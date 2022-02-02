#include "Card.h"

void Card::setValue(values valueParam)
{
	value = valueParam;
}

void Card::setSuit(suits suitParam)
{
	suit = suitParam;
}

Card::values Card::getValue()
{
	return value;
}

Card::suits Card::getSuit()
{
	return suit;
}
