#include "card.h"

	Card::Card(string card_name, int card_action)
	{
		name = card_name;
		id_action = card_action;
	}
	
	Card::Card(const Card& card)
	{
		name = card.name;
		id_action = card.id_action;
	}
