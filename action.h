#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Action 
{
	public:
		void action_card(vector<Player>& Players, Player Active_Player, Card card);
};
