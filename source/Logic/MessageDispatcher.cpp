#include "MessageDispatcher.h"

namespace Logic {
	
	MessageDispatcher::~MessageDispatcher()
	{
		//Just in case there are pending msg to process
		auto it = _messages.begin();
		for (; it != _messages.end(); ++it)
		{
			delete (*it);
		}
		_messages.clear();
	} 

	bool MessageDispatcher::AddMessageToQueue(Message *message)
	{
		bool isAccepted = AcceptMessage(message);
		if (isAccepted)
		{
			message->increaseRef();
			_messages.push_back(message);
		}
		return isAccepted;
	}

	void MessageDispatcher::ProcessAllMessages()
	{
		auto it = _messages.begin();
		for (; it != _messages.end(); ++it)
		{
			auto msg = (*it);
			ProcessMessage(msg); //de-reference msg to process
			msg->decreaseRef();//remove one reference because it's processed
		}
		_messages.clear();//Once it finishes from processing all of them, clear the list
	}
}

