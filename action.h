#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;


/* Класс, содержащий методы действий над объектами во время игры*/

class Action 
{
	public:
		void card_in_hand(vector <Card>& deck, vector<Player>& Players, Card card, int n, int np);
		void get_card(vector<Player>& Players, Card card, int n);
};
