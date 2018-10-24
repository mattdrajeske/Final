#include "ofApp.h"

#ifndef Electron_h
#define Electron_h

class Electron {

public:
	Electron();

	void move();
	void show();
	void run();
	void update();
	void eColor();

private:
	float x; //x location
	float y; //y location that changes based on mouse position
	float radius; //radius of electron
	//float yspeed;
	int r;
	int g;
	int b;

};

#endif /* Electron _h */
