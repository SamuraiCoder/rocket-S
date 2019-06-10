#ifndef FILE_UTILS
#define FILE_UTILS
/*
* FileUtils.h 
* May 2017.
* Class to make it easier to access to resources, files or paths.
*/

#include <iostream>
#include <string>
#include <SDL.h>

namespace FileUtils {
	/*
	* GetResourcePath
	* Get the resource path for resources located in res/subDir
	*/
	std::string GetResourcePath(const std::string &subDir = "");

	/*
	Get a substring after the ":" when reading a file
	*/
	std::string GetSubstrFiles(std::string myData);
}


#endif