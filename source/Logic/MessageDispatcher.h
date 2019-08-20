#ifndef MESSAGE_DISPATCHER
#define MESSAGE_DISPATCHER

#include <iostream>
#include <list>
#include <memory>

using namespace std;

#include "GameUtils\Globals.h"

namespace Logic {
	/*
	* Message will contain a message that it's going to be sended/received. 
	*/
	class Message
	{
	public:
		Message() {}
		virtual ~Message() {}
		virtual Constants::MessageType getType() = 0;
	}; 

	/*
	MessageDispatcher:
	This class will handle communication between components. BaseClass (BaseComponent)
	will inherit this dispatcher and will delegate all its methods to process messages
	*/
	class MessageDispatcher
	{
		public:
			//Default base constructor (does nothing)
			MessageDispatcher() {}
			virtual ~MessageDispatcher();

			//This method just add a message to the queue if it's accepted by the receiver. 
			bool AddMessageToQueue(Message *message);

			//Checks what messages will be accepted. Every class should implement this method.
			virtual bool AcceptMessage(Message *message) { return false; }

			//Handles a message and performs an action. Every class should implement this method. 
			virtual void ProcessMessage(std::shared_ptr<Message*> message) { }

			//This method will process all the message's queue. Probably will be called from Component's tick
			void ProcessAllMessages();

	protected:
		//List that holds all the messages
		std::list< std::shared_ptr<Message*> > _messages;

	};
}

#endif