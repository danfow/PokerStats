#pragma once
#include "Deck.h"
class pokerGame
{

public:
	void addCard(vector<Card> &hand, Card cardToAdd);
	void sortHand(vector<Card>& hand);
	string getStringValueCard(Card::values cardVal);
	string printHand(vector<Card> hand);
	void clearPlayerHand();
	void clearOtherHands();
	Deck gameDeck;
	void addPlayerHand();
	void addOtherHands();
	vector<Card> getPlayerHand();
	vector<Card> getOtherHand1();
	vector<Card> getOtherHand2();
	vector<Card> getOtherHand3();
	vector<Card> getOtherHand4();
	vector<Card> getOtherHand5();
	bool anyoneHaveSameCard();

private:
	vector<Card> playerHand;
	vector<Card> otherHand1;
	vector<Card> otherHand2;
	vector<Card> otherHand3;
	vector<Card> otherHand4;
	vector<Card> otherHand5;
	


};

