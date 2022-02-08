#include "pokerGame.h"
#include <iostream>
#include <fstream>


void pokerGame::addCard(vector<Card>& hand, Card cardToAdd) {
	hand.push_back(cardToAdd);
}

void pokerGame::sortPlayerHand()
{

	
	
	for (int i = 0; i < players.at(0).size() - 1; i++) {
		for (int j = 0; j < players.at(0).size() - i - 1; j++) {
			if (players.at(0).at(j).getValue() > players.at(0).at(j+1).getValue()) {

				/*
				Card tempCard;
				tempCard.setValue(hand.at(j).getValue());
				tempCard.setSuit(hand.at(j).getSuit());
				hand.at(j).setValue(hand.at(j + 1).getValue());
				hand.at(j).setSuit(hand.at(j + 1).getSuit());
				hand.at(j+1).setValue(tempCard.getValue());
				hand.at(j+1).setSuit(tempCard.getSuit());
				*/
				swap(players.at(0).at(j), players.at(0).at(j+1));
				

			}
		}
	}
}

void pokerGame::sortOthersHand()
{

	for (int k = 1; k < players.size(); k++) {
		for (int i = 0; i < players.at(k).size() - 1; i++) {
			for (int j = 0; j < players.at(0).size() - i - 1; j++) {
				if (players.at(k).at(j).getValue() > players.at(k).at(j + 1).getValue()) {

					/*
					Card tempCard;
					tempCard.setValue(hand.at(j).getValue());
					tempCard.setSuit(hand.at(j).getSuit());
					hand.at(j).setValue(hand.at(j + 1).getValue());
					hand.at(j).setSuit(hand.at(j + 1).getSuit());
					hand.at(j+1).setValue(tempCard.getValue());
					hand.at(j+1).setSuit(tempCard.getSuit());
					*/
					swap(players.at(k).at(j), players.at(k).at(j + 1));


				}
			}
		}
	}
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
	
	for (int i = 0; i < players.at(0).size(); i++) {
		//gameDeck.deck.push_back(playerHand.at(i));
		gameDeck.deck.push_back(  players.at(0).at(i));
	}
	//playerHand.clear();
	players.at(0).clear();
}

void pokerGame::clearOtherHands()
{
	/*
	for (int i = 0; i < otherHand1.size(); i++) {
		gameDeck.deck.push_back(otherHand1.at(i));
		gameDeck.deck.push_back(otherHand2.at(i));
		gameDeck.deck.push_back(otherHand3.at(i));
		gameDeck.deck.push_back(otherHand4.at(i));
		gameDeck.deck.push_back(otherHand5.at(i));
	}
	*/


	
	for (int i = 0; i < players.at(1).size(); i++) {
		gameDeck.deck.push_back(players.at(1).at(i));
		gameDeck.deck.push_back(players.at(2).at(i));
		gameDeck.deck.push_back(players.at(3).at(i));
		gameDeck.deck.push_back(players.at(4).at(i));
		gameDeck.deck.push_back(players.at(5).at(i));
	}

	

	/*
	otherHand1.clear();
	otherHand2.clear();
	otherHand3.clear();
	otherHand4.clear();
	otherHand5.clear();
	*/
	


	
	players.at(1).clear();
	players.at(2).clear();
	players.at(3).clear();
	players.at(4).clear();
	players.at(5).clear();
	


}
	

void pokerGame::addPlayerHand() // add 5 cards to the 'player' hand that we are testing the odds of winning
{
	for (int i = 0; i < 5; i++) {
		//addCard(playerHand, gameDeck.deck.at(i));
		addCard(players.at(0), gameDeck.deck.at(i));

	}
	gameDeck.deck.erase(gameDeck.deck.begin() ,gameDeck.deck.begin() +  5);
}

void pokerGame::addOtherHands() //dish out 5 cards each to the remaining 5 players
{
	int numPlayers = 5;
	int numCards = 5;
	for (int i = 0; i < 5; i++) {
		
		/*
		addCard(otherHand1, gameDeck.deck.at(i));
		addCard(otherHand2, gameDeck.deck.at(i+5));
		addCard(otherHand3, gameDeck.deck.at(i+10));
		addCard(otherHand4, gameDeck.deck.at(i+15));
		addCard(otherHand5, gameDeck.deck.at(i+20));
		*/


		
		addCard(players.at(1), gameDeck.deck.at(i));
		addCard(players.at(2), gameDeck.deck.at(i + 5));
		addCard(players.at(3), gameDeck.deck.at(i + 10));
		addCard(players.at(4), gameDeck.deck.at(i + 15));
		addCard(players.at(5), gameDeck.deck.at(i + 20));
		
	}
	gameDeck.deck.erase(gameDeck.deck.begin(),gameDeck.deck.begin() + (numPlayers * numCards));
}

vector<Card> pokerGame::getPlayerHand()
{
	return playerHand;
}

vector<Card> pokerGame::getOtherHand1() //should be a way to not duplicate all these methods but.....onward we go...
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
	/*
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
		*/

		return false;
		
		
		
		
	
}

bool pokerGame::isPair(vector<Card>& hand)
{
	for (int i = 0; i < hand.size()-i; i++) {
		if (hand.at(i + 1).getValue() == hand.at(i).getValue()) {
			return true;
		}
	}

	return false;
}

bool pokerGame::is2Pair(vector<Card>& hand)
{
	//TODO
	return false;
}

bool pokerGame::is3Kind(vector<Card>& hand)
{
	//TODO
	return false;
}

bool pokerGame::isFlush(vector<Card>& hand)
{
	for (int i = 0; i < hand.size() - 1; i++) {
		if (hand.at(i + 1).getSuit() == hand.at(i).getSuit()) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}


int pokerGame::pairOrThreeKind(vector<Card>& hand)
{
	{


		
		//remembered maps can be useful for this but not how to use them so I used this resource https://thispointer.com/c-how-to-find-duplicates-in-a-vector/
		map<int, int> checkForPair;
		for (int i = 0; i < hand.size(); i++) {
			//pair<string, int> tempPair(getStringValueCard(hand.at(i).getValue()), 1);
			pair<int, int> tempPair(hand.at(i).getValue(), 1);
			auto result = checkForPair.insert(tempPair); //result is a pair with the map and the bool indicating whether the insert succeeded or not
			if (result.second == false) { //card already occured in hand
				result.first->second++; //so iterate its value in map
			}


		}

		int handPairCount = 0;
		int handThreeOfKindCount = 0;
		int fourkindCount = 0;
		for (auto & cardOccurence : checkForPair) {//iterate over map
			if (cardOccurence.second > 3) {
				fourkindCount += 1;

			} 
			else if (cardOccurence.second > 2) { // 3 kind
				handThreeOfKindCount += 1;
			}
			
			else if (cardOccurence.second > 1) { // a pair
				handPairCount += 1;
			}
		}
		if (fourkindCount == 1) { //4kind
			return 5;
		}
		else if (handThreeOfKindCount == 1 && handPairCount == 1) { //full house
			return 4;
		}
		else if (handThreeOfKindCount == 1) { //3kind
			return 3;
		}
		else if (handPairCount == 2) { // 2pair
			return 2;
		}
		else if (handPairCount == 1) { //pair
			return 1;
		}
		else {
			return -1; //None of the above
		}

		

	}
}

bool pokerGame::isStraight(vector<Card>& hand)
{
	
	
	
	
	if (hand.at(0).getValue() == Card::ace && hand.at(1).getValue() == Card::ten && hand.at(2).getValue() == Card::jack
		&& hand.at(3).getValue() == Card::queen && hand.at(4).getValue() == Card::king)
	{
		return true;
	}
	

	for (int i = 0; i < hand.size()-1; i++) {
		if (hand.at(i+1).getValue() ==  (hand.at(i).getValue()) + 1) {
			continue;
		}
		else {
			return false;
		}

	}

	


	return true;
}

bool pokerGame::isStraighFlush(vector<Card>& hand)
{
	if (isStraight(hand) == true && isFlush(hand) == true) {
		return true;
	}
	else {
		return false;
	}
}

bool pokerGame::isRoyalFlush(vector<Card>& hand) {
	if (isStraighFlush(hand) == true && hand.at(0).getValue() == Card::ace && hand.at(4).getValue() == Card::king) {
		return true;
	}
	else {
		return false;
	}
}

void pokerGame::cardOutputPerLine(ofstream& logFile)
{
	logFile << endl << endl;
	logFile << "Total number of hands dealt is " << totalHandsDealt << endl;;
	logFile << "Total number of High card is " << highCardFrequency << " and its percentage is " << ((highCardFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << " Total number of one pairs is " << onePairFrequency << " and its percentage is " << ((onePairFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of two pairs is " << twoPairFrequency << " and its percentage is " << ((twoPairFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of three of a kind is " << threeOfAKindFrequency << " and its percentage is " << ((threeOfAKindFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of straights is " << straightFrequency << " and its percentage is " << ((straightFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of flushes is " << flushFrequency << " and its percentage is " << ((flushFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of full house is " << fullHouseFrequency << " and its percentage is " << ((fullHouseFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of 4kind is " << fourKindFrequency << " and its percentage is " << ((fourKindFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of Straight flushes is " << straightFlushFrequency << " and its percentage is " << ((straightFlushFrequency / float(totalHandsDealt))) * 100 << "%" << endl;
	logFile << "Total number of Royal flushes is " << royalFlushFrequency << " and its percentage is " << ((royalFlushFrequency / float(totalHandsDealt))) * 100 << "%" << endl;

}

void pokerGame::outputStatsplayer(ofstream& statsFile, int playerHandNum, int otherHandNum)
{
	sortPlayerHand();
	string output;
	statsFile << "Player Hand " << playerHandNum << " iteration " << otherHandNum << endl;
	if (isRoyalFlush(players.at(0)) == true) {
		output = "Royal Flush";
		royalFlushFrequency += 1;
	}

	else if (isStraighFlush(players.at(0)) == true) {
		output = "Straight Flush";
		straightFlushFrequency += 1;
	}
	else if (pairOrThreeKind(players.at(0)) == 5) {
		output = " 4Kind";
		fourKindFrequency+=1;
	}

	else if (isFlush(players.at(0)) == true) {
		output = "Flush";
		flushFrequency += 1;
	}
	
	else if (pairOrThreeKind(players.at(0)) == 4) {
		output = " Full House";
		fullHouseFrequency += 1;
		//twoPairFrequency += 1;
		//onePairFrequency += 1;
		//threeOfAKindFrequency += 1;
	}
	else if (isStraight(players.at(0)) == true) {
		output = " straight";
		straightFrequency += 1;
	}
	
	else if (pairOrThreeKind(players.at(0)) == 3) {
		output = " 3kind";
		threeOfAKindFrequency += 1;
		//onePairFrequency += 1;
	}
	
	
	else if (pairOrThreeKind(players.at(0)) == 2) {
		output = " 2pair";
		twoPairFrequency += 1;
		//onePairFrequency += 1; // does a two pair also count as an occurence of a pair?
	}
	
	else if (pairOrThreeKind(players.at(0)) == true) {
		output = " pair";
		onePairFrequency += 1; // do a 3kind also count as an occurence of a pair?
	}
	else  
	{
		output = "HCard";
		highCardFrequency += 1;
	 
	}
	 
	 
		
	statsFile << printHand(players.at(0)) << "," << output << endl;
	

	
}

void pokerGame::outputStatsOthers(ofstream& statsFile, int playerHandNum,int otherHandNum)
{
	sortOthersHand(); 
	string output;
	/*
	vector<vector<Card>> localPlayers;
	localPlayers.push_back(otherHand1);
	localPlayers.push_back(otherHand2);
	localPlayers.push_back(otherHand3);
	localPlayers.push_back(otherHand4);
	localPlayers.push_back(otherHand5);
	*/

	
	for (int i = 1; i < players.size(); i++) { 
		if (isRoyalFlush(players.at(i)) == true) {
			output = "Royal Flush";
			straightFlushFrequency += 1;
		}

		else if (isStraighFlush(players.at(i)) == true) {
			output = "Straight Flush";
			straightFlushFrequency += 1;
		}
		else if (pairOrThreeKind(players.at(i)) == 5) {
			output = " 4Kind";
			fourKindFrequency += 1;
		}
		else if (pairOrThreeKind(players.at(i)) == 4) {
			output = "Full house";
			fullHouseFrequency += 1;
			//twoPairFrequency += 1;
			//onePairFrequency += 1;
			//threeOfAKindFrequency += 1;
		}

		else if (isFlush(players.at(i)) == true) {
			output += "Flush";
			flushFrequency += 1;
		}

		else if (isStraight(players.at(i)) == true) {
			output = " straight";
			straightFrequency += 1;
		}
		
		else if (pairOrThreeKind(players.at(i)) == 3) {
			output = " 3kind";
			threeOfAKindFrequency += 1;
			//onePairFrequency += 1;
		}
		
		
		else if (pairOrThreeKind(players.at(i)) == 2) {
			output = " 2pair";
			twoPairFrequency += 1;
			//onePairFrequency += 1;
		}
		
		else if (pairOrThreeKind(players.at(i)) == 1) {
			output = " pair";
			onePairFrequency += 1;
		}
		else  {
			output = "HCard";
			highCardFrequency += 1;

		}
		
		statsFile << printHand(players.at(i)) << "," << output << endl;
	}

	statsFile << endl << endl;
	
	
}




void pokerGame::testMethod()
{
	
	
	addPlayerHand();
	addOtherHands();
	cout << "Player hand before sort is " << printHand(players.at(0)) << endl;
	cout << "Other hand1 before sort is " << printHand(players.at(1)) << endl;
	cout << "Other hand2 before sort is " << printHand(players.at(2)) << endl;
	cout << "Other hand3 before sort is " << printHand(players.at(3)) << endl;
	cout << "Other hand4 before sort is " << printHand(players.at(4)) << endl;
	cout << "Other hand5 before sort is " << printHand(players.at(5)) << endl;

	sortPlayerHand();
	sortOthersHand();
	

	cout << "Player hand after sort is " << printHand(players.at(0)) << endl;
	cout << "Other hand1 after sort is " << printHand(players.at(1)) << endl;
	cout << "Other hand2 after sort is " << printHand(players.at(2)) << endl;
	cout << "Other hand3 after sort is " << printHand(players.at(3)) << endl;
	cout << "Other hand4 after sort is " << printHand(players.at(4)) << endl;
	cout << "Other hand5 after sort is " << printHand(players.at(5)) << endl;

	

	/*
	for (int i = 1; i < players.size(); i++) {
		if (pairOrThreeKind(players.at(i)) == 4) {
			output = "Full house";
			fullHouseFrequency += 1;
			//twoPairFrequency += 1;
			onePairFrequency += 1;
			threeOfAKindFrequency += 1;
		}

		else if (isStraight(players.at(i)) == true) {
			output = " straight";
			straightFrequency += 1;
		}
		else if (pairOrThreeKind(players.at(i)) == 3) {
			output = " 3kind";
			threeOfAKindFrequency += 1;
			//onePairFrequency += 1;
		}
		else if (pairOrThreeKind(players.at(i)) == 2) {
			output = " 2pair";
			twoPairFrequency += 1;
			onePairFrequency += 2;
		}
		else if (pairOrThreeKind(players.at(i)) == 1) {
			output = " pair";
			onePairFrequency += 1;
		}

		else {
			output = " N/A";
			highCardFrequency += 1;
		}
		statsFile << printHand(players.at(i)) << "," << output << endl;
	}

	statsFile << endl << endl;

	*/


}

 

