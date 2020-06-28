#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Action //класс с различными действиями, происходящими в игре
{
	public:
		void card_in_hand(vector <Card>& deck, vector<Player>& Players, Card card, int n, int np); //событие игры карты с руки игрока
		void get_card(vector<Player>& Players, Card card, int n); //событие получения карты с колоды игроком
};
