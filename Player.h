#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "card.h"
using namespace std;

/* Класс, ??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ДОПИСАТЬ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
class Player
{
	public:
		string name;
		vector <Card> hand;
		Player(string input);
		Player(const Player& player);//конструктор копирования

};
