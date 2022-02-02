#pragma once
#include <string>
class Card
{

public:
	enum suits { Spades, Hearts, Diamonds, Clubs, lastS };
	enum values { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, lastV };
	void setValue(values valueParam);
	void setSuit(suits suitParam);
	values getValue();
	suits getSuit();
private:
	values value;
	suits suit;
	
	
};

