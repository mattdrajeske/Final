#include "ofApp.h"
#include vector

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

	void subdivide();
	void insert();
	void query();
	vector<ofPoint> points;

private:
	ofRectangle boundary;
	float capacity;	
	bool divided;

};


#endif /* Qtree_h */
