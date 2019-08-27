#include "MessageDispatcher.h"

namespace Logic {
	
	MessageDispatcher::~MessageDispatcher()
	{
		//Just in case there are pending msg to process
		auto it = _messages.begin();
		for (; it != _messages.end(); ++it)
		{
			delete (*it->get());
		}
		_messages.clear();
	} 

	bool MessageDispatcher::AddMessageToQueue(Message *msg)
	{
		bool isAccepted = AcceptMessage(msg);
		if (isAccepted)
		{
			auto message = std::make_shared<Message*>(msg);
			_messages.push_back(message);
		}
		return isAccepted;
	}

	void MessageDispatcher::ProcessAllMessages()
	{
		auto it = _messages.begin();
		for (; it != _messages.end(); ++it)
		{
			ProcessMessage(*it->get()); //de-reference msg to process
			delete (*it->get()); //remove msg because it's processed
		}
		_messages.clear();//Once it finishes from processing all of them, clear the list
	}
}

