#include "ofApp.h"
#include <vector>

#ifndef Qtree_h
#define Qtree_h

//class qPoint {
//public:
//	qPoint(int x, int y, float userData);
//
//private:
//
//
//};

//class Rectangle {
//public:
//	// Parameterized Constructor
//	Rectangle();
//
//	void contains(float);
//	void intersects(int);
//
//private:
//	int x;
//	int y;
//	int w;
//	int h;
//
//};
//

class QuadTree {
public:
	QuadTree(ofRectangle, float);
	QuadTree();
	//QuadTree(QuadTree *);
	void subdivide();
	void insert(ofPoint);
	void query();
	void changeBoundary(ofRectangle);
	bool contains(ofPoint);
	QuadTree * northeast; //sections of quadtree
	QuadTree * northwest;
	QuadTree * southeast;
	QuadTree * southwest;
	

private:
	vector<ofPoint> points;
	ofRectangle boundary;
	float capacity;	
	bool divided = false;

};


#endif /* Qtree_h */
