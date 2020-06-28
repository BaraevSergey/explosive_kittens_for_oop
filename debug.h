#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Debug
{
	/* �����, ����������� ������ ������ ���������� � �������� ������������ � ���� */

public:
	void write_list_card_from_deck(vector <Card>& deck); //����� ����������� ������ ���� � ������
	void write_list_active_players(vector <Player>& active_players); //�����, ������� ���������� ����� ������ �������� � ������ ����
	void write_list_card_from_players(Player player); //�����, ������������ ����� � ���� ������
	void write_player_boom_info(Player player); //����� ������ ���������� � ���, ��� ����� ���������
	void write_player_winner_info(Player player); //����� ������ ���������� � ���, ��� ����� �������
	void write_player_defuse_info(Player player); //�����, ������������ ���������� � ���, ��� ����� ������ ����� �����������
	void write_took_card(Player player, Card card); //����� ������ ���������� � ���, ��� ����� ���� �����
};