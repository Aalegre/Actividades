#include "Player.h"



Player::Player()
{
}

Player::Player(int score_, std::string name_)
{
	score = score_;
	name = name_;
}


Player::~Player()
{
}

bool Player::operator<(const Player& p_) const
{
	if (score == p_.score) {
		return name >= p_.name;
	}
	else {
		return score < p_.score;
	}
}
bool Player::operator>(const Player& p_) const
{
	if (score == p_.score) {
		return name <= p_.name;
	}
	else {
		return score > p_.score;
	}
}

int Player::GetScore() const
{
	return score;
}

std::string Player::GetName() const
{
	return name;
}
