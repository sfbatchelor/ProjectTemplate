#include "ofApp.h"
#include "Windows.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

	//if(Content::respond())
	//	ofLog(OF_LOG_NOTICE, string("Nice"));
	//else 
	//	ofLog(OF_LOG_WARNING, string("BAD"));

	m_content = loadContentCode();
	m_content.m_updateAndRender();
	unloadContentCode(&m_content);

}

//--------------------------------------------------------------
void ofApp::draw(){

}

WindowsContentCode ofApp::loadContentCode(void)
{
	WindowsContentCode result = {};
	result.m_dll = LoadLibraryA("Content.dll");
	if (result.m_dll)
	{
		result.m_updateAndRender = (Content_Update_And_Render*)
			GetProcAddress(result.m_dll, "ContentUpdateAndRender");
		result.m_isValid = (result.m_updateAndRender);
	}
	if (!result.m_isValid)
	{
		result.m_updateAndRender = ContentUpdateAndRenderStub;
	}

	return result;
}

void ofApp::unloadContentCode(WindowsContentCode *contentCode)
{
	if (contentCode->m_dll)
		FreeLibrary(contentCode->m_dll);
	contentCode->m_isValid = false;
	contentCode->m_updateAndRender = ContentUpdateAndRenderStub;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
