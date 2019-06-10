#include "Frame.h"

namespace Graphics{

	void Frame::Draw(SDL_Texture* spriteSheet, float destX, float destY)
	{
		SDL_Rect posToDraw;
		posToDraw.x = (int)destX - frameAnchor.x;
		posToDraw.y = (int)destY - frameAnchor.y;
		posToDraw.w = frameClip.w;
		posToDraw.h = frameClip.h;

		Graphics::CGraphicsManager::Instance().renderTexture(spriteSheet, Graphics::CGraphicsManager::Instance().GetSDLRenderer(), posToDraw.x, posToDraw.y, &frameClip);
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