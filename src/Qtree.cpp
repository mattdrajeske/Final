//
//  Qtree.cpp
//  final
//
//  Created by Matt on 12/6/18.
//
//
#include <vector>
#include "Qtree.hpp"
#include "ofApp.hpp
#include <stdio.h>

using namespace std;

//#include <vector>
//#include "Qtree.hpp"



QuadTree::QuadTree(ofRectangle bound, float cap) {
	bound = boundary;
	cap = capacity;
}

QuadTree::QuadTree() {
	boundary = ofRectangle(0, 0, 0, 0);
	capacity = 2;
}

bool QuadTree::contains(ofPoint point) {
	return(point.x > boundary.x - boundary.width &&
		point.x < boundary.x + boundary.width &&
		point.y > boundary.y - boundary.height &&
		point.y < boundary.y + boundary.height);
}


void QuadTree::changeBoundary(ofRectangle newBound) {
	boundary.width = newBound.width; //changes boundary of quad tree
	boundary.height = newBound.height;
	boundary.x = newBound.x;
	boundary.y = newBound.y;
}

void QuadTree::subdivide() {
	float x = boundary.x; 
	float y = boundary.y;
	
	ofRectangle ne(x + boundary.width / 2, y - boundary.height / 2, boundary.width/2, boundary.height/2); //make quadrants of the quad tree	
	northeast->changeBoundary(ne);

	ofRectangle nw(x - boundary.width / 2, y - boundary.height / 2, boundary.width / 2, boundary.height / 2);	
	northwest->changeBoundary(nw);

	ofRectangle se(x + boundary.width / 2, y + boundary.height / 2, boundary.width / 2, boundary.height / 2);
	southeast->changeBoundary(se);

	ofRectangle sw(x - boundary.width / 2, y + boundary.height / 2, boundary.width / 2, boundary.height / 2);
	southwest->changeBoundary(sw);
	divided = true;
}


void QuadTree::insert(ofPoint point) {
	if (!contains(point)) {
		return;
	}

	if (points.size() < capacity) { //if the quadrant is over capacity, subdivide it
		points.push_back(point);
	}
	else {
		if (!divided) { //flag to tell if quadtree has been divided
			subdivide();
		}
		northeast->insert(point);
		northwest->insert(point);
		southeast->insert(point);
		southeast->insert(point);
	}
}


//vector<int> QuadTree:: query(ofRectangle range, vector<int> found){
//    if(found.length() = 0){
//        return found;
//    }
//    
//    if(range.intersects(boundary)){
//        return found;
//    }
//    
//    if(divided){
//        for(int i = 0; i < particles; i++){
//            northwest.query(range, found);
//            northeast.query(range, found);
//            southwest.query(range, found);
//            southeast.query(range, found);
//        }
//    }
//    
//    return found;
//}