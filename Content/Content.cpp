#include "Content.h"
#include "ofMain.h"

extern "C" CONTENT_UPDATE_AND_RENDER(ContentUpdateAndRender)
{
	int a, b;
	a = 2;
	b = 3;
	a *= b;

	ofDrawBox(100.);

	return;
}
