#include <stdio.h>
#include "Electron.h"

Electron::Electron() {
	//fields
	x = 200;				 
	y = ofGetMouseY();
	radius = 15; //different rain drop length

	//yspeed = ofMap(z, 0, 20, 1, 20);
}

void Electron::move() {
	y = ofGetMouseY();
	//float grav = ofMap(z, 0, 20, 0, 0.2); //to make the movement more natural
	//yspeed = yspeed + grav;

	//so the drops reset to the top
	//    if (y > ofGetHeight()) {
	//        y = ofRandom(-200, -100);
	//        yspeed = ofMap(z, 0, 20, 4, 10);
	//    }
	
	//Keeps the electron on the screen
	if (y >= (ofGetWindowHeight() - radius) ) {
		y -= 1;
	}
	else  if (y <= ofGetWindowHeight() + radius) {
		y += 1;
	}
}

void Electron::show() {
	/*float thick = ofMap(z, 0, 20, 1, 3);
	ofSetLineWidth(thick);
	ofSetColor(138, 43, 226);
	ofDrawLine(x, y, x, y + len);*/

	ofDrawCircle(x, y, radius);
	//ofSetColor(255, 255, 255);
}

void Electron::run()
{
	move();
	show();
}

void Electron::eColor() {
	r = 255; 
	g = 255;
	b = 255;
	ofSetColor(r, g, b);
}