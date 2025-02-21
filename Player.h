#pragma once
#include "Wheel.h"
#include <string>

using std::string;


class Player
{
private:
	int Money;
	int CurrentBet;
	string BetType;

public:
	Wheel Roulette_Wheel;

	Player();

	void setCurrentBet(int);
	void setBetType(string);

	int getMoney();
	int getCurrentBet();
	string getBetType();

	void Payout(bool);
};
