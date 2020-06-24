#pragma once
#include <vector>
#include <string>
using namespace std;
class Card
{
	public:
		string name; //имя карты
		int id_action; // индекс события карты
		Card(string card_name, int card_action);
		Card(const Card& card);
};