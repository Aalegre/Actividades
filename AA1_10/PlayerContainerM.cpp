#include "PlayerContainerM.h"



PlayerContainerM::PlayerContainerM()
{
}


PlayerContainerM::~PlayerContainerM()
{
}

void PlayerContainerM::Add(const Player& player_)
{
	if (data.size() > 0) {

	}
	else {
		data.push_back(player_);
	}
}

void PlayerContainerM::print() const
{
}
