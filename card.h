#pragma once
#include <vector>
#include <string>
using namespace std;

/* �����, ����������� ������ "�����" */

class Card
{
	public:
		string name; //��� �����
		int id_action; // ������ ������� �����
		Card(string card_name, int card_action);
		Card(const Card& card);
		Card();
};