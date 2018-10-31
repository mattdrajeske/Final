#include <stdio.h>
#include "Photon.h"
#define PHOTON_LENGTH 100
#define SLOWDOWN 1.0
#define z_upper 90
#define z_lower 5

Photon::Photon() {
	//fields
	x = ofGetWindowWidth() + 50; //random starting location
					   //    x  = ofRandom(ofGetWidth()); //random starting location
	y = ofRandom(ofGetWindowHeight() - 30, 30); //random y location and start off screen
	z =      ofRandom(z_lower, z_upper); ///pseudo parallax
	a = ofMap(z, z_lower, z_upper, 50, 100);
	xspeed = ofMap(z, z_lower, z_upper, 1, 2);
	//len =    ofMap(z, z_lower, z_upper, 10, PHOTON_LENGTH); //different rain drop length
	height = ofMap(z, z_lower, z_upper, 3, 15);
}

void Photon::fall() {

	float grav = ofMap(z, z_lower, z_upper, 0, 0.5); //to make the movement more natural
	xspeed = (grav + xspeed)*SLOWDOWN;
	x -= xspeed;
	//len += xspeed/len;

	if (x <= -200) {
		x = ofGetWindowWidth() + 50;
		y = ofRandom(ofGetWindowHeight() - 30, 30);
		z =      ofRandom(z_lower, z_upper);
		//len =    ofMap(z, z_lower, z_upper, 10, PHOTON_LENGTH);
		xspeed = ofMap(z, z_lower, z_upper, 1, 2);
		height = ofMap(z, z_lower, z_upper, 3, 15);
	}
	//show();
}

void Photon::show() {
	/*ofPoint p;
	p.x = x;
	p.y = y;*/
	
	ofSetLineWidth(5);
	ofRectangle rect(x, y, height, height);
	ofDrawRectangle(rect);
}

void Photon::run()
{
	show();
	fall();
}

void Photon::pColor(int i) {
	
	if(i % 4 == 0) {
		r = 255;
		g = 200;
		b = 21;
	}else if(i % 3 == 0){
		r = 51;
		g = 153;
		b = 255;
	}else if(i % 2 == 0) {
		r = 245;
		g = 68;
		b = 37;
	}
	else {
		r = 149;
		g = 186;
		b = 90;
	}
	
	/*r = ofRandom(255);
	g = ofRandom(255);
	b = ofRandom(255);*/
	
	ofSetColor(r, g, b, a);
}