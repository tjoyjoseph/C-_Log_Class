

#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <algorithm>
#include <vector>
#include <fstream>

#include "DynArray.h"

struct deck
{
	int suit;
	int rank;
};


class Players
{
public:
	Players() {
		Points = 0;
		winner = false;
		AI = false;
		dealer = false;
		playername = "dealer";
		hit = true;
	}
	void SetPlayerName(string name = "Dealer")
	{
		if (dealer == false)
		{
			cout << "What is your name? ";
			cin >> name;
		}
		playername = name;
	}
	void SetPlayerType(bool Dealer = false)
	{
		if (Dealer == false)
		{
			char isAI;
			cout << "Is " << playername << " a computer? <y or n>";
			cin >> isAI;
			if (isAI == 'y')
			{
				AI = true;
			}
		}
		else
		{
			dealer = true;
		}
	}
	void AssignCard(DynArray<deck>& Cards, int card);
	void HitorStand() {
		if (Points > 21)
		{
			hit = false;
			winner = false;
			cout << playername << ", You lose." << endl;
		}
		else
		{
			cout << playername << endl;
			cout << "Your Points - " << Points << endl;
			if ((AI == true) || (dealer == true))
			{
				if (Points > 21)
				{
					winner = false;
					hit = false;
				}
				else if ((Points > 17) && (Points < 22))
				{
					hit = false;
					cout << "stand" << endl;
				}
				else if (Points <= 17)
				{
					cout << "Hit" << endl;
					hit = true;
				}
				else if (Points == 21)
				{
					cout << "Black Jack" << endl;
					winner = true;
				}
			}
			else
			{
				if (Points < 21)
				{
					char PlayerChoice = 'z';
					while (!((PlayerChoice == 'h') || (PlayerChoice == 's')) || (cin.fail()))
					{
						cout << "Hit (h) or Stand (s)";
						cin >> PlayerChoice;
						if (PlayerChoice == 'h') {
							hit = true;
						}
						else if (PlayerChoice == 's') {
							hit = false;
						}
						else
						{
							cout << "Invalid Choice" << endl;
							cout << "" << endl;
							cin.clear();
							cin.ignore();
						}
					}
				}
				else if (Points == 21) {
					hit = false;
					winner = true;
				}
			}
		}
	}
	void AddPoints()
	{
		int i = PlayerCards.front().rank;
		if ((i == 10) || (i == 11) || (i == 12))
		{
			Points += 10;
		}
		else
		{
			Points += i + 1;
		}
		cout << "Player's points - " << Points << endl;
		cout << "" << endl;
	}
	string playername;
	bool hit;
	bool winner;
private:
	vector<deck> PlayerCards;
	int Points;
	bool AI;
	bool dealer;
};
