#include "FrameAnimation.h"
#include "GameUtils\FileUtils.h"

namespace Graphics {
	FrameAnimation::FrameAnimation(const string &name)
	{
		frameAnimationName = name;
	}

	Frame* FrameAnimation::getNextFrame(Frame *frame)
	{
		if (frame->GetFrameIndex() + 1 < animationFrames.size())
			return getFrame(frame->GetFrameIndex() + 1);//next frame
		else
			return getFrame(0);//first frame
	}

	Frame* FrameAnimation::getFrame(int fIndex)
	{
		if (animationFrames.size() == 0)
			return nullptr;

		auto itFrameFound = std::next(animationFrames.begin(), fIndex);
		return &(*itFrameFound);
	}

	void FrameAnimation::loadAnimation(ifstream &file)
	{
		getline(file, frameAnimationName);
		
		string buffer;
		getline(file, buffer);
		
		stringstream ss;
		buffer = FileUtils::GetSubstrFiles(buffer);
		ss << buffer;
		int amountOfFrames;
		ss >> amountOfFrames;

		for (int i = 0; i < amountOfFrames; ++i)
		{
			Frame newFrame;
			newFrame.loadFrame(file);
			animationFrames.push_back(newFrame);
		}
	}
}

