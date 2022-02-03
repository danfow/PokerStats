#include "Deck.h"
#include "Card.h"
#include  <iostream>

Card templateCard;
void Deck::generateDeck() {
	for (int suitInt = templateCard.Spades; suitInt != templateCard.lastS; suitInt++) {
		for (int valueInt = templateCard.ace; valueInt != templateCard.lastV; valueInt++) {
			Card tempCard;
			Card::values value = static_cast<Card::values>(valueInt);
			Card::suits suit = static_cast<Card::suits>(suitInt);
			tempCard.setValue(value) ;
			tempCard.setSuit(suit);
			deck.push_back(tempCard);
		}
	}

}


string Deck::getStringValueCard(Card::values cardVal)
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

void Deck::printDeck()
{
	for (int i = 0; i < deck.size(); i++) {
		Card deckCard = deck.at(i);
		switch (deckCard.getSuit())
		{
		case Card::Spades:
			cout << getStringValueCard( deckCard.getValue()) << "S" <<  " ";
			break;
		case Card::Hearts:
			cout << getStringValueCard(deckCard.getValue()) << "H" << " ";
			break;
		case Card::Diamonds:
			cout << getStringValueCard(deckCard.getValue()) << "D" << " ";
			break;
		case Card::Clubs:
			cout << getStringValueCard(deckCard.getValue()) << "C" << " ";
			break;
		default:
			cout << " Uhh ohh something broke";
			break;
		}
	}
}

void Deck::shuffleDeck()
{
	//been a while since I used random functions found this example here for this function https://www.geeksforgeeks.org/shuffle-a-deck-of-cards-3/
	srand(time(0));
	for (int i = 0; i < deck.size(); i++) {
		int randInt = i + (rand() % (deck.size() - i));
		swap(deck.at(i), deck.at(randInt));
	}
}




