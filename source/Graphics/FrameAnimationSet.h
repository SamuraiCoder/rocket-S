#ifndef FRAME_ANIMATION_SET
#define FRAME_ANIMATION_SET

#include "FrameAnimation.h"

using std::ifstream;
using std::string;
using std::stringstream;

namespace Graphics {
	class FrameAnimationSet{
	public:
		//Default constructor passing a name for the animationFrameSet
		FrameAnimationSet(const string &animName);

		//Cleanup memory due to spritesheets/imgs loaded.
		~FrameAnimationSet(); 

		//Get an animation given an FrameAnimation name
		FrameAnimation* getFrameAnimationSet(const string &animationFrameSetName);

		//This will load the file *.fas (Frame Animation Set) that will contain all the definitions for all the animations.
		void loadAnimationSet(const string &fileName, bool setColourKey = false, int transparentPixelIndex = 0);

		//will return the spritesheet where all the animations are
		SDL_Texture* getSpriteSheet(){ return spriteSheet; }

		bool isLoaded;

	private: 
		//Spritesheet's name
		string spriteSheetName;
		//Keeps the spritesheet into memory
		SDL_Texture* spriteSheet;
		//List of all the FrameAnimations
		list<FrameAnimation> frameAnimationSet;
		
	};
}
#endif