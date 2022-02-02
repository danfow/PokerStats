#include <iostream>
#include "Deck.h"
using namespace std;


int main() {

	Deck gameDeck;
	gameDeck.generateDeck();
	gameDeck.printDeck();
	cout << "Done" << endl;

	

	

	return 0;
}