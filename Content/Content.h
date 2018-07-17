#pragma once

#ifdef CONTENT_EXPORTS  
#define CONTENT_API __declspec(dllexport)   
#else  
#define CONTENT_API __declspec(dllimport)   
#endif  

namespace Content
{
	CONTENT_API bool respond();
}


// define update and render function prototype and stub to be used by app layer.
#define CONTENT_UPDATE_AND_RENDER(name) void name(void)
typedef CONTENT_UPDATE_AND_RENDER(Content_Update_And_Render);
inline CONTENT_UPDATE_AND_RENDER(ContentUpdateAndRenderStub)
{

}

extern "C" CONTENT_API CONTENT_UPDATE_AND_RENDER(ContentUpdateAndRender);
