#include "Player.h"


Player::Player()
{
	Money = 500;
	CurrentBet = 0;
	BetType = "";
}

void Player::setCurrentBet(int bet) { CurrentBet = bet; }
void Player::setBetType(string bet_change) { BetType = bet_change; }


int Player::getMoney() { return Money; }
int Player::getCurrentBet() { return CurrentBet; }
string Player::getBetType() { return BetType; }

void Player::Payout(bool win)
{
	if (win) { Money += CurrentBet; }
	else
	{
		if (BetType == "Halved") { Money -= (CurrentBet * 2); }
		else { Money -= CurrentBet; }
	}

	CurrentBet = 0;
}
