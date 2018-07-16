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
