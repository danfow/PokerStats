#include <iostream>
#include "pokerGame.h"
#include <fstream>
using namespace std;

void testingHandDistribution() {
	for (int i = 0; i < 100; i++) {
		pokerGame pGame;
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
}

void pairAndThreeKindTest() {
	ofstream cardStats("cardStats.txt");
	ofstream logFile("logFile.txt");
	pokerGame pGame;
	cout << "Loading...." << endl;
	pGame.gameDeck.shuffleDeck();
	int handsDealt = 0;
	int handNum = 1;
	int totalNumIteration = 1;


	for (int i = 0; i < 250; i++) {
		pGame.gameDeck.shuffleDeck();
		pGame.addPlayerHand();
		pGame.incrementPlayerHandsCounter();
		pGame.outputStatsplayer(logFile, handNum, totalNumIteration);
		for (int j = 0; j < 250;j++) {
			pGame.addOtherHands();
			pGame.incrementOthersCounter();
			pGame.outputStatsOthers(logFile,handNum,totalNumIteration);
			pGame.clearOtherHands();
			pGame.gameDeck.shuffleDeck();
			totalNumIteration += 1;
		}
		pGame.clearPlayerHand();
		pGame.gameDeck.shuffleDeck();	
		handNum += 1;
		totalNumIteration = 1;
	}
	pGame.cardOutputPerLine(cardStats);
	cardStats.close();
	logFile.close();
	cout << "Done! Check output files" << endl;
	cout << endl << endl << endl << endl << endl;
	
}

int main() {

	pairAndThreeKindTest();

	return 0;
}