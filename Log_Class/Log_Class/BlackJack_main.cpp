//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <algorithm>
#include <vector>
#include <fstream>

//#include "DynArray.h"
#include "Players.h"

using namespace std;

const int DECKSIZE = 52;
const int maxRanks = 13;
const int maxSuit = 4;
const int MAXPLAYERS = 6;





string getRank(int deckRank)
{
	string CardRank[maxRanks];
	ifstream Ranks("Ranks.txt");
	if (Ranks)
	{
		for (int i = 0; i < 14; i++)
		{
			Ranks >> CardRank[i];
		}
	}
	//string CardRank[maxRanks] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	return CardRank[deckRank];
}

string getSuit(int deckSuit)
{
	string CardSuit[maxRanks];
	ifstream Suit("Suit.txt");
	if (Suit)
	{
		for (int i = 0; i < 14; i++)
		{
			Suit >> CardSuit[i];
		}
	}
	//string CardSuit[maxSuit] = { "Heart", "Diamond", "Spade", "Club" };
	return CardSuit[deckSuit];
}

void Players::AssignCard(DynArray<deck>&cards,int card = 6)
{
	//This function gives out the cards
	deck TempCards;
	TempCards.rank = cards[0].rank;
	TempCards.suit = cards[0].suit;
	PlayerCards.push_back(TempCards);
	if (((dealer == false) || (card == 0)) || ((dealer == true) && (!card == 1)))
	{
		cout << "\t" << getRank(PlayerCards.front().rank) << " of " << getSuit(PlayerCards.front().suit) << endl;
	}
	cards.removeFront();
	AddPoints();
}

void CreateCards(DynArray<deck>& cards)
{
	/// This function assigns integer to the decks to represent card rank and suit 
	int card = 0;
	deck TempCards;
	for (int suit = 0; suit < 4; suit++)
	{
		for (int rank = 0; rank < 13; rank++)
		{
			TempCards.rank = rank;
			TempCards.suit = suit;
			cards.push_back(TempCards);
		}
	}
}

int WelcomeScreen()
{
	//Welcome screen to display instructions
	cout << "\t\tWELCOME TO THE GAME OF BLACK JACK" << endl;
	cout << "\t\t=================================" << endl;
	cout << "" << endl;
	cout << "To start with you must choose how many players you would like." << endl;
	cout << "The maximum number of players you can choose is 6." << endl;
	cout << "" << endl;
	int Playernums = 0;
	while ((Playernums < 1) || (Playernums > 6)) 
	{
		cout << "How many players would you like to have? must be between 1 and 6  - "  ;
		cin >> Playernums;
		if (cin.fail() || Playernums < 1 || Playernums > 6)
		{
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore();
		}
		cout << "" << endl;
		Sleep(1000);
	}
	return Playernums;
}

DynArray<deck> DealCards(Players Player[MAXPLAYERS], Players& Dealer, int Playernums, DynArray<deck> Cards)
{
	for (int i = 0; i < Playernums; i++)
	{
		cout << "Player " << i + 1 << endl;
		Player[i].SetPlayerName();
		Player[i].SetPlayerType();
		cout << Player[i].playername << "'s cards are" << endl;
		for (int card = 0; card < 2; card++)
		{
			Player[i].AssignCard(Cards, card);
		}
		cout << "" << endl;
	}
	Dealer.SetPlayerType(true);
	Dealer.SetPlayerName();
	cout << "Dealer will always be a computer" << endl;
	cout << Dealer.playername << "'s first card is" << endl;
	for (int card = 0; card < 2; card++)
	{
		Dealer.AssignCard(Cards, card);
	}
	cout << "" << endl;
	return Cards;
}

void CalculateWinner(int Playernums, Players Dealer, Players Player[MAXPLAYERS])
{
	if (Dealer.winner == true)
	{
		cout << "The Dealer has won" << endl;
	}
	else
	{
		bool AnyPlayerwon = false;
		for (int i = 0; i < Playernums; i++)
		{
			if (Player[i].winner == true)
			{
				cout << Player[i].playername << " is the winner" << endl;
				AnyPlayerwon = true;
			}
		}
		if (AnyPlayerwon == false)
		{
			Dealer.winner = true;
			cout << "Since no player has won the Dealer automatically wins" << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int Playernums;
	Playernums = WelcomeScreen();
	DynArray<deck> Cards; 
	Players Player[MAXPLAYERS];
	Players Dealer;
	CreateCards(Cards);  ///pointer points to DECKSIZE array
	//random_shuffle(Cards.back(), Cards.front());
	///Test cards after random shuffle
	//for (int i = 0; i < 52; i++){cout << getSuit(Cards[i].suit) << " of " << getRank(Cards[i].rank) << endl;}

	///Create players and assign them their first set of cards
	Cards = DealCards(Player, Dealer, Playernums, Cards);
	Sleep(2000);
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	for (int i = 0; i < Playernums; i++)
	{
		while (Player[i].hit == true)
		{
			Player[i].HitorStand();
			if (Player[i].hit == true)
			{
				Player[i].AssignCard(Cards);
			}
		}
		cout << "" << endl;
		Sleep(2000);
	}
	while (Dealer.hit == true)
	{
		Dealer.HitorStand();
		if (Dealer.hit == true)
		{
			Dealer.AssignCard(Cards);
		}
	}
	Sleep(2000);
	CalculateWinner(Playernums, Dealer, Player);
}