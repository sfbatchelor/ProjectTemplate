#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(1560, 2130);
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
	
}