#include "FrameAnimationSet.h"

namespace Graphics {
	FrameAnimationSet::FrameAnimationSet(const string &animName)
	{
		spriteSheetName = animName;
	}

	FrameAnimationSet::~FrameAnimationSet()
	{
		//todo: implement!
	}

	FrameAnimation* FrameAnimationSet::getFrameAnimationSet(const string &animationFrameSetName)
	{
		//todo: redo thinking on modern lambdas!
		for (list<FrameAnimation>::iterator it = frameAnimationSet.begin(); it != frameAnimationSet.end(); ++it)
		{
			FrameAnimation* frameAnimation = &(*it);

			if (frameAnimation->GetFrameAnimationName() == animationFrameSetName)
			{
				return frameAnimation;
			}
		}

		return nullptr;
	}

	void FrameAnimationSet::loadAnimationSet(const string &fileName, bool setColourKey, int transparentPixelIndex)
	{
		ifstream file;
		string resPath = FileUtils::GetResourcePath();
		file.open(resPath + fileName);
		if (file.good())
		{
			getline(file, spriteSheetName);
			if (setColourKey)
			{
				SDL_Surface *spriteSurface = GM->loadSurface(resPath + fileName);

				//for transparency, we will grab the [transparentPixelIndex] from the surface we just made
				SDL_Color* transparentPixel = &spriteSurface->format->palette->colors[transparentPixelIndex];
				SDL_SetColorKey(spriteSurface, 1, SDL_MapRGB(spriteSurface->format, transparentPixel->r, transparentPixel->g, transparentPixel->b));

				spriteSheet = GM->convertSurfaceToTexture(spriteSurface, false);

				GM->cleanup(spriteSurface);
			}
			else
				spriteSheet = GM->loadTexture(resPath + fileName);

			string buffer;
			getline(file, buffer);
			stringstream ss;
			buffer = FileUtils::GetSubstrFiles(buffer);
			ss << buffer;
			int numberOfAnimations;
			ss >> numberOfAnimations;

			for (int i = 0; i < numberOfAnimations; i++)
			{
				FrameAnimation newAnimation = FrameAnimation(fileName);
				newAnimation.loadAnimation(file);
				frameAnimationSet.push_back(newAnimation);
			}

		}
		file.close();
	}

}