#pragma once
#include "ofMain.h"
#include "Content.h"

struct WindowsContentCode
{
	HMODULE m_dll;
	Content_Update_And_Render *m_updateAndRender;
	bool m_isValid;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		WindowsContentCode loadContentCode(void );
		void unloadContentCode(WindowsContentCode *contentCode);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

private:

	WindowsContentCode m_content;
		
};
