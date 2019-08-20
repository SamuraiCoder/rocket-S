#include "MessageDispatcher.h"

namespace Logic {
	
	MessageDispatcher::~MessageDispatcher()
	{
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
			ProcessMessage(*it); 
		}
		//due to the usage of shared_ptr once it's processed it deletes 1 ref counter. If 0 then it deletes 
		_messages.clear();

	}
}

