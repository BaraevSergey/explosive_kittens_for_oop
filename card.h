#pragma once
#include <vector>
#include <string>
using namespace std;
class Card
{
	public:
		string name; //��� �����
		int id_action; // ������ ������� �����

	Card()
	{

	}
	Card(string input)
	{
		name = input;
	}
	Card(string card_name, int card_action)
	{
		name = card_name;
		id_action = card_action;
	}

};