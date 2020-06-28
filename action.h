#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;


/* Класс, содержащий методы действий над объектами во время игры*/

class Action 
{
	public:
		void action_card(vector<Player>& Players, Player Active_Player, Card card);
};
