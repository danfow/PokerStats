#include "pokerGame.h"
#include <iostream>
void pokerGame::sortHand(vector<Card>& hand) {
	for (int i = 0; i < hand.size() - 1; i++)
		for (int j = 0; j < hand.size() - i - 1; j++)
			if (hand.at(j).getValue() > hand.at(j + 1).getValue())
				swap(hand.at(j), hand.at(j + 1));
}

void pokerGame::addCard(vector<Card> &hand, Card cardToAdd) {
	hand.push_back(cardToAdd);
}

string pokerGame::getStringValueCard(Card::values cardVal)
{
	switch (cardVal)
	{
	case Card::ace:
		return "A";
		break;
	case Card::two:
		return "2";
		break;
	case Card::three:
		return "3";
		break;
	case Card::four:
		return "4";
		break;
	case Card::five:
		return "5";
		break;
	case Card::six:
		return "6";
		break;
	case Card::seven:
		return "7";
		break;
	case Card::eight:
		return "8";
		break;
	case Card::nine:
		return "9";
		break;
	case Card::ten:
		return "10";
		break;
	case Card::jack:
		return "J";
		break;
	case Card::queen:
		return "Q";
		break;
	case Card::king:
		return "K";
		break;
	case Card::lastV:
		return "something went wrong";
		break;
	default:
		return "something went wrong";
		break;
	}

}

string pokerGame::printHand(vector<Card> hand)
{
	string playerHandString;
	for (int i = 0; i < hand.size(); i++) {
		Card deckCard = hand.at(i);
		switch (deckCard.getSuit())
		{
		case Card::Spades:
			playerHandString +=  (getStringValueCard(deckCard.getValue()) + "S" + " ");
			break;
		case Card::Hearts:
			playerHandString += (getStringValueCard(deckCard.getValue()) + "H" + " ");
			break;
		case Card::Diamonds:
			playerHandString += (getStringValueCard(deckCard.getValue()) + "D" + " ");
			break;
		case Card::Clubs:
			playerHandString += (getStringValueCard(deckCard.getValue()) + "C" + " ");
			break;
		default:
			return " Uhh ohh something broke";
			break;
		}
		
	}
	return playerHandString;
}

void pokerGame::clearPlayerHand()
{
	
	for (int i = 0; i < playerHand.size(); i++) {
		gameDeck.deck.push_back(playerHand.at(i));
	}
	playerHand.clear();
}

void pokerGame::clearOtherHands()
{
	for (int i = 0; i < otherHand1.size(); i++) {
		gameDeck.deck.push_back(otherHand1.at(i));
		gameDeck.deck.push_back(otherHand2.at(i));
		gameDeck.deck.push_back(otherHand3.at(i));
		gameDeck.deck.push_back(otherHand4.at(i));
		gameDeck.deck.push_back(otherHand5.at(i));
	}
	playerHand.clear();
	otherHand1.clear();
	otherHand2.clear();
	otherHand3.clear();
	otherHand4.clear();
	otherHand5.clear();
}
	

void pokerGame::addPlayerHand()
{
	for (int i = 0; i < 5; i++) {
		addCard(playerHand, gameDeck.deck.at(i));
	}
	gameDeck.deck.erase(gameDeck.deck.begin() ,gameDeck.deck.begin() +  5);
}

void pokerGame::addOtherHands()
{
	int numPlayers = 5;
	int numCards = 5;
	for (int i = 0; i < 5; i++) {
		addCard(otherHand1, gameDeck.deck.at(i));
		addCard(otherHand2, gameDeck.deck.at(i+5));
		addCard(otherHand3, gameDeck.deck.at(i+10));
		addCard(otherHand4, gameDeck.deck.at(i+15));
		addCard(otherHand5, gameDeck.deck.at(i+20));
	}
	gameDeck.deck.erase(gameDeck.deck.begin(),gameDeck.deck.begin() + (numPlayers * numCards));
}

vector<Card> pokerGame::getPlayerHand()
{
	return playerHand;
}

vector<Card> pokerGame::getOtherHand1()
{
	return otherHand1;
}

vector<Card> pokerGame::getOtherHand2()
{
	return otherHand2;
}

vector<Card> pokerGame::getOtherHand3()
{
	return otherHand3;
}

vector<Card> pokerGame::getOtherHand4()
{
	return otherHand4;
}

vector<Card> pokerGame::getOtherHand5()
{
	return otherHand5;
}

//don't open this method or you will know despair. NEVER code when you're tired.
bool pokerGame::anyoneHaveSameCard()
{
	
	for (int i = 0; i < playerHand.size(); i++) {
		if (playerHand.at(i).getValue() == otherHand1.at(i).getValue() && playerHand.at(i).getSuit() == otherHand1.at(i).getSuit()) {
			return true;
		}
		if (playerHand.at(i).getValue() == otherHand2.at(i).getValue() && playerHand.at(i).getSuit() == otherHand2.at(i).getSuit()) {
			return true;
		}
		if (playerHand.at(i).getValue() == otherHand3.at(i).getValue() && playerHand.at(i).getSuit() == otherHand3.at(i).getSuit()) {
			return true;
		}
		if (playerHand.at(i).getValue() == otherHand4.at(i).getValue() && playerHand.at(i).getSuit() == otherHand4.at(i).getSuit()) {
			return true;
		}
		if (playerHand.at(i).getValue() == otherHand5.at(i).getValue() && playerHand.at(i).getSuit() == otherHand5.at(i).getSuit()) {
			return true;
		}


		if (otherHand1.at(i).getValue() == otherHand2.at(i).getValue() && otherHand1.at(i).getSuit() == otherHand2.at(i).getSuit()) {
			return true;
		}
		if (otherHand1.at(i).getValue() == otherHand3.at(i).getValue() && otherHand1.at(i).getSuit() == otherHand3.at(i).getSuit()) {
			return true;
		}
		if (otherHand1.at(i).getValue() == otherHand4.at(i).getValue() && otherHand1.at(i).getSuit() == otherHand4.at(i).getSuit()) {
			return true;
		}
		if (otherHand1.at(i).getValue() == otherHand5.at(i).getValue() && otherHand1.at(i).getSuit() == otherHand5.at(i).getSuit()) {
			return true;
		}



		if (otherHand2.at(i).getValue() == otherHand3.at(i).getValue() && otherHand2.at(i).getSuit() == otherHand3.at(i).getSuit()) {
			return true;
		}
		if (otherHand2.at(i).getValue() == otherHand4.at(i).getValue() && otherHand2.at(i).getSuit() == otherHand4.at(i).getSuit()) {
			return true;
		}
		if (otherHand2.at(i).getValue() == otherHand5.at(i).getValue() && otherHand2.at(i).getSuit() == otherHand5.at(i).getSuit()) {
			return true;
		}



		if (otherHand3.at(i).getValue() == otherHand4.at(i).getValue() && otherHand3.at(i).getSuit() == otherHand4.at(i).getSuit()) {
			return true;
		}
		if (otherHand3.at(i).getValue() == otherHand5.at(i).getValue() && otherHand3.at(i).getSuit() == otherHand5.at(i).getSuit()) {
			return true;
		}


		if (otherHand4.at(i).getValue() == otherHand5.at(i).getValue() && otherHand4.at(i).getSuit() == otherHand5.at(i).getSuit()) {
			return true;
		}

		return false;
		
		
		
		
	}
}
