#include "pokerGame.h"
#include <iostream>
#include <fstream>
#include <unordered_map>


void pokerGame::addCard(vector<Card>& hand, Card cardToAdd) {
	hand.push_back(cardToAdd);
}

/*
void pokerGame::sortPlayerHand()
{

	
	
	for (int i = 0; i < players.at(0).size() - 1; i++) {
		for (int j = 0; j < players.at(0).size() - i - 1; j++) {
			if (players.at(0).at(j).getValue() > players.at(0).at(j+1).getValue()) {

				
				swap(players.at(0).at(j), players.at(0).at(j+1));
				

			}
		}
	}
}
*/

//borrowed shell sort implementation from geeksforgeeks https://www.geeksforgeeks.org/shellsort/
void pokerGame::sortPlayerHand() {
	int gap, j, k;
	for (gap = players[0].size() / 2; gap > 0; gap = gap / 2) {        //initially gap = n/2,
			//decreasing by gap / 2
		for (j = gap; j < players[0].size(); j++) {
			for (k = j - gap; k >= 0; k -= gap) {
				if (players[0][k + gap].getValue() >= players[0][k].getValue())
					break;
				else
					swap(players[0][k + gap], players[0][k]);
			}
		}
	}

}

/*
void pokerGame::sortOthersHand()
{

	for (int k = 1; k < players.size(); k++) {
		for (int i = 0; i < players.at(k).size() - 1; i++) {
			for (int j = 0; j < players.at(0).size() - i - 1; j++) {
				if (players.at(k).at(j).getValue() > players.at(k).at(j + 1).getValue()) {

					
					swap(players.at(k).at(j), players.at(k).at(j + 1));


				}
			}
		}
	}
}
*/


void pokerGame::sortOthersHand() {
	//4 levels of for loops....yay....
	for (int i = 1; i < players.size(); i++) {

		int gap, j, k;
		for (gap = players[i].size() / 2; gap > 0; gap = gap / 2) {        //initially gap = n/2,
			//decreasing by gap / 2
			for (j = gap; j < players[0].size(); j++) {
				for (k = j - gap; k >= 0; k -= gap) {
					if (players[i][k + gap].getValue() >= players[i][k].getValue())
						break;
					else
						swap(players[i][k + gap], players[i][k]);
				}
			}
		}
		}

	}



void pokerGame::sortPlayerHandRankings()
{



	for (int i = 0; i < playerHandTypes.size() - 1; i++) {
		for (int j = 0; j < playerHandTypes.size() - i - 1; j++) {
			if (playerHandTypes.at(j) > playerHandTypes.at(j+1)   ) {


				swap(playerHandTypes.at(j), playerHandTypes.at(j + 1));


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

string pokerGame::getStringValueRank(handTypes handRank)
{
	switch (handRank)
	{
	case pokerGame::highCard:
		return "hCard";
		break;
	case pokerGame::onePair:
		return "1Pair";
		break;
	case pokerGame::twoPair:
		return "2Pair";
		break;
	case pokerGame::threeKind:
		return "3Kind";
		break;
	case pokerGame::straight:
		return "straight";
		break;
	case pokerGame::flush:
		return "flush";
		break;
	case pokerGame::fullhouse:
		return "fullHouse";
		break;
	case pokerGame::fourKind:
		return "4kind";
		break;
	case pokerGame::straightFlush:
		return "straightFlush";
		break;
	case pokerGame::royalFlush:
		return "royalFlush";
		break;
	default:
		break;
	}
}


int pokerGame::getCountFromRankString(string HandRankString)
{
	if (HandRankString == "hCard") {
		return highCardWins;

	}

	else if (HandRankString == "1Pair") {
		return onePairWins;

	}
	else if (HandRankString == "2Pair") {
		return twoPairWins;
	}
	else if (HandRankString == "3Kind") {
		return threeOfAKindWins;
	}
	else if (HandRankString == "straight") {
		return straightWins;
	}
	else if (HandRankString == "flush") {
		return flushWins;
	}
	else if (HandRankString == "fullhouse") {
		return fullHouseWins;

	}
	else if (HandRankString == "4kind") {
		return fourkindWins;
	}
	else if (HandRankString == "straightFlush") {
		return straightFlushWins;
	}
	else if (HandRankString == "royalFlush") {
		return royalFlushWins;
	}
}

int pokerGame::evalHighCard(vector<Card> &hand, int rightOffset)
{

	int highCardVal = 0;

	if (hand.at(0).getValue() == Card::ace && rightOffset == 0) { //1st iteration want to check for aces before any other card
		return 15; //can be any arbitary value higher than the value of king which is 13
	}
	else {
		if (hand.at(0).getValue() == Card::ace ) {
			
			highCardVal = hand.at(  ((hand.size() - 1)  - rightOffset) + 1 ).getValue(); // special case since we needed to evaluate ace high 1st in this situation
			return highCardVal;
		}
		else {
			highCardVal = hand.at((hand.size() - 1) - rightOffset).getValue(); // best value high card should be rightmost card as hand already sorted
			return highCardVal;
		}
	}


}

int pokerGame::getHighCardIndex(int offsetFromRightOfHand)
{
	vector<int> highCardValues{0,0,0,0,0,0};

	for (int i = 0; i < players.size(); i++) {
		if (playerHandTypes.at(i) == highCard) {
			highCardValues.at(i) = evalHighCard(players.at(i), offsetFromRightOfHand); //if they are not a high card leave value at 0. 
		}
	}

	int highCardPlayerIndex = -1;
	int secondHighestCardPlayerIndex = -1;
	int highestCardValue = -1;
	int secondHighestCardValue = -2;
	for (int i = 0; i < players.size(); i++) {
		if (highCardValues.at(i) >= highestCardValue) {
			highestCardValue = highCardValues.at(i);
			highCardPlayerIndex = i;
		}
		else if (highCardValues.at(i) >= secondHighestCardValue) {
			secondHighestCardValue = highCardValues.at(i);
			secondHighestCardPlayerIndex = i;
		}
	}

	if (secondHighestCardPlayerIndex != highCardPlayerIndex) { //if there is no tie
		return highCardPlayerIndex;
	}

	else {
		getHighCardIndex(offsetFromRightOfHand + 1); //this code has officially gone into spaghetti code recursion territory. Needs to be a + not minus. Counter intuitive spaghetti code
	}

	
	
}

int pokerGame::evalOnePair(vector<Card> &hand,int rightOffset)
{
	/*
	int highPairCardVal = 0;

	if (hand.at(0).getValue() == Card::ace && hand.at(1).getValue() == Card::ace && rightOffset == 0) { //1st iteration want to check for aces before any other card
		return 15; //can be any arbitary value higher than the value of king which is 13
	}
	else {
		if (hand.at(0).getValue() == Card::ace && hand.at(1).getValue() == Card::ace) {

			highPairCardVal = hand.at(((hand.size() - 2) - rightOffset) + 2).getValue(); // need to account for the fact the 1st 'real' two highest cards in this hand were the ace pairs
			return highPairCardVal;
		}
		else {
			highPairCardVal = hand.at((hand.size() - 2) - rightOffset).getValue(); // best value pair card should be rightmost card as hand already sorted. Can start at leftmost card in the pair
			return highPairCardVal;
		}
	}
	*/
	return 1;
}

int pokerGame::evalStraight(vector<Card> &hand)
{
	int highCardVal = 0;

	if (hand.at(0).getValue() == Card::ace && hand.at(4).getValue() == Card::king) { //ace high straight
		return 15; //can be any arbitary value higher than the value of king which is 13
	}

	else {
		highCardVal = hand.at((hand.size() - 1)).getValue(); // best value card in straight should be on right most side
		return highCardVal;
	}
	
	
}

int pokerGame::getHighPairIndex(int offsetFromRightOfHand)
{
	
	vector<int> highestPairPerPlayer{ 0,0,0,0,0,0 };
	vector<int> playerUniqueCardValues;

	for (int i = 0; i < players.size(); i++) { //iterate through all sorted players hand
		for (int j = 0; j < players.at(i).size(); j++) { //iterate through players hands right to left since hand is sorted. Looking for pair value
			if (find(playerUniqueCardValues.begin(), playerUniqueCardValues.end(), players.at(i).at(j).getValue())     != playerUniqueCardValues.end()) { //element has occured before so its a pair
				highestPairPerPlayer.insert(highestPairPerPlayer.begin() + i, players.at(i).at(j).getValue());
			}
			else {
				playerUniqueCardValues.push_back(players.at(i).at(j).getValue()); //value has not occured yet add it to unique val vector

			}
		}
		playerUniqueCardValues.clear();
	}


	


	int highPairPlayerIndex = -1;
	int secondHighestPairPlayerIndex = -1;
	int highestPairValue = -1;
	int secondHighestPairValue = -2;

	for (int i = 0; i < highestPairPerPlayer.size(); i++) {
		if (highestPairPerPlayer.at(i) == 1) {//ace
			highestPairValue = highestPairPerPlayer.at(i);
			highPairPlayerIndex = i;
		}
		else if (highestPairPerPlayer.at(i) >= highestPairValue) {
			highestPairValue = highestPairPerPlayer.at(i);
			highPairPlayerIndex = i;
		}
		else if (highestPairPerPlayer.at(i) >= secondHighestPairValue) {
			secondHighestPairValue = highestPairPerPlayer.at(i);
			secondHighestPairPlayerIndex = i;
		}
	}

	if (secondHighestPairPlayerIndex != highPairPlayerIndex) { //if there is no tie in pairs
		return highPairPlayerIndex;
	}

	else { // is a tie of pairs so now need to compare highest value remaining cards that are not pairrs
		//where I got the code for removing specific elements from a vector https://stackoverflow.com/questions/7631996/remove-an-element-from-a-vector-by-value-c
		vector<vector<Card>> handsWithPairRemoved;

		vector<Card> playerHandCopy = players.at(0);
		vector <Card> otherPlayer1Copy = players.at(1);
		vector <Card> otherPlayer2Copy = players.at(2);
		vector <Card> otherPlayer3Copy = players.at(3);
		vector <Card> otherPlayer4Copy = players.at(4);
		vector <Card> otherPlayer5Copy = players.at(5);

		handsWithPairRemoved.push_back(playerHandCopy);
		handsWithPairRemoved.push_back(otherPlayer1Copy);
		handsWithPairRemoved.push_back(otherPlayer2Copy);
		handsWithPairRemoved.push_back(otherPlayer3Copy);
		handsWithPairRemoved.push_back(otherPlayer4Copy);
		handsWithPairRemoved.push_back(otherPlayer5Copy);


		
		for (int i = 0; i < handsWithPairRemoved.size(); i++) {
			for (int j = 0; i < handsWithPairRemoved.size(); j++) {
				if (highestPairPerPlayer.at(i) != 0 && handsWithPairRemoved.at(i).at(j).getValue() == highestPairPerPlayer.at(i)) {
					handsWithPairRemoved.at(i).erase(handsWithPairRemoved.at(i).begin() + j);
				}
			}
			//handsWithPairRemoved.at(i).erase(   remove_if(handsWithPairRemoved.at(i).begin(), handsWithPairRemoved.at(i).end(), highestPairPerPlayer.at(i))   , handsWithPairRemoved.at(i).end()); //make copies of hands and remove their pairs
			//handsWithPairRemoved.at(i).erase(   remove_if(handsWithPairRemoved.at(i).begin(), handsWithPairRemoved.at(i).end(), isPairsInVector(highestPairPerPlayer.at(i),handsWithPairRemoved.at(i))  )   , handsWithPairRemoved.at(i).end());
		}

		for (int i = 0; i < highestPairPerPlayer.size(); i++) { //reset value of all hands
			highestPairPerPlayer.at(i) = 0;

		}
		

		for (int i = 0; i < players.size(); i++) {
			if (playerHandTypes.at(i) == onePair) { // only want to consider hands that had pairs
				highestPairPerPlayer.at(i) = evalHighCard(handsWithPairRemoved.at(i), offsetFromRightOfHand); //if they are not a high card leave value at 0. 
			}
		}

		int highCardPlayerIndex = -1;
		int secondHighestCardPlayerIndex = -1;
		int highestCardValue = -1;
		int secondHighestCardValue = -2;
		for (int i = 0; i < players.size(); i++) {
			if (highestPairPerPlayer.at(i) > highestCardValue) { // > or >= ?
				highestCardValue = highestPairPerPlayer.at(i);
				highCardPlayerIndex = i;
			}
			else if (highestPairPerPlayer.at(i) > secondHighestCardValue) {
				secondHighestCardValue = highestPairPerPlayer.at(i);
				secondHighestCardPlayerIndex = i;
			}
		}

		if (secondHighestCardPlayerIndex != highCardPlayerIndex) { //if there is no tie
			return highCardPlayerIndex;
		}

		else {
			getHighPairIndex(offsetFromRightOfHand + 1); //this code has officially gone into spaghetti code recursion territory. Needs to be a + not minus. Counter intuitive spaghetti code
		}
	}
	
	



	

}

int pokerGame::getHighTwoPairIndex(int offsetFromRightOfHand)
{
	int highPairPlayerIndex = -1;
	int secondHighestPairPlayerIndex = -1;
	int highestPairValue = -1;
	int secondHighestPairValue = -2;

	vector<int> highestPairPerPlayer{ 0,0,0,0,0,0 };
	vector<int> playerUniqueCardValues;

	for (int i = 0; i < players.size(); i++) { //iterate through all sorted players hand
		for (int j = 0; j < players.at(i).size(); j++) { //iterate through players hands right to left since hand is sorted. Looking for pair value
			if (find(playerUniqueCardValues.begin(), playerUniqueCardValues.end(), players.at(i).at(j).getValue()) != playerUniqueCardValues.end()) { //element has occured before so its a pair
				highestPairPerPlayer.insert(highestPairPerPlayer.begin() + i, players.at(i).at(j).getValue());
			}
			else {
				playerUniqueCardValues.push_back(players.at(i).at(j).getValue()); //value has not occured yet add it to unique val vector

			}
		}
		playerUniqueCardValues.clear();
	}





	

	for (int i = 0; i < highestPairPerPlayer.size(); i++) {
		if (highestPairPerPlayer.at(i) == 1) {//ace
			highestPairValue = highestPairPerPlayer.at(i);
			highPairPlayerIndex = i;
		}
		else if (highestPairPerPlayer.at(i) >= highestPairValue) {
			highestPairValue = highestPairPerPlayer.at(i);
			highPairPlayerIndex = i;
		}
		else if (highestPairPerPlayer.at(i) >= secondHighestPairValue) {
			secondHighestPairValue = highestPairPerPlayer.at(i);
			secondHighestPairPlayerIndex = i;
		}
	}

	if (secondHighestPairPlayerIndex != highPairPlayerIndex) { //if there is no tie in pairs
		return highPairPlayerIndex;
	}

	else { // is a tie of pairs so now need to compare 2nd set of pairs
		//where I got the code for removing specific elements from a vector https://stackoverflow.com/questions/7631996/remove-an-element-from-a-vector-by-value-c
		vector<vector<Card>> handsWithHighestPairRemoved;

		vector<Card> playerHandCopy = players.at(0);
		vector <Card> otherPlayer1Copy = players.at(1);
		vector <Card> otherPlayer2Copy = players.at(2);
		vector <Card> otherPlayer3Copy = players.at(3);
		vector <Card> otherPlayer4Copy = players.at(4);
		vector <Card> otherPlayer5Copy = players.at(5);

		handsWithHighestPairRemoved.push_back(playerHandCopy);
		handsWithHighestPairRemoved.push_back(otherPlayer1Copy);
		handsWithHighestPairRemoved.push_back(otherPlayer2Copy);
		handsWithHighestPairRemoved.push_back(otherPlayer3Copy);
		handsWithHighestPairRemoved.push_back(otherPlayer4Copy);
		handsWithHighestPairRemoved.push_back(otherPlayer5Copy);




		for (int i = 0; i < handsWithHighestPairRemoved.size(); i++) {
			for (int j = 0; i < handsWithHighestPairRemoved.size(); j++) {
				if (highestPairPerPlayer.at(i) != 0 && handsWithHighestPairRemoved.at(i).at(j).getValue() == highestPairPerPlayer.at(i)) {
					handsWithHighestPairRemoved.at(i).erase(handsWithHighestPairRemoved.at(i).begin() + j);
				}
			}

			for (int i = 0; i < highestPairPerPlayer.size(); i++) { //reset value of all hands
				highestPairPerPlayer.at(i) = 0;

			}


			//Get 2nd highest pair and try again ...
			for (int i = 0; i < handsWithHighestPairRemoved.size(); i++) { //iterate through all sorted players hand
				for (int j = 0; j < handsWithHighestPairRemoved.at(i).size(); j++) { //iterate through players hands right to left since hand is sorted. Looking for pair value
					if (find(playerUniqueCardValues.begin(), playerUniqueCardValues.end(), players.at(i).at(j).getValue()) != playerUniqueCardValues.end()) { //element has occured before so its a pair
						highestPairPerPlayer.insert(highestPairPerPlayer.begin() + i, players.at(i).at(j).getValue());
					}
					else {
						playerUniqueCardValues.push_back(players.at(i).at(j).getValue()); //value has not occured yet add it to unique val vector

					}
				}
				playerUniqueCardValues.clear();
			}


			highPairPlayerIndex = -1;
			secondHighestPairPlayerIndex = -1;
			highestPairValue = -1;
			secondHighestPairValue = -2;
			for (int i = 0; i < players.size(); i++) {
				if (highestPairPerPlayer.at(i) > highestPairValue) { // > or >= ?
					highestPairValue = highestPairPerPlayer.at(i);
					highPairPlayerIndex = i;
				}
				else if (highestPairPerPlayer.at(i) > secondHighestPairValue) {
					secondHighestPairValue = highestPairPerPlayer.at(i);
					secondHighestPairPlayerIndex = i;
				}
			}

			if (secondHighestPairPlayerIndex != highPairPlayerIndex) { //if there is no tie between 2nd pair
				return highPairPlayerIndex;
			}

			else {

				for (int i = 0; i < players.size(); i++) {
					if (playerHandTypes.at(i) == twoPair) { // only want to consider hands that had pairs
						highestPairPerPlayer.at(i) = evalHighCard(handsWithHighestPairRemoved.at(i), offsetFromRightOfHand); //if they are not a high card leave value at 0. 
					}
				}


				for (int i = 0; i < highestPairPerPlayer.size(); i++) {
					if (highestPairPerPlayer.at(i) == 1) {//ace
						highestPairValue = highestPairPerPlayer.at(i);
						highPairPlayerIndex = i;
					}
					else if (highestPairPerPlayer.at(i) >= highestPairValue) {
						highestPairValue = highestPairPerPlayer.at(i);
						highPairPlayerIndex = i;
					}
					else if (highestPairPerPlayer.at(i) >= secondHighestPairValue) {
						secondHighestPairValue = highestPairPerPlayer.at(i);
						secondHighestPairPlayerIndex = i;
					}
				}

				if (secondHighestPairPlayerIndex != highPairPlayerIndex) { //if there is no tie in pairs
					return highPairPlayerIndex;
				}
				else {
					return -1;
				}

				
			}
		}

	}

		
	
}

int pokerGame::getHighThreeKindIndex()
{
	vector<int> highestThreeKindPlayer{ 0,0,0,0,0,0 };
	vector<int> timeCardOccuredPerPlayer{ 0,0,0,0,0,0 };
	vector<int> playerUniqueCardValues;

	for (int i = 0; i < players.size(); i++) { //iterate through all sorted players hand
		for (int j = 0; j < players.at(i).size(); j++) { //iterate through players hands right to left since hand is sorted. Looking for pair value
			if (find(playerUniqueCardValues.begin(), playerUniqueCardValues.end(), players.at(i).at(j).getValue()) != playerUniqueCardValues.end() && timeCardOccuredPerPlayer.at(i) == 2) {//2 previous 3kind elem already occured
				highestThreeKindPlayer.insert(highestThreeKindPlayer.begin() + i, players.at(i).at(j).getValue());
			}
			else if (find(playerUniqueCardValues.begin(), playerUniqueCardValues.end(), players.at(i).at(j).getValue()) != playerUniqueCardValues.end()) { //element has occured before so its a pair
				timeCardOccuredPerPlayer.at(i) += 1;
			}
			else {
				playerUniqueCardValues.push_back(players.at(i).at(j).getValue()); //value has not occured yet add it to unique val vector

			}
		}
		playerUniqueCardValues.clear();
	}





	int highPairPlayerIndex = -1;
	int secondHighestPairPlayerIndex = -1;
	int highestPairValue = -1;
	int secondHighestPairValue = -2;

	for (int i = 0; i < highestThreeKindPlayer.size(); i++) {
		if (highestThreeKindPlayer.at(i) == 1) {//ace
			highestPairValue = highestThreeKindPlayer.at(i);
			highPairPlayerIndex = i;
		}
		else if (highestThreeKindPlayer.at(i) >= highestPairValue) {
			highestPairValue = highestThreeKindPlayer.at(i);
			highPairPlayerIndex = i;
		}
		else if (highestThreeKindPlayer.at(i) >= secondHighestPairValue) {
			secondHighestPairValue = highestThreeKindPlayer.at(i);
			secondHighestPairPlayerIndex = i;
		}
	}

	if (secondHighestPairPlayerIndex != highPairPlayerIndex) { //if there is no tie in 3 of a kind
		return highPairPlayerIndex;
	}

	
}

int pokerGame::getHighFourKindIndex()
{
	
		vector<int> highestFourKindPlayer{ 0,0,0,0,0,0 };
		vector<int> timeCardOccuredPerPlayer{ 0,0,0,0,0,0 };
		vector<int> playerUniqueCardValues;

		for (int i = 0; i < players.size(); i++) { //iterate through all sorted players hand
			for (int j = 0; j < players.at(i).size(); j++) { //iterate through players hands right to left since hand is sorted. Looking for pair value
				if (find(playerUniqueCardValues.begin(), playerUniqueCardValues.end(), players.at(i).at(j).getValue()) != playerUniqueCardValues.end() && timeCardOccuredPerPlayer.at(i) == 3) {//3 previous 4kind elem already occured
					highestFourKindPlayer.insert(highestFourKindPlayer.begin() + i, players.at(i).at(j).getValue());
				}
				else if (find(playerUniqueCardValues.begin(), playerUniqueCardValues.end(), players.at(i).at(j).getValue()) != playerUniqueCardValues.end()) { //element has occured before so its a pair
					timeCardOccuredPerPlayer.at(i) += 1;
				}
				else {
					playerUniqueCardValues.push_back(players.at(i).at(j).getValue()); //value has not occured yet add it to unique val vector

				}
			}
			playerUniqueCardValues.clear();
		}





		int highPairPlayerIndex = -1;
		int secondHighestPairPlayerIndex = -1;
		int highestPairValue = -1;
		int secondHighestPairValue = -2;

		for (int i = 0; i < highestFourKindPlayer.size(); i++) {
			if (highestFourKindPlayer.at(i) == 1) {//ace
				highestPairValue = highestFourKindPlayer.at(i);
				highPairPlayerIndex = i;
			}
			else if (highestFourKindPlayer.at(i) >= highestPairValue) {
				highestPairValue = highestFourKindPlayer.at(i);
				highPairPlayerIndex = i;
			}
			else if (highestFourKindPlayer.at(i) >= secondHighestPairValue) {
				secondHighestPairValue = highestFourKindPlayer.at(i);
				secondHighestPairPlayerIndex = i;
			}
		}

		if (secondHighestPairPlayerIndex != highPairPlayerIndex) { //if there was a 4 kind tie something has gone very wrong....
			return highPairPlayerIndex;
		}
}

int pokerGame::getHighStraightIndex()
{
	vector<int> highStraightValues{ 0,0,0,0,0,0 };

	for (int i = 0; i < players.size(); i++) {
		if (playerHandTypes.at(i) == straight) {
			highStraightValues.at(i) = evalStraight(players.at(i)); //if they are not a high card leave value at 0. 
		}
	}

	int highCardPlayerIndex = -1;
	int secondHighestCardPlayerIndex = -2;
	int highestCardValue = -1;
	int secondHighestCardValue = -2;
	for (int i = 0; i < players.size(); i++) {
		if (highStraightValues.at(i) >= highestCardValue) {
			highestCardValue = highStraightValues.at(i);
			highCardPlayerIndex = i;
		}
		else if (highStraightValues.at(i) >= secondHighestCardValue) {
			secondHighestCardValue = highStraightValues.at(i);
			secondHighestCardPlayerIndex = i;
		}
	}

	if (secondHighestCardPlayerIndex != highCardPlayerIndex) { //if there is no tie
		return highCardPlayerIndex;
	}

	else {
		return -1; //tie
	}
}

int pokerGame::getFullHouseIndex()
{
	int fullHouseIndex = getHighThreeKindIndex(); //full house ties broken by comparing 3 kind cards and impossible for both players to have same three kind so just call three kind method
	return fullHouseIndex;
}

int pokerGame::getHighFlushIndex()
{
	vector<int> highFlushValues{ 0,0,0,0,0,0 };

	for (int i = 0; i < players.size(); i++) {
		if (playerHandTypes.at(i) == flush) {
			highFlushValues.at(i) = evalHighCard(players.at(i),0); 
		}
	}

	int highCardPlayerIndex = -1;
	int secondHighestCardPlayerIndex = -2;
	int highestCardValue = -1;
	int secondHighestCardValue = -2;
	for (int i = 0; i < players.size(); i++) {
		if (highFlushValues.at(i) >= highestCardValue) {
			highestCardValue = highFlushValues.at(i);
			highCardPlayerIndex = i;
		}
		else if (highFlushValues.at(i) >= secondHighestCardValue) {
			secondHighestCardValue = highFlushValues.at(i);
			secondHighestCardPlayerIndex = i;
		}
	}

	if (secondHighestCardPlayerIndex != highCardPlayerIndex) { //if there is no tie
		return highCardPlayerIndex;
	}

	else {
		return -1; //tie
	}
}

int pokerGame::getStraightFlushIndex()
{
	vector<int> highStraightFlushValues{ 0,0,0,0,0,0 };

	for (int i = 0; i < players.size(); i++) {
		if (playerHandTypes.at(i) == highCard) {
			highStraightFlushValues.at(i) = evalHighCard(players.at(i), 0); //if they are not a high card leave value at 0. 
		}
	}

	int highCardPlayerIndex = -1;
	int secondHighestCardPlayerIndex = -1;
	int highestCardValue = -1;
	int secondHighestCardValue = -2;
	for (int i = 0; i < players.size(); i++) {
		if (highStraightFlushValues.at(i) >= highestCardValue) {
			highestCardValue = highStraightFlushValues.at(i);
			highCardPlayerIndex = i;
		}
		else if (highStraightFlushValues.at(i) >= secondHighestCardValue) {
			secondHighestCardValue = highStraightFlushValues.at(i);
			secondHighestCardPlayerIndex = i;
		}
	}

	if (secondHighestCardPlayerIndex != highCardPlayerIndex) {
		return highCardPlayerIndex;
	}

	else {
		return -1;
	}

	


}

bool pokerGame::isPairsInVector(int pairVal, vector<Card> hand) {

	for (int i = 0; i < hand.size(); i++) {
		if (hand.at(i).getValue() == pairVal) {
			return true;
		}
	}
	return false;
}



void pokerGame::incrementCardRank(handTypes &hand, bool isTied) 
{
	if (isTied == false) {
		playerWins += 1;

		switch (hand)
		{
		case handTypes::highCard:
			highCardWins++;
			//playerHighCardFrequency++;
			//return "hCard";
			break;
		case handTypes::onePair:
			onePairWins++;
			//playerOnePairFrequency++;
			//return "1Pair";
			break;
		case handTypes::twoPair:
			twoPairWins++;
			//playerTwoPairFrequency++;
			//return "2Pair";
			break;
		case handTypes::threeKind:
			threeOfAKindWins++;
			//playerThreeOfAKindFrequency++;
			//return "3Pair";
			break;
		case handTypes::straight:
			straightWins++;
			//playerStraightFrequency++;
			//return "straight";
			break;
		case handTypes::flush:
			flushWins++;
			//playerFlushFrequency++;
			//return "flush";
			break;
		case handTypes::fullhouse:
			fullHouseWins++;
			//playerFullHouseFrequency++;
			//return "fullHouse";
			break;
		case handTypes::fourKind:
			fourkindWins++;
			//playerFourKindFrequency++;
			//return "4kind";
			break;
		case handTypes::straightFlush:
			straightFlushWins++;
			//playerStraightFlushFrequency++;
			break;
		case handTypes::royalFlush:
			royalFlushWins++;
			break;
		default:
			break;
		}
	}
	else {
		//not implemented
		testInt++;
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
			playerHandString +=  (getStringValueCard(deckCard.getValue()));
			playerHandString += "S ";
			break;
		case Card::Hearts:
			playerHandString += (getStringValueCard(deckCard.getValue()));
			playerHandString += "H ";
			break;
		case Card::Diamonds:
			playerHandString += (getStringValueCard(deckCard.getValue()));
			playerHandString += "D ";
			break;
		case Card::Clubs:
			playerHandString += (getStringValueCard(deckCard.getValue()));
			playerHandString += "D ";
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
		int handPairCount = 0;
		int handThreeOfKindCount = 0;
		int twoPairCount = 0;
		int fourkindCount = 0;
		int fullHouseCount = 0;
		
		/*
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
		*/

		
			if ((hand.at(0).getValue() == hand.at(3).getValue()) || (hand.at(1).getValue() == hand.at(4).getValue())) {
				fourkindCount++;
			}
			if ((hand.at(0).getValue() == hand.at(1).getValue() && hand.at(1).getValue() == hand.at(2).getValue() && hand.at(3).getValue() == hand.at(4).getValue())
				|| (hand.at(0).getValue() == hand.at(1).getValue() && hand.at(2).getValue() == hand.at(3).getValue() && hand.at(3).getValue() == hand.at(4).getValue())) 
				{
					fullHouseCount++;

				}

			if ( (hand.at(0).getValue() == hand.at(2).getValue())    ||  (hand.at(1).getValue() == hand.at(3).getValue()) || (hand.at(2).getValue() == hand.at(4).getValue() )    ) { //3kind
				handThreeOfKindCount++;
			}

			if (((hand.at(0).getValue() == hand.at(1).getValue()) && (hand.at(2).getValue() == hand.at(3).getValue()))
				||
				(hand.at(1).getValue() == hand.at(2).getValue()) && (hand.at(3).getValue() == hand.at(4).getValue()) //2 pair

				||
				(hand.at(0).getValue() == hand.at(1).getValue()) && (hand.at(3).getValue() == hand.at(4).getValue()))


				{
					//handPairCount += 2;
				twoPairCount += 1;
				}
			if ( (hand.at(0).getValue() == hand.at(1).getValue()) || hand.at(1).getValue() == hand.at(2).getValue() || // 1 pair
				hand.at(2).getValue() == hand.at(3).getValue() || hand.at(3).getValue() == hand.at(4).getValue()) 
			{
				handPairCount += 1;
			}
				
				
				

	

		
		



		



		if (fourkindCount == 1) { //4kind
			return 5;
		}
		else if (fullHouseCount == 1) { //full house
			return 4;
		}
		else if (handThreeOfKindCount == 1) { //3kind
			return 3;
		}
		else if (twoPairCount == 1) { // 2pair
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
	logFile << "Total number of hands dealt is " << totalHandsDealt << "\n";;
	logFile << "Total number of High card occurences is " << highCardFrequency << " and its occurence percentage is " << ((highCardFrequency / float(totalHandsDealt))) * 100 << "%" << " total number of high card wins is " 
		<< highCardWins << " and its win percentage is " 
		<< (highCardWins/float(playerHighCardFrequency))*100 << " %" << "\n";

	logFile << " Total number of one pair occurences is " << onePairFrequency << " and its occurence percentage is " << ((onePairFrequency / float(totalHandsDealt))) * 100 << "%" << " total number of one pair wins is " 
		<< onePairWins << "and its winning percentage is "
		<< (onePairWins / float(playerOnePairFrequency)) * 100 << " %" << "\n";

	logFile << "Total number of two pairs occurences is " << twoPairFrequency << " and its occurence percentage is " << ((twoPairFrequency / float(totalHandsDealt))) * 100 << "%" <<  " and its winning percentage is " 
		<< (twoPairWins / float(playerTwoPairFrequency)) * 100 << " %" << "\n";

	logFile << "Total number of three of a kind occurences is " << threeOfAKindFrequency << " and its occurence percentage is " << ((threeOfAKindFrequency / float(totalHandsDealt))) * 100 << "%" << " and its winning percentage is " 
		<< (threeOfAKindWins / float(playerThreeOfAKindFrequency)) * 100 << " %" << "\n";


	if (playerStraightFrequency == 0) {
		logFile << "Total number of straight occurences is " << straightFrequency << " and its occurence percentage is " << ((straightFrequency / float(totalHandsDealt))) * 100 << "%" << " 1st player did not get any flushes" << endl;
	}

	else {
		logFile << "Total number of straight occurences is " << straightFrequency << " and its occurence percentage is " << ((straightFrequency / float(totalHandsDealt))) * 100 << "%" << " and its winning percentage is "
			<< (straightWins / float(playerStraightFrequency)) * 100 << " %" << "\n";
	}


	if (playerFlushFrequency == 0) {
		logFile << "Total number of flush occurences is " << flushFrequency << " and its occurence percentage is " << ((flushFrequency / float(totalHandsDealt))) * 100 << "%" << " 1st player did not have any flushes" << endl;

	}
	else {
		logFile << "Total number of flush occurences is " << flushFrequency << " and its occurence percentage is " << ((flushFrequency / float(totalHandsDealt))) * 100 << "%" << " and its winning percentage is "
			<< (flushWins / float(playerFlushFrequency)) * 100 << " %" << "\n";
	}


	if (playerFullHouseFrequency == 0) {
		logFile << "Total number of full house occurences is " << fullHouseFrequency << " and its occurence percentage is " << ((fullHouseFrequency / float(totalHandsDealt))) * 100 << "%" << " 1st player did not have any full house" << endl;
			
	}
	else {
		logFile << "Total number of full house occurences is " << fullHouseFrequency << " and its occurence percentage is " << ((fullHouseFrequency / float(totalHandsDealt))) * 100 << "%" << " and its winning percentage is "
			<< (fullHouseWins / float(playerFullHouseFrequency)) * 100 << " %" << "\n";
	}



	if (playerFourKindFrequency == 0) {
		logFile << "Total number of 4kind occurences is " << fourKindFrequency << " and its occurence percentage is " << ((fourKindFrequency / float(totalHandsDealt))) * 100 << "%" <<
			" player did not have any four of a kinds so no win percentage" << "\n";
			
	}
	else {
		logFile << "Total number of 4kind occurences is " << fourKindFrequency << " and its occurence percentage is " << ((fourKindFrequency / float(totalHandsDealt))) * 100 << "%" << " and its winning percentage is "
			<< (fourkindWins / float(playerFourKindFrequency)) * 100 << " %" << "\n";
	}

	if (playerStraightFlushFrequency == 0) {
		logFile << "Total number of straight flush occurences is " << straightFlushFrequency << " and its occurence percentage is " << ((straightFlushFrequency / float(totalHandsDealt))) * 100 << "%" <<
			" player did not have any straight flushes so no win percentage " << "\n";
	}
	else {
		logFile << "Total number of straight flush occurences is " << straightFlushFrequency << " and its occurence percentage is " << ((straightFlushFrequency / float(totalHandsDealt))) * 100 << "%" << " and its winning percentage is "
			<< (straightFlushWins / float(playerStraightFrequency)) * 100 << " %" << "\n";
	}

	
	if (playerRoyalFlushFrequency == 0) {

		logFile << "Total number of royal flush occurences is " << royalFlushFrequency << " and its occurence percentage is " << ((royalFlushFrequency / float(totalHandsDealt))) * 100 << "%" <<
			" Player did not have any royal flushes so no win percentage " << "\n";
			
	}

	
	else {

		logFile << "Total number of royal flush occurences is " << royalFlushFrequency << " and its occurence percentage is " << ((royalFlushFrequency / float(totalHandsDealt))) * 100 << "%" << " and its winning percentage is "
			<< (royalFlushWins / float(playerRoyalFlushFrequency)) * 100 << " %" << "\n";
	}



	
	logFile << "Player won "<< playerWins << " rounds out of " << totalHandsDealt/6 << " simulated rounds. Overall win percentage for player is " << (playerWins /  (float(totalHandsDealt)/6)) * 100 << "%" << "\n";

}

void pokerGame::outputStatsplayer(ofstream& statsFile, int playerHandNum, int otherHandNum)
{
	sortPlayerHand();
	string output;
	//statsFile << "Player Hand " << playerHandNum << " iteration " << otherHandNum << endl;
	if (isRoyalFlush(players.at(0)) == true) {
		output = "Royal Flush";
		//royalFlushFrequency += 1;
		//playerFlushFrequency++;
		playerHandTypes.at(0) = handTypes::royalFlush;
	}

	else if (isStraighFlush(players.at(0)) == true) {
		output = "Straight Flush";
		//straightFlushFrequency += 1;
		//playerStraightFlushFrequency++;
		playerHandTypes.at(0) = handTypes::straightFlush;
	}
	else if (pairOrThreeKind(players.at(0)) == 5) {
		output = " 4Kind";
		//fourKindFrequency+=1;
		//playerFourKindFrequency++;
		playerHandTypes.at(0) = handTypes::fourKind;
	}

	else if (isFlush(players.at(0)) == true) {
		output = "Flush";
		//flushFrequency += 1;
		//playerFlushFrequency++;
		playerHandTypes.at(0) = handTypes::flush;
	}
	
	else if (pairOrThreeKind(players.at(0)) == 4) {
		output = " Full House";
		//fullHouseFrequency += 1;
		//playerFullHouseFrequency++;
		playerHandTypes.at(0) = handTypes::fullhouse;
		//twoPairFrequency += 1;
		//onePairFrequency += 1;
		//threeOfAKindFrequency += 1;
	}
	else if (isStraight(players.at(0)) == true) {
		output = " straight";
		//straightFrequency += 1;
		//playerStraightFrequency++;
		playerHandTypes.at(0) = handTypes::straight;
	}
	
	else if (pairOrThreeKind(players.at(0)) == 3) {
		output = " 3kind";
		//threeOfAKindFrequency += 1;
		//playerThreeOfAKindFrequency++;

		playerHandTypes.at(0) = handTypes::threeKind;
		//onePairFrequency += 1;
	}
	
	
	else if (pairOrThreeKind(players.at(0)) == 2) {
		output = " 2pair";
		//twoPairFrequency += 1;
		//playerTwoPairFrequency++;
		playerHandTypes.at(0) = handTypes::twoPair;
		//onePairFrequency += 1; // does a two pair also count as an occurence of a pair?
	}
	
	else if (pairOrThreeKind(players.at(0)) == 1) {
		output = " pair";
		//playerOnePairFrequency++;
		//onePairFrequency += 1; // do a 3kind also count as an occurence of a pair?
		playerHandTypes.at(0) = handTypes::onePair;
	}
	else  
	{
		output = "HCard";
		//playerHighCardFrequency++;
		//highCardFrequency += 1;
		playerHandTypes.at(0) = handTypes::highCard;
	 
	}
	 
	 
		
	//statsFile << printHand(players.at(0)) << "," << output << endl;
	

	
}

void pokerGame::outputStatsOthers(ofstream& statsFile, int playerHandNum, int otherHandNum)
{
	isTie = false;
	sortOthersHand();
	string output;
	string winner;
	/*
	vector<vector<Card>> localPlayers;
	localPlayers.push_back(otherHand1);
	localPlayers.push_back(otherHand2);
	localPlayers.push_back(otherHand3);
	localPlayers.push_back(otherHand4);
	localPlayers.push_back(otherHand5);
	*/



	for (int i = 0; i < players.size(); i++) { //changed this to 0...
		if (isRoyalFlush(players.at(i)) == true) {


			if (i == 0) {
				playerRoyalFlushFrequency++;
			}
			else {
				output = "Royal Flush";
				royalFlushFrequency += 1;
				playerHandTypes.at(i) = handTypes::royalFlush;
			}
		}

		else if (isStraighFlush(players.at(i)) == true) {


			if (i == 0) {
				playerStraightFlushFrequency++;
			}

			else {
				output = "Straight Flush";
				straightFlushFrequency += 1;
				playerHandTypes.at(i) = handTypes::straightFlush;
			}
		}
		else if (pairOrThreeKind(players.at(i)) == 5) {


			if (i == 0) {
				playerFourKindFrequency++;
			}

			else {
				output = " 4Kind";
				fourKindFrequency += 1;
				playerHandTypes.at(i) = handTypes::fourKind;
			}
		}
		else if (pairOrThreeKind(players.at(i)) == 4) {



			if (i == 0) {
				playerFullHouseFrequency++;
			}

			else {
				output = "Full house";
				fullHouseFrequency += 1;
				playerHandTypes.at(i) = handTypes::fullhouse;
			}

			//twoPairFrequency += 1;
			//onePairFrequency += 1;
			//threeOfAKindFrequency += 1;
		}

		else if (isFlush(players.at(i)) == true) {

			if (i == 0) {
				playerFlushFrequency++;
			}
			else {
				output += "Flush";
				flushFrequency += 1;
				playerHandTypes.at(i) = handTypes::flush;
			}


		}

		else if (isStraight(players.at(i)) == true) {

			if (i == 0) {
				playerStraightFrequency++;
			}

			else {
				output = " straight";
				straightFrequency += 1;
				playerHandTypes.at(i) = handTypes::straight;
			}

		}

		else if (pairOrThreeKind(players.at(i)) == 3) {

			if (i == 0) {
				playerThreeOfAKindFrequency++;
			}
			else {
				output = " 3kind";
				threeOfAKindFrequency += 1;
				playerHandTypes.at(i) = handTypes::threeKind;
			}

			//onePairFrequency += 1;
		}


		else if (pairOrThreeKind(players.at(i)) == 2) {

			if (i == 0) {
				playerTwoPairFrequency++;

			}
			else {
				output = " 2pair";
				twoPairFrequency += 1;
				playerHandTypes.at(i) = handTypes::twoPair;
			}

			//onePairFrequency += 1;
		}

		else if (pairOrThreeKind(players.at(i)) == 1) {

			if (i == 0) {
				playerOnePairFrequency++;
			}
			else {
				output = " pair";
				onePairFrequency += 1;
				playerHandTypes.at(i) = handTypes::onePair;
			}
		}
		else {
			if (i == 0) {
				playerHighCardFrequency++;
			}
			else {
				output = "HCard";
				playerHighCardFrequency++;
				highCardFrequency += 1;
				playerHandTypes.at(i) = handTypes::highCard;
			}


		}


		//statsFile << printHand(players.at(i)) << "," << output << endl;
	}

	//sortPlayerHandRankings();

	handTypes highestPlayerRank = playerHandTypes.at(0);
	int highestPlayerRankIndex = 0;
	handTypes secondHighestPlayerRank = handTypes::minimum;
	int secondHighestPlayerRankIndex = 0;

	for (int i = 1; i < players.size(); i++) {
		if (playerHandTypes.at(i) > highestPlayerRank) { // > or >= ?
			highestPlayerRank = playerHandTypes.at(i);
			highestPlayerRankIndex = i;
		}

		else if (playerHandTypes.at(i) > secondHighestPlayerRank) { //> or >= ?
			secondHighestPlayerRank = playerHandTypes.at(i);
			secondHighestPlayerRankIndex = i;

		}


	}

	if (highestPlayerRank == secondHighestPlayerRank) { //tie needs to be resolved
		isTie = true;

	}
	else {
		isTie = false;
	}

	statsFile << "Player Hand " << playerHandNum << " iteration " << otherHandNum << "\n"; // maybe remove this later


	if (isTie == false && highestPlayerRankIndex == 0) {

		incrementCardRank(playerHandTypes.at(0), 0);
		statsFile << "Player won with a " << getStringValueRank(playerHandTypes.at(0)) << "\n";

	}
	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::highCard) { //if there is a tie and the 1st player is one of those in the tie


		int bestHighCardPlayer = getHighCardIndex(0);
		if (bestHighCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "All players have high cards and 1st player won   " << "\n";
		}
	}
	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::onePair) {


		int bestPairCardPlayer = getHighPairIndex(0);
		if (bestPairCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "There was a one pair tie and 1st player won" << "\n";
		}


	}

	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::twoPair) {

		int bestPairCardPlayer = getHighTwoPairIndex(0);
		if (bestPairCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "There was a two pair tie and 1st player won" << "\n";
		}
		else if (bestPairCardPlayer == -1) {
			statsFile << "There was a complete two pair tie" << "\n";
		}
	}

	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::threeKind) {

		int bestPairCardPlayer = getHighThreeKindIndex();
		if (bestPairCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "There was a three pair tie and 1st player won" << "\n";
		}

	}

	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::straight) {


		int bestStraightCardPlayer = getHighStraightIndex();
		if (bestStraightCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "There was a straight tie and 1st player won" << "\n";
		}
		else if (bestStraightCardPlayer == -1) {
			statsFile << "There was a full straight tie" << "\n";
		}


	}

	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::flush) {

		int bestFlushCardPlayer = getHighStraightIndex();
		if (bestFlushCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "There was a flush tie and 1st player won" << "\n";
		}
		else if (bestFlushCardPlayer == -1) {
			statsFile << "There was a full flush tie" << "\n";
		}


	}
	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::fullhouse) {
		int bestFlushCardPlayer = getFullHouseIndex();
		if (bestFlushCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "There was a full house tie and 1st player won" << "\n";
		}
		else if (bestFlushCardPlayer == -1) {
			statsFile << "There was a full flush tie" << "\n";
		}

	}
	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::fourKind) {

		int bestFourKindCardPlayer = getHighFourKindIndex();
		if (bestFourKindCardPlayer == 0) {
			incrementCardRank(playerHandTypes.at(0), 0);
			statsFile << "There was a four kind tie and 1st player won" << "\n";
		}
		else if (bestFourKindCardPlayer == -1) {
			statsFile << "There was a full flush tie" << "\n";
		}
		
	}
	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::straightFlush) {

	int bestStraightFlushPlayer = getStraightFlushIndex();
	if (bestStraightFlushPlayer == 0) {
		incrementCardRank(playerHandTypes.at(0), 0);
		statsFile << "There was a four kind tie and 1st player won" << "\n";
	}
	else if (bestStraightFlushPlayer == -1) {
		statsFile << "There was a  full straight flush tie. This is crazy!" << "\n";
	}

	}
	else if (isTie == true && highestPlayerRankIndex == 0 && highestPlayerRank == handTypes::royalFlush) {

		statsFile << "There was a royal flush tie. Go buy a lotto ticket!    ";
	}





	for (int i = 0; i < playerHandTypes.size(); i++) {

		if (highCardWins == 0) {

			if (playerHandTypes.at(i) == handTypes::highCard) {
				statsFile << printHand(players.at(i)) << ",high card" << "," << "0 %\n";
			}
		}
		else {
			if (playerHandTypes.at(i) == handTypes::highCard) {

				statsFile << printHand(players.at(i)) << ",high card" << "," << (highCardWins / float( playerHighCardFrequency)) * 100 << "%\n";
			}

		}

		if (onePairWins == 0) {
			if (playerHandTypes.at(i) == handTypes::onePair) {
				statsFile << printHand(players.at(i)) << ",one pair" << "," << "0 %\n";
			}
		}
		else {
			if (playerHandTypes.at(i) == handTypes::onePair) {
				statsFile << printHand(players.at(i)) << ",one pair" << "," << (onePairWins / float( playerOnePairFrequency)) * 100 << "%\n";
			}
		}

		if (twoPairWins == 0) {
			if (playerHandTypes.at(i) == handTypes::twoPair) {
				statsFile << printHand(players.at(i)) << ",two pair" << "," << "0 %\n";
			}
		}

		else {

			if (playerHandTypes.at(i) == handTypes::twoPair) {
				statsFile << printHand(players.at(i)) << ",two pair" << "," << (twoPairWins / float( playerTwoPairFrequency)) * 100 << "%\n";
			}

		}

		if (threeOfAKindWins == 0) {
			if (playerHandTypes.at(i) == handTypes::threeKind) {
				statsFile << printHand(players.at(i)) << ",three kind" << "," << "0 %\n";
			}
		}

		else {

			if (playerHandTypes.at(i) == handTypes::threeKind) {
				statsFile << printHand(players.at(i)) << ",three kind" << "," << (threeOfAKindWins / float( playerThreeOfAKindFrequency)) * 100 << "%\n";
			}

		}

		if (straightWins == 0) {
			if (playerHandTypes.at(i) == handTypes::straight) {
				statsFile << printHand(players.at(i)) << ",straight" << "," << "0 %\n";
			}

		}
		else {
			if (playerHandTypes.at(i) == handTypes::straight) {
				statsFile << printHand(players.at(i)) << ",straight" << "," << (straightWins / float (playerStraightFrequency)) * 100 << "%\n";
			}

		}

		if (flushWins == 0) {
			if (playerHandTypes.at(i) == handTypes::flush) {
				statsFile << printHand(players.at(i)) << ",flush" << "," << "0 %\n";
			}

		}
		else {
			if (playerHandTypes.at(i) == handTypes::flush) {
				statsFile << printHand(players.at(i)) << ",flush" << "," << (flushWins / float(playerFlushFrequency)) * 100 << "%\n";
			}

		}

		if (fullHouseWins == 0) {

			if (playerHandTypes.at(i) == handTypes::fullhouse) {
				statsFile << printHand(players.at(i)) << ",full house" << "," << "0 %\n";
			}

		}
		else {
			if (playerHandTypes.at(i) == handTypes::fullhouse) {
				statsFile << printHand(players.at(i)) << ",full house" << "," << ( fullHouseWins / float(playerFullHouseFrequency)) * 100 << "%\n";
			}

		}

		if (fourkindWins == 0) {
			if (playerHandTypes.at(i) == handTypes::fourKind) {
				statsFile << printHand(players.at(i)) << ",four of a kind" << "," << "0 %\n";
			}

		}

		else {
			if (playerHandTypes.at(i) == handTypes::fourKind) {
				statsFile << printHand(players.at(i)) << ",four of a kind" << "," << ( fourkindWins / float(playerFourKindFrequency)) * 100 << "%\n";
			}

		}

		if (straightFlushWins == 0) {
			if (playerHandTypes.at(i) == handTypes::straightFlush) {
				statsFile << printHand(players.at(i)) << ",straight flush" << "," << "0 %\n";
			}
		}
		else {
			if (playerHandTypes.at(i) == handTypes::straightFlush) {
				statsFile << printHand(players.at(i)) << ",straight flush" << "," << (  straightFlushWins / float(playerStraightFlushFrequency)) * 100 << "%\n";
			}
		}

		if (royalFlushWins == 0) {
			if (playerHandTypes.at(i) == handTypes::royalFlush) {
				statsFile << printHand(players.at(i)) << ",royal flush" << "," << "0 %\n";
			}

		}

		else {
			if (playerHandTypes.at(i) == handTypes::royalFlush) {
				statsFile << printHand(players.at(i)) << ",royal flush" << "," << ( royalFlushWins / float (playerRoyalFlushFrequency)) * 100 << "%\n";
			}

		}



		








		//awful performance fix
		//statsFile << printHand(players.at(i)) << "," << getStringValueRank(playerHandTypes.at(i))  << "," << "0 %" << endl;
	}
	statsFile << "\n\n\n";
}

		

			
			
			
			
			
			
			
			
			
			
			

		

	

	
		
	





void pokerGame::testMethod()
{
	
	for (int i = 0; i < 10000; i++) {
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
		

		clearPlayerHand();
		clearOtherHands();
		gameDeck.shuffleDeck();
	}

	

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

 

