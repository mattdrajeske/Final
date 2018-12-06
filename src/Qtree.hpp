//
//  Qtree.hpp
//  final
//
//  Created by Matt on 12/6/18.
//
//
#pragma once
#ifndef Qtree_hpp
#define Qtree_hpp

#include <stdio.h>
#include "ofApp.h"
#include <vector>


class QuadTree {
public:
	QuadTree(ofRectangle, float);
	QuadTree();
	//QuadTree(QuadTree *);
	void subdivide();
	void insert(ofPoint);
	void query();
	void changeBoundary(ofRectangle);
	bool contains(ofP/Users/matt/Documents/ofCrap/apps/myApps/finaloint);
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



#endif /* Qtree_hpp */
