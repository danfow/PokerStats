#pragma once
#include <vector>
#include "Card.h"
#include <string>
using namespace std;
class Deck
{
public:
	Deck() {
		generateDeck();
	}
	vector<Card> deck;
	void generateDeck();
	void printDeck();
	void shuffleDeck();
	string getStringValueCard (Card::values cardVal);
};



