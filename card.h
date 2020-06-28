#pragma once
#include <vector>
#include <string>
using namespace std;

/* Класс, описывающий объект "Карта" */

class Card
{
	public:
		string name; //имя карты
		int id_action; // индекс события карты
		Card(string card_name, int card_action);
		Card(const Card& card);
		Card();
};