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
	void pColor(int);

private:
	float x; //random starting location
	float y; //random y location and start off screen
	float z; ///pseudo parallax
	float len; //different rain drop length
	float xspeed;
	float height;
	int r;
	int g;
	int b;
	int a;

};

#endif /* Photon_h */