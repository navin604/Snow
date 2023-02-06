#pragma once

#ifdef SNOW_PLATFORM_WINDOWS
	#ifdef SNOW_BUILD_DLL
		#define SNOW_API __declspec(dllexport)
	#else 
		#define SNOW_API __declspec(dllimport)
	#endif
	#else
	#error Windows support only!
#endif
