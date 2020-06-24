#include <vector>
#include <string>
#include <iostream>
#include "card.h"
using namespace std;
class Player
{
public:
		string name;
		vector <Card> hand;

	Player(string input)
	{
		name = input;
	}
	Player(const Player &player)//конструктор копирования
	{
		name = player.name;
		hand = player.hand;
	}

};
