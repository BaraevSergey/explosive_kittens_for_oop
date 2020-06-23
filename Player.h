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

	Player()
	{
		cout << "¬ведите им€ игрока: ";
		cin >> name;
	}
	Player(string input)
	{
		name = input;
	}

};
