#include <stdio.h>
#include <vector>
#include "Qtree.h"



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

//void QuadTree::query(range, found) {
//	if (!found) {
//		found = [];
//	}
//
//	if (!range.intersects(boundary)) {
//		return found;
//	}
//
//	for (let p of points) {
//		if (range.contains(p)) {
//			found.push(p);
//		}
//	}
//	if (divided) {
//		northwest.query(range, found);
//		northeast.query(range, found);
//		southwest.query(range, found);
//		southeast.query(range, found);
//	}
//
//	return found;
//}