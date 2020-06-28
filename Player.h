#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "card.h"

using namespace std;

class Player
{
	/*
	Класс игроков
	*/
	public:
		string name;// имя игрока
		vector <Card> hand;// карты, принадлежащие игроку
		Player(string input);// конструктор
		Player(const Player& player);//конструктор копирования
		Player();//конструктор по умолчанию

};
