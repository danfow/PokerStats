#pragma once
#include <vector>
#include "Card.h"
#include <string>
using namespace std;
class Deck
{
public:

	vector<Card> deck;
	void generateDeck();
	void printDeck();
	string getStringValueCard (Card::values cardVal);
};



