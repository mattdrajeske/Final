#include "ofApp.h"
#include "photon.h"
#include <vector>
#define NUM_PHOTONS 200

//--------------------------------------------------------------
void ofApp::setup() {
	//ofBackground(230, 230, 250);
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();
	
	for (int i = 0; i < NUM_PHOTONS; i++) {
		Photon *p = new Photon();
		photons.push_back(p);

	}
	
	//ofSetBackgroundAuto(false);
	ofBackground(0, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update() {
	//for (int i = 0; i < NUM_PHOTONS; i++) {
		
	//}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(0, 0, 0, 20);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	for (int i = 0; i < NUM_PHOTONS; i++) {
		photons[i]->Photon::pColor(i+1);
		photons[i]->Photon::run();
		photons[i]->Photon::PhotonDraw();
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