#include <iostream>
#include "pokerGame.h"
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void testingHandDistribution() {
	pokerGame pGame;
	srand(time(0));
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
}




void pairAndThreeKindTest() {
	ofstream cardStats("cardStats.txt");
	ofstream logFile("logFile.txt");
	pokerGame pGame;
	//pGame.generatePlayers();
	cout << "Loading...." << endl;
	pGame.gameDeck.shuffleDeck();
	int handsDealt = 0;
	int handNum = 1;
	int totalNumIteration = 1;

	//an extra 250 iterations is being counted for player 1. Need to seperate extra player line from counter!
	
	for (int i = 0; i < 800; i++) {
		pGame.playerhandsDealt++;
		pGame.incrementPlayerHandsCounter(); // where does this thing go
		pGame.gameDeck.shuffleDeck();
		pGame.addPlayerHand();;
		pGame.outputStatsplayer(logFile, handNum, totalNumIteration);
		for (int j = 0; j < 500;j++) {
			//pGame.incrementPlayerHandsCounter();
			//pGame.outputStatsplayer(logFile, handNum, totalNumIteration);
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

void testSortFunction() {
	pokerGame pGame;
	pGame.gameDeck.shuffleDeck();
	pGame.testMethod();

}
int main() {
	// got code for getting program execution time here https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
	auto start = high_resolution_clock::now();
	pairAndThreeKindTest();
	//testSortFunction();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	cout << "Time taken by program: "
		<< duration.count() << " seconds" << endl;

	return 0;
}



/*TODO
*Fix bug of aces not being ranked highest in 1 pair ties
Implement tie rules for 2pair and up
* Get full house tie rules and up implemented
* fix log counter for player
* Profit
*/