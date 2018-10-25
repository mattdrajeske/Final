#include "ofApp.h"
#include "photon.h"
#include <vector>
#define NUM_PHOTONS 200

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(230, 230, 250);
	
	for (int i = 0; i < NUM_PHOTONS; i++) {
		Photon *p = new Photon();
		photons.push_back(p);
	}

	ofBackground(0, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < photons.size(); i++) {
		photons[i]->Photon::pColor();
		photons[i]->Photon::run();
	}

	elec.eColor();
	elec.Electron::run();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {


}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}