#include "Content.h"

static std::shared_ptr<ofAppBaseWindow> m_mainWindow;
static std::shared_ptr<ofBaseRenderer> m_renderer;

std::deque< glm::vec2> mouse;


extern "C" CONTENT_SETUP(ContentSetup)
{
	m_mainWindow = window;
	m_renderer = m_mainWindow->renderer();
	m_mainWindow->setWindowTitle("Graphics Window");
	m_mainWindow->hideCursor();
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

	m_renderer->setBackgroundColor(300);

	float gc = sin(glm::length(ofGetElapsedTimef() * 4));
	m_renderer->setColor(255, gc * 130, 0);
	float radius = 50 + 10 * sin(100);
	m_renderer->setFillMode(OF_FILLED);

	m_renderer->drawCircle(400 + cos(ofGetElapsedTimef()) * 110, 600 + (cos(ofGetElapsedTimef()*.9)) * 80, 0, radius);

	gc = sin(glm::fract(ofGetElapsedTimef() * 5));
	m_renderer->setColor(155, 100, gc * 230);
	glm::vec3 bPos = glm::vec3(900 +  sin(ofGetElapsedTimef()) * 200, 400+ glm::length(cos(ofGetElapsedTimef()*.3)) *580., 0.);
	m_renderer->drawBox(bPos, 50 + 200 * glm::length(sin(ofGetElapsedTimef())));

	for (int i = 0; i < mouse.size(); i++)
	{
		m_renderer->setColor(0, i, 0);
		m_renderer->drawCircle(mouse[i].x, mouse[i].y, 0, 30);
	}

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
	mouse.push_back(glm::vec2(x,y));
	if (mouse.size() > 255)
		mouse.pop_front();
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