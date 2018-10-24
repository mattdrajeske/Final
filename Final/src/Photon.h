#include "ofApp.h"

#ifndef Photon_h
#define Photon_h

class Photon {

public:
	Photon();

	void fall();
	void show();
	void run();
	void update();
	void pColor();

private:
	float x; //random starting location
	float y; //random y location and start off screen
	float z; ///pseudo parallax
	float len; //different rain drop length
	float yspeed;
	int r;
	int g;
	int b;

};

#endif /* Photon_h */