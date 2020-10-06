#include "GameUtils.h"

#include <iostream>
#include <iomanip>
#include <map>
#include <random>

namespace GameUtils {

	bool GameUtils::GetRandomBoolean()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::bernoulli_distribution d(0.5);

		return d(gen);
	}
	

}
