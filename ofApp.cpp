#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetColor(255, 255, 0);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotate(90);

	float radius = 300;
	ofVec2f location_1, location_2;
	float y_span = 5;
	float noise_value = 0;

	for (float deg = 0; deg < 180; deg += 5) {
		location_1 = ofVec2f(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		location_2 = ofVec2f(radius * cos(-deg * DEG_TO_RAD), radius * sin(-deg * DEG_TO_RAD));

		for (float y = location_2.y; y < location_1.y; y += y_span) {
			ofLine(ofVec3f(location_1.x + ofMap(ofNoise(ofGetFrameNum() * 0.05 + y * 0.05), 0, 1, -25, 25), y, 0), ofVec3f(location_1.x + ofMap(ofNoise(ofGetFrameNum() * 0.05 + (y + y_span) * 0.05), 0, 1, -25, 25), y + y_span, 0));
		}
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}