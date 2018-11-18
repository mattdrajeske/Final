#include "ofApp.h"
#include "photon.h"
#include "Qtree.h"
#include <vector>
#define NUM_PHOTONS 200

//vector<ofPoint> points;
ofRectangle boundary(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2); //boundary for quad tree that handles collision detection
QuadTree qt(boundary, 4); //quad tree, 4 is the capacity that causes it to divide

//--------------------------------------------------------------
void ofApp::setup() {
	//ofBackground(230, 230, 250);
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();

	
	ofPoint photonPosition; //point that each of the photons are at
	
	for (int i = 0; i < NUM_PHOTONS; i++) {
		Photon *p = new Photon();
		photonPosition.x = p->GetX();//sets x for each point handled by the quad tree
		photonPosition.y = p->GetY();//sets y for each point handled by the quad tree
		photons.push_back(p);
		qt.insert(photonPosition);//adds points to a vector that is a member data of the quad tree class		
	}
	
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
		//qt.points[i].x = photons[i]->GetX();//updates the points in the points vector of quad tree class
		//qt.points[i].y = photons[i]->GetY();
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