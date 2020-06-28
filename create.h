#pragma once
#include <vector>
#include "card.h"
#include "Player.h"
using namespace std;

/* Класс, описывающий методы генерации объектов и действий в игре */
class Create
{
	public:
		void create_players(int n, vector <Player>& active_players); // метод создания игроков
		void create_card_bomb(int number_of_card, vector <Card>& deck); // метод создания взрывных карт
		void create_card_neutral(int number_of_card, vector <Card>& deck); // метод создания обычных карт
		void mix_deck(vector <Card>& deck); // метод перемешивания колоды
};