#ifdef DG_PLATFORM_WINDOWS
	#ifdef DG_BUILD_DLL
		#define DG_API __declspec(dllexport)
	#else 
		#define DG_API __declspec(dllimport)
	#endif
#else
	#error  DUCKGAME ES SOLO PA WINDOWS TONTOLIN >:3
#endif