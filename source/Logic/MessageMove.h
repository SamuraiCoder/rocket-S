#ifndef MESSAGE_MOVE_FORWARD
#define MESSAGE_MOVE_FORWARD

/*
	MessageMove: 
		This msg will be send when movement (with key pressed/released) is involved
*/

#include "Logic\MessageDispatcher.h"
#include "GameUtils\Globals.h"

namespace Logic{
	class CMessageMove : public Message
	{
	public:
		CMessageMove(Constants::MessageType typeOfMov) : _typeOfMovement(typeOfMov) {}
		~CMessageMove() {}
		Constants::MessageType getType() { return _typeOfMovement; }
		Constants::MessageType _typeOfMovement;
	};
}

#endif