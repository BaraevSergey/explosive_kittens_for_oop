#include <vector>
#include <string>
#include <iostream>
#include "card.h"
using namespace std;
class Player
{
	string name;
	vector <Card> hand;

	public: Player(string input)
	{
		name = input;
	}

};
