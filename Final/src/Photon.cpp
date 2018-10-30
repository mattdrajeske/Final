#include <stdio.h>
#include "Photon.h"
#define PHOTON_LENGTH 100

Photon::Photon() {
	//fields
	x = ofGetWindowWidth() + 50; //random starting location
					   //    x  = ofRandom(ofGetWidth()); //random starting location
	y = ofRandom(ofGetWindowHeight() - 30, 30); //random y location and start off screen
	z = ofRandom(2, 30); ///pseudo parallax
	xspeed = ofMap(z, PHOTON_LENGTH, 0, PHOTON_LENGTH, 1);
	len = ofMap(xspeed, PHOTON_LENGTH, 0, PHOTON_LENGTH, 10); //different rain drop length
}

void Photon::fall() {

	float grav = ofMap(z, 0, 20, 0, 0.2); //to make the movement more natural
	xspeed = (grav + xspeed)/1;
	x -= xspeed;
	len += xspeed/len;

	if (x <= -200) {
		x = ofGetWindowWidth() + 50;
		y = ofRandom(ofGetWindowHeight() - 30, 30);
		z = ofRandom(2, 30);
		len = ofMap(z, PHOTON_LENGTH, 0, PHOTON_LENGTH, 10);
		xspeed = ofMap(z, PHOTON_LENGTH, 0, PHOTON_LENGTH, 1);
	}
	show();
}

void Photon::show() {
	float thick = ofMap(z, 0, 10, 3, 1);
	ofSetLineWidth(thick);
	ofDrawLine(x, y, x - len, y);
}

void Photon::run()
{
	fall();
}

void Photon::pColor(int i) {
	
	if(i % 4 == 0) {
		r = 255;
		g = 0;
		b = 0;
	}else if(i % 3 == 0){
		r = 0;
		g = 255;
		b = 0;
	}else if(i % 2 == 0) {
		r = 0;
		g = 0;
		b = 255;	
	}
	else {
		r = 255;
		g = 0;
		b = 255;
	}
	
	/*r = ofRandom(255);
	g = ofRandom(255);
	b = ofRandom(255);*/

	ofSetColor(r, g, b);
}