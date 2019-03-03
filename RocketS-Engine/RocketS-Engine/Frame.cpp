#include "Frame.h"

namespace Graphics{

	void Frame::Draw(SDL_Texture* spriteSheet, float destX, float destY)
	{
		SDL_Rect posToDraw;
		posToDraw.x = destX - frameAnchor.x;
		posToDraw.y = destY - frameAnchor.y;
		posToDraw.w = frameClip.w;
		posToDraw.h = frameClip.h;

		GM->renderTexture(spriteSheet, GM->GetSDLRenderer(), posToDraw.x, posToDraw.y, &frameClip);
	}

	void Frame::loadFrame(ifstream &file)
	{
		string buffer;
		getline(file, buffer);
		stringstream ss;
		
		//index
		getline(file, buffer);
		buffer = FileUtils::GetSubstrFiles(buffer);
		ss << buffer;
		ss >> frameIndex;

		//duration
		getline(file, buffer);
		ss.clear();
		buffer = FileUtils::GetSubstrFiles(buffer);
		ss << buffer;
		ss >> frameDuration;

		//anchor
		getline(file, buffer);
		ss.clear();
		buffer = FileUtils::GetSubstrFiles(buffer);
		ss << buffer;
		ss >> frameAnchor.x >> frameAnchor.y;
		
		//index
		getline(file, buffer);
		ss.clear();
		buffer = FileUtils::GetSubstrFiles(buffer);
		ss << buffer;
		ss >> frameClip.x >> frameClip.y >> frameClip.w >> frameClip.h;
	}
}