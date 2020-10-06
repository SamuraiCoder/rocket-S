#ifndef GAME_UTILS
#define GAME_UTILS
/*
* GameUtils.h 
* Class to have some specific functionalities aggregated in a class
*/

namespace GameUtils {
	/*
	* GetRandomBoolean
	* Get a random boolean between true or false =)
	* It uses std::bernoulli_distribution
	*/
	bool GetRandomBoolean();
}


#endif