#ifndef FRAME
#define FRAME

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "SDL.h"

/*
* Frame
* Feb 2019.
* This class represent a minimum unit for an animation
*/

using std::list;
using std::ifstream;
using std::string;
using std::stringstream;

namespace Graphics{
	class Frame{
	public:
		/*
		 Draws a spritesheet in the given position
		*/
		void Draw(SDL_Texture* spriteSheet, float destX, float destY, float scale, bool flip);
		
		/*
		 Loads a frame into memory. A Frame is represented with the following structure:
		 *		index : 0
		 *		duration : 0.1
		 *		anchor : 19 47
		 *		clip : 10 10 10 10 (x, y, width, height) 
		*/
		void loadFrame(ifstream &file);
		
		/*
		* Getters
		*/
		int GetFrameIndex(){ return frameIndex; }
		float GetFrameDuration(){ return frameDuration; }

	private:
		//Identifier inside a frameAnimation. Own id.
		int frameIndex;
		//Region on the spritesheet where this frame is located.
		SDL_Rect frameClip;
		//How long does this frame appears
		float frameDuration;
		//Pivot point to help align frames in an animation (offset)
		SDL_Point frameAnchor;
	};
}

#endif