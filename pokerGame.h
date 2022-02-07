#pragma once
#include "Deck.h"
#include <map>
class pokerGame
{

public:
	pokerGame() {
		generatePlayers();
	}
	void addCard(vector<Card>& hand, Card cardToAdd);
	void sortHand(vector<Card>& hand);
	string getStringValueCard(Card::values cardVal);
	string printHand(vector<Card> hand);
	void clearPlayerHand();
	void clearOtherHands();
	Deck gameDeck;
	void addPlayerHand();
	void addOtherHands();
	void  generatePlayers() {
		players.push_back(playerHand);
		players.push_back(otherHand1);
		players.push_back(otherHand2);
		players.push_back(otherHand3);
		players.push_back(otherHand4);
		players.push_back(otherHand5);
		
	}
	vector<Card> getPlayerHand();
	vector<Card> getOtherHand1();
	vector<Card> getOtherHand2();
	vector<Card> getOtherHand3();
	vector<Card> getOtherHand4();
	vector<Card> getOtherHand5();
	
	bool anyoneHaveSameCard();
	int pairOrThreeKind(vector<Card> hand);
	void cardOutputPerLine(ofstream& logFile);
	void outputStatsplayer(ofstream& statsFile, int playerHandNum, int otherHandNum);
	void outputStatsOthers(ofstream& statsFile, int playerHandNum, int otherHandNum);
	void incrementOthersCounter() {
		totalHandsDealt += 5; // dont forget to change this when its 2 for loops!
	}
	void incrementPlayerHandsCounter() {
		totalHandsDealt += 1; // dont forget to change this when its 2 for loops!
	}


private:
	vector<Card> playerHand;
	int totalHandsDealt = 0;
	int playerWins = 0;
	int highCardWins = 0;
	int highCardFrequency = 0;
	int onePairWins = 0;
	int onePairFrequency = 0;
	int twoPairWins = 0;
	int twoPairFrequency = 0;
	int threeOfAKindWins = 0;
	int threeOfAKindFrequency = 0;
	int straightWins = 0;
	int straightWinsFrquency = 0;
	int flushWins = 0;
	int flushWinsFrequency = 0;
	int fullHouseWins = 0;
	int fullHouseWinsFrequency = 0;

	vector<Card> otherHand1;
	vector<Card> otherHand2;
	vector<Card> otherHand3;
	vector<Card> otherHand4;
	vector<Card> otherHand5;
	vector<vector<Card>> players;
	


};

