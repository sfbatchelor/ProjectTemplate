#include "ofApp.h"
#include "Windows.h"

//--------------------------------------------------------------
void ofApp::setup(){

	m_content = loadContentCode();
	m_dllWatcher.lock();
	m_dllWatcher.setFile(boost::filesystem::path("..\\Content.dll"), 100);
	m_dllWatcher.registerCallback(std::function<void()>([this]() {onDllWasModified(); }));
	m_dllWatcher.unlock();
	m_dllWatcher.startThread();

}

//--------------------------------------------------------------
void ofApp::update(){
	m_content.m_updateAndRender();
}

//--------------------------------------------------------------
void ofApp::draw(){

}

WindowsContentCode ofApp::loadContentCode(void)
{
	WindowsContentCode result = {};

	CopyFile(L"Content.dll", L"Content_temp.dll", FALSE);
	result.m_dll = LoadLibraryA("Content_temp.dll");
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

void ofApp::onDllWasModified()
{
	m_dllWatcher.lock();
	unloadContentCode(&m_content);
	m_content = loadContentCode();
	m_dllWatcher.unlock();
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
