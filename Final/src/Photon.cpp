#include <stdio.h>
#include "Photon.h"

Photon::Photon() {
	//fields
	x = ofRandom(800); //random starting location
					   //    x  = ofRandom(ofGetWidth()); //random starting location
	y = ofRandom(-500, -50); //random y location and start off screen
	z = ofRandom(0, 20); ///pseudo parallax
	len = ofMap(z, 0, 20, 10, 20); //different rain drop length
	yspeed = ofMap(z, 0, 20, 1, 20);
}

void Photon::fall() {
	y = y + yspeed;
	float grav = ofMap(z, 0, 20, 0, 0.2); //to make the movement more natural
	yspeed = yspeed + grav;

	//so the drops reset to the top
	//    if (y > ofGetHeight()) {
	//        y = ofRandom(-200, -100);
	//        yspeed = ofMap(z, 0, 20, 4, 10);
	//    }
	if (y > 600) {
		y = ofRandom(-200, -100);
		yspeed = ofMap(z, 0, 20, 4, 10);
	}
}

void Photon::show() {
	float thick = ofMap(z, 0, 20, 1, 3);
	ofSetLineWidth(thick);
	ofSetColor(138, 43, 226);
	ofDrawLine(x, y, x, y + len);
}

void Photon::run()
{
	fall();
	show();
}

void Photon::pColor() {
	r = 138;
	g = 43;
	b = 226;
	ofSetColor(r, g, b);
}