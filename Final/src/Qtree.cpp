#include <stdio.h>
#include <vector>
#include "Qtree.h"



QuadTree::QuadTree(ofRectangle bound, float cap) {
	bound = boundary;
	cap = capacity;
}

QuadTree::QuadTree() {
	boundary = ofRectangle(0, 0, 0, 0);
	capacity = 0;
}

QuadTree::QuadTree(QuadTree * qt) {
	boundary = qt->boundary;
	capacity = qt->capacity;
}

QuadTree * northeast;
QuadTree * northwest;
QuadTree * southeast;
QuadTree * southwest;

void QuadTree::subdivide() {
	float x = boundary.x; 
	float y = boundary.y;
	
	ofRectangle ne(x + boundary.width / 2, y - boundary.height / 2, boundary.width/2, boundary.height/2); //make quadrants of the quad tree
	northeast = new QuadTree(ne, 4);
	QuadTree qtne(northeast);

	ofRectangle nw(x - boundary.width / 2, y - boundary.height / 2, boundary.width / 2, boundary.height / 2);
	northwest= new QuadTree(nw, 4);
	QuadTree qtne(northwest);

	ofRectangle se(x + boundary.width / 2, y + boundary.height / 2, boundary.width / 2, boundary.height / 2);
	southeast = new QuadTree(se, 4);
	QuadTree qtse(southeast);

	ofRectangle sw(x - boundary.width / 2, y + boundary.height / 2, boundary.width / 2, boundary.height / 2);
	southwest = new QuadTree(sw, 4);
	QuadTree qtsw(southwest);

}


void QuadTree::insert(ofPoint point) {

	if (points.size() < capacity) { //if the quadrant is over capacity, subdivide it
		points.push_back(point);
	}
	else {
		if (!divided) { //flag to tell if quadtree has been divided
			subdivide();
			divided = true;
		}

	}
}

void QuadTree::query(range, found) {
	if (!found) {
		found = [];
	}

	if (!range.intersects(boundary)) {
		return found;
	}

	for (let p of points) {
		if (range.contains(p)) {
			found.push(p);
		}
	}
	if (divided) {
		northwest.query(range, found);
		northeast.query(range, found);
		southwest.query(range, found);
		southeast.query(range, found);
	}

	return found;
}