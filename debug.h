#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Debug
{
	public:
		void write_list_card_from_deck(vector <Card>& deck); //����� ����������� ������ ���� � ������
		void write_list_active_players(vector <Player>& active_players); //�����, ������� ���������� ����� ������ �������� � ������ ����
		void write_list_card_from_players(Player player); //�����, ������������ ����� � ���� ������
};