#include <iostream>
#include <stdlib.h>
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

void set_wheel(Player&, Player&);
void place_bet(Player&);
void change_bet(Player&);
void house_roll(Player&, Player&, const int, string&);
bool play_again(Player&, const string);


int main()
{
	// Define Player and House
	Player user;
	Player house;

	set_wheel(user, house);

	bool running = true;
	while (running)
	{
		// User places bet
		place_bet(user);

		// User first roll
		int user_roll = user.Roulette_Wheel.Spin();

		// User bet change
		cout << "You rolled: " << user_roll << endl;
		change_bet(user);

		// House rolls and user Payout
		string result;
		cout << "You rolled: " << user_roll << endl;
		house_roll(user, house, user_roll, result);

		// Results
		cout << result << endl;
		cout << "Balance: " << user.getMoney() << endl;

		if (!play_again(user, result)) { running = false; }
	}


	return 0;
}

void set_wheel(Player& player, Player& house)
{
	string value;
	cout << "Choose how many values are on the wheel (6-20): ";
	cin >> value;

	player.Roulette_Wheel.setUpperBound(stoi(value));
	house.Roulette_Wheel.setUpperBound(stoi(value));

	system("cls");
}

void place_bet(Player& player)
{
	string bet;
	cout << "Balance: " << player.getMoney() << endl;
	cout << "Place your bet and spin the wheel: ";
	cin >> bet;

	player.setCurrentBet(stoi(bet));

	system("cls");
}

void change_bet(Player& player)
{
	string choice;
	cout << "Do you want to change your bet?" << endl
		<< "1: Keep Bet" << endl
		<< "2: Double Bet" << endl
		<< "3: Cut bet in half" << endl
		<< "Choice: ";
	cin >> choice;

	switch (stoi(choice))
	{
	case 1:
		player.setBetType("");
		break;

	case 2:
		player.setBetType("Double");
		player.setCurrentBet(player.getCurrentBet() * 2);
		break;

	case 3:
		player.setBetType("Halved");
		player.setCurrentBet(player.getCurrentBet() / 2);
		break;
	}

	system("cls");
}

void house_roll(Player& player, Player& house, const int user_roll, string& result)
{
	int house_roll[2];

	if ((player.getBetType() == "Double") or (player.getBetType() == "Halved"))
	{
		house_roll[0] = house.Roulette_Wheel.Spin();
		house_roll[1] = house.Roulette_Wheel.Spin();

		cout << "House rolled: " << house_roll[0] << ", " << house_roll[1] << endl;

		if (player.getBetType() == "Double")
		{
			if ((user_roll > house_roll[0]) and (user_roll > house_roll[1]))
			{
				player.Payout(true);
				result = "Player Wins";

			}
			else
			{
				player.Payout(false);
				result = "Player Loses";
			}
		}
		else if (player.getBetType() == "Halved")
		{
			if ((user_roll > house_roll[0]) and (user_roll > house_roll[1]))
			{
				player.Payout(true);
				result = "Player Wins";
			}
			else if ((user_roll <= house_roll[0]) and (user_roll <= house_roll[1]))
			{
				player.Payout(false);
				result = "Player Loses";
			}
			else
			{
				player.setCurrentBet(0);
				result = "Draw";
			}
		}
	}
	else
	{
		house_roll[0] = house.Roulette_Wheel.Spin();

		cout << "House rolled: " << house_roll[0] << endl;

		if (user_roll > house_roll[0])
		{
			player.Payout(true);
			result = "Player Wins";
		}
		else
		{
			player.Payout(false);
			result = "Player Loses";
		}
	}
}

bool play_again(Player& player, const string result)
{
	string again = "";

	if ((result == "Player Loses") or (player.getMoney() == 0))
	{
		return false;
	}
	else
	{
		cout << "Play Again (y/n)? ";
		cin >> again;

		system("cls");

		if (again == "y") { return true; }
		else { return false; }
	}
}
