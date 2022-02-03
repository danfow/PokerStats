#include <iostream>
#include "pokerGame.h"
using namespace std;


int main() {

	pokerGame pGame;
	pGame.gameDeck.printDeck();
	pGame.gameDeck.shuffleDeck();
	cout << endl;
	cout << "deck size is " << pGame.gameDeck.deck.size();
	cout << endl << endl << endl;
	pGame.gameDeck.printDeck();
	cout << endl << endl << endl;
	for (int i = 0; i < 100; i++) {
		pGame.addPlayerHand();
		pGame.addOtherHands();
		cout << "Player one hand size is " << pGame.getPlayerHand().size() << endl;
		cout << "Player one hand is " << pGame.printHand(pGame.getPlayerHand()) << endl;
		cout << "1st other player hand is " << pGame.printHand(pGame.getOtherHand1()) << endl;
		cout << "1st other player hand size is " << pGame.getOtherHand1().size() << endl;
		cout << "2nd other player hand is " << pGame.printHand(pGame.getOtherHand2()) << endl;
		cout << "2nd other player hand size is " << pGame.getOtherHand2().size() << endl;
		cout << "3rd other player hand is " << pGame.printHand(pGame.getOtherHand3()) << endl;
		cout << "3rd other player hand size is " << pGame.getOtherHand3().size() << endl;
		cout << "4th other player hand is " << pGame.printHand(pGame.getOtherHand4()) << endl;
		cout << "4th other player hand size is " << pGame.getOtherHand4().size() << endl;
		cout << "5th other player hand is " << pGame.printHand(pGame.getOtherHand5()) << endl;
		cout << "5th other player hand size is " << pGame.getOtherHand5().size() << endl;
		cout << "deck size is " << pGame.gameDeck.deck.size() << endl;
		if (pGame.anyoneHaveSameCard() == true) {
			cout << "Someone has the same card as someone else. Something is broken" << endl;
		}
		else {
			cout << "no one has the same card" << endl;
		}
		pGame.gameDeck.printDeck();
		cout << endl << endl << endl << endl << endl;
		pGame.clearPlayerHand();
		pGame.clearOtherHands();
		pGame.gameDeck.shuffleDeck();
	}
	cout << "Done" << endl;

	

	

	

	return 0;
}