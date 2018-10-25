#include <stdio.h>
#include "Photon.h"
#define PHOTON_LENGTH 100

Photon::Photon() {
	//fields
	x = ofGetWindowWidth() + 50; //random starting location
					   //    x  = ofRandom(ofGetWidth()); //random starting location
	y = ofRandom(ofGetWindowHeight() - 30, 30); //random y location and start off screen
	z = ofRandom(0, 20); ///pseudo parallax
	len = ofMap(z, PHOTON_LENGTH, 0, PHOTON_LENGTH, 10); //different rain drop length
	xspeed = ofMap(z, PHOTON_LENGTH, 0, PHOTON_LENGTH, 1);
}

void Photon::fall() {
	float grav = ofMap(z, 0, 20, 0, 0.2); //to make the movement more natural
	xspeed = (grav + xspeed)*0.9;// *0.75;
	x -= xspeed;
	
	

	//so the drops reset to the top
	//    if (y > ofGetHeight()) {
	//        y = ofRandom(-200, -100);
	//        xspeed = ofMap(z, 0, 20, 4, 10);
	//    }

	if (x < 200) {
		x = ofGetWindowWidth() + 50;
		y = ofRandom(ofGetWindowHeight() - 30, 30);
		z = ofRandom(10, 20);
		ofMap(z, 100, 0, 100, 10);
		xspeed = ofMap(z, 20, 0, 10, 4);
	}
}

void Photon::show() {
	float thick = ofMap(z, 0, 20, 3, 1);
	ofSetLineWidth(thick);
	//ofSetColor(138, 43, 226);
	ofDrawLine(x, y, x - len, y);
}

void Photon::run()
{
	fall();
	show();
}

void Photon::pColor(int i) {
	
	switch (i) {
	case 0:
		r = 255;
		g = 0;
		b = 0;
		break;
	case 1:
		r = 0;
		g = 255;
		b = 0;
		break;
	case 2:
		r = 0;
		g = 0;
		b = 255;
		break;
	case 3:
		r = 255;
		g = 244;
		b = 79;
		break;
	}
	ofSetColor(r, g, b);
}