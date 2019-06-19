#include "FileUtils.h"

namespace FileUtils {
	std::string GetResourcePath(const std::string &subDir)
	{
#ifdef _WIN32
		char const *PATH_SEP = "\\";
#else
		char const *PATH_SEP = '/';
#endif
		static std::string baseRes;
		//In some platforms, this might return NULL
		char *basePath = SDL_GetBasePath();
		
		if (basePath == nullptr)
		{
			std::cerr << "[FileUtils] Error getting resource path: " << SDL_GetError() << std::endl;
			return NULL;
		}

		baseRes = basePath;
		SDL_free(basePath);
#ifdef _DEBUG
		//This basically will point to ..\\..\\data from the project instead of the DEBUG folder.
		baseRes.append("..");
		baseRes.append(PATH_SEP);
		baseRes.append("..");
		baseRes.append(PATH_SEP);
		baseRes.append("data");
		baseRes.append(PATH_SEP);
#else
		baseRes.append(PATH_SEP);
#endif		
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
