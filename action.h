#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Action 
{
	public:
		void card_in_hand(vector <Card>& deck, vector<Player>& Players, Player active_player, Card card, int n);
		void get_card(vector<Player>& Players, Player Active_Player, Card card);
};
