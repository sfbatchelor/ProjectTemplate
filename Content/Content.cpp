#include "Content.h"

extern "C" CONTENT_UPDATE_AND_RENDER(ContentUpdateAndRender)
{
	int a, b;
	a = 2;
	b = 3;
	a *= b;

	return;
}
