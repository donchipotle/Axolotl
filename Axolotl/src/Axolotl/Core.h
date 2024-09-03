#pragma once

#ifdef AX_PLATFORM_WINDOWS
	#ifdef AX_BUILD_DLL
		#define AXOLOTL_API __declspec(dllexport)
	#else
		#define AXOLOTL_API __declspec(dllimport)
	#endif // DEBUG
//#else
//#error Axolotls don't like anything that isn't windows!
#endif





