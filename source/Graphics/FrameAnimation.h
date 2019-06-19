#ifndef FRAME_ANIMATION
#define FRAME_ANIMATION

#include "Frame.h"
#include <iostream>
#include <algorithm>
#include <iterator>

namespace Graphics {
	class FrameAnimation{
	public:
		//Default constructor passing a name for the animationFrame
		FrameAnimation(const string &name);

		//Returns the next frame if exists otherwise goes to the beginning. 
		Frame *getNextFrame(Frame* frame);

		//Returns current frame given a frameNumber
		Frame* getFrame(int frameIndex); 

		//Returns animation frame
		string GetFrameAnimationName() { return frameAnimationName; }

		/*
		Loads a list of frames (animations) into memory. A list of frames is represented with the following structure:
			up
			frames: 4
			...
			down
			frames: 4
			...
		*/
		void loadAnimation(ifstream &file);
		
	private:
		//Animation's name e.g "up", "down" ...
		string frameAnimationName;
		//Contains a list of frames 
		list<Frame> animationFrames;
	};
}
#endif