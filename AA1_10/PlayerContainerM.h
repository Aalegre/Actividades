#pragma once
#include "Player.h"
#include <map>

class PlayerContainerM
{
public:
	std::map<int, std::string> data;

	PlayerContainerM();
	~PlayerContainerM();
	void Add(const Player& player_);
	void print() const;
};

