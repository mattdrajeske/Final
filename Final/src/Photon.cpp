#include <stdio.h>
#include "Photon.h"
#define PHOTON_LENGTH 100
#define SLOWDOWN 0.75
#define z_upper 90
#define z_lower 5

Photon::Photon() {
	//fields
	x = ofGetWindowWidth() + 50; //random starting location
					   //    x  = ofRandom(ofGetWidth()); //random starting location
	y = ofRandom(ofGetWindowHeight() - 30, 30); //random y location and start off screen
	z =      ofRandom(z_lower, z_upper); ///pseudo parallax
	a = ofMap(z, 2, 30, 50, 100);
	xspeed = ofMap(z, z_lower, z_upper, 1, 2);
	len =    ofMap(z, z_lower, z_upper, 10, PHOTON_LENGTH); //different rain drop length
	height = ofMap(z, z_lower, z_upper, 0.1, 5);
}

void Photon::fall() {

	float grav = ofMap(z, z_lower, z_upper, 0, 0.5); //to make the movement more natural
	xspeed = (grav + xspeed)*SLOWDOWN;
	x -= xspeed;
	len += xspeed/len;

	if (x <= -200) {
		x = ofGetWindowWidth() + 50;
		y = ofRandom(ofGetWindowHeight() - 30, 30);
		z =      ofRandom(z_lower, z_upper);
		len =    ofMap(z, z_lower, z_upper, 10, PHOTON_LENGTH);
		xspeed = ofMap(z, z_lower, z_upper, 1, 2);
		height = ofMap(z, z_lower, z_upper, 3, 5);
	}
	//show();
}

void Photon::show() {
	/*ofPoint p;
	p.x = x;
	p.y = y;*/
	
	ofSetLineWidth(5);
	ofRectangle rect(x, y, len, height);
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
		g = 0;
		b = 0;
	}else if(i % 3 == 0){
		r = 0;
		g = 255;
		b = 0;
	}else if(i % 2 == 0) {
		r = 50;
		g = 100;
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
	
	ofSetColor(r, g, b, a);
}