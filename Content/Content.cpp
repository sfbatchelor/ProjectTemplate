#include "Content.h"
extern "C" CONTENT_SETUP(ContentSetup)
{
	return;
}

extern "C" CONTENT_UPDATE(ContentUpdate)
{
	return;
}

extern "C" CONTENT_RENDER(ContentRender)
{
	int a, b;
	a = 2;
	b = 3;
	a *= b;

	renderer->setBackgroundColor(300);
	renderer->setColor(255, 0, 0);
	renderer->setFillMode(OF_FILLED);
	renderer->drawBox(glm::vec3(0, -100, 0), 100);
	renderer->setColor(1);

	float gc = sin(glm::fract(ofGetElapsedTimef() * 3));
	renderer->setColor(255, gc * 130, 0);
	float radius = 50 + 10 * sin(100);
	renderer->setFillMode(OF_FILLED);
	renderer->drawCircle(200, 400, 0, radius);
	return;

}

extern "C" CONTENT_EXIT(ContentExit)
{
	return;
}
extern "C" CONTENT_KEY_PRESSED(ContentKeyPressed)
{
	return;
}
extern "C" CONTENT_KEY_RELEASED(ContentKeyReleased)
{
	return;
}
extern "C" CONTENT_MOUSE_MOVED(ContentMouseMoved)
{
	return;
}
extern "C" CONTENT_MOUSE_DRAGGED(ContentMouseDragged)
{
	return;
}
extern "C" CONTENT_MOUSE_PRESSED(ContentMousePressed)
{
	return;
}
extern "C" CONTENT_MOUSE_RELEASED(ContentMouseReleased)
{
	return;
}
extern "C" CONTENT_MOUSE_ENTERED(ContentMouseEntered)
{
	return;
}
extern "C" CONTENT_MOUSE_EXITED(ContentMouseExited)
{
	return;
}
extern "C" CONTENT_WINDOW_RESIZED(ContentWindowResized)
{
	return;
}
extern "C" CONTENT_DRAG_EVENT(ContentDragEvent)
{
	return;
}
extern "C" CONTENT_GOT_MESSAGE(ContentGotMessage)
{
	return;
}