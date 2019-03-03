#include "FileUtils.h"

namespace FileUtils {
	std::string GetResourcePath(const std::string &subDir){
		//We need to choose the path separator properly based on which
		//platform we're running on, since Windows uses a different
		//separator than most systems
#ifdef _WIN32
		const char PATH_SEP = '\\';
#else
		const char PATH_SEP = '/';
#endif
		//This will hold the base resource path: 
		//We give it static lifetime so that we'll only need to call
		//SDL_GetBasePath once to get the executable path
		static std::string baseRes;
		if (baseRes.empty()){
			//SDL_GetBasePath will return NULL if something went wrong in retrieving the path
			char *basePath = SDL_GetBasePath();
			if (basePath){
				baseRes = basePath;
				SDL_free(basePath);
			}
			else {
				std::cerr << "[FileUtils] Error getting resource path: " << SDL_GetError() << std::endl;
				return "";
			}
			//We replace the last bin/ with data/ to get the the resource path
			size_t pos = baseRes.rfind("bin");
			baseRes = baseRes.substr(0, pos) + "data" + PATH_SEP;
		}
		//If we want a specific subdirectory path in the resource directory
		//append it to the base path. This would be something like Lessons/res/Lesson0
		return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
	}

	std::string GetSubstrFiles(std::string myData)
	{
		int pos = myData.find(":", 0);
		if (pos != -1){
			myData = myData.substr(pos + 1, myData.length() - pos + 2);
		}
		return myData;
	}

}
