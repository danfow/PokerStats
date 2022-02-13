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
	void sortPlayerHand();
	void sortOthersHand();
	void sortPlayerHandRankings();
	enum handTypes { minimum  = -1, highCard = 0, onePair = 1, twoPair = 2, threeKind = 3, straight = 4, flush = 5, fullhouse = 6,fourKind = 7,straightFlush = 8,royalFlush = 9 };
	string getStringValueCard(Card::values cardVal); 
	string getStringValueRank(handTypes handRank); 
	int getCountFromRankString(string HandRankString); 
	int evalHighCard(vector<Card> &hand, int rightOffset); 
	int getHighCardIndex(int offsetFromRightOfHand);
	int evalOnePair(vector<Card> &hand, int rightOffset); 
	int evalStraight(vector<Card> &hand); 
	int getHighPairIndex(int offsetFromRightOfHand);
	int getHighTwoPairIndex(int offsetFromRightOfHand);
	int getHighThreeKindIndex();
	int getHighFourKindIndex();
	int getHighStraightIndex();
	int getFullHouseIndex();
	int getHighFlushIndex();
	int getStraightFlushIndex();
	bool isPairsInVector(int pairVal, vector<Card> hand);
	void incrementCardRank(handTypes &hand, bool isTied); 
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
	bool isPair(vector<Card>& hand);
	bool is2Pair(vector<Card>& hand);
	bool is3Kind(vector<Card>& hand);
	bool isTie = false;
	bool isFlush(vector<Card>& hand);
	int pairOrThreeKind(vector<Card>& hand);
	bool isStraight(vector<Card>& hand);
	bool isStraighFlush(vector<Card>& hand);
	bool isRoyalFlush(vector<Card>& hand);
	void cardOutputPerLine(ofstream& logFile);
	void outputStatsplayer(ofstream& statsFile, int playerHandNum, int otherHandNum);
	void outputStatsOthers(ofstream& statsFile, int playerHandNum, int otherHandNum);
	void testMethod();
	void incrementOthersCounter() {
		totalHandsDealt += 5; 
	}
	void incrementPlayerHandsCounter() {
		totalHandsDealt += 1; 
	}


	int playerHighCardFrequency = 0;
	int playerOnePairFrequency = 0;
	int playerTwoPairFrequency = 0;
	int playerThreeOfAKindFrequency = 0;
	int playerFullHouseFrequency = 0;
	int playerFourKindFrequency = 0;
	int playerStraightFrequency = 0;
	int playerFlushFrequency = 0;
	int playerStraightFlushFrequency = 0;
	int playerRoyalFlushFrequency = 0;
	int playerhandsDealt = 0;


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
	int fourKindFrequency = 0;
	int fourkindWins = 0;
	int straightWins = 0;
	int straightFrequency = 0;
	int flushWins = 0;
	int flushFrequency = 0;
	int straightFlushFrequency = 0;
	int straightFlushWins = 0;
	int royalFlushWins = 0;
	int royalFlushFrequency = 0;
	int fullHouseWins = 0;
	int fullHouseFrequency = 0;
	int testInt = 0;
	

	


	vector<Card> otherHand1;
	vector<Card> otherHand2;
	vector<Card> otherHand3;
	vector<Card> otherHand4;
	vector<Card> otherHand5;
	vector<vector<Card>> players;
	vector<handTypes> playerHandTypes{highCard,highCard,highCard,highCard,highCard,highCard};
	


};

