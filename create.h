#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Create
{
	/*
	����� ��� �������� ������� � ������ ����
	*/
	public:
		void create_players(int n, vector <Player>& active_players); // ����� �������� �������
		void create_card_bomb(int number_of_card, vector <Card>& deck); // ����� �������� �������� ����
		void create_card_neutral(int number_of_card, vector <Card>& deck); // ����� �������� ������� ����
		void create_card_defuse(int number_of_defuse, vector <Card>& deck, vector <Player>& players); //����� �������� ���� �������������� + ������ ������� ����
		void mix_deck(vector <Card>& deck); // ����� ������������� ������
		void hand_filling(vector <Player>& Players, vector <Card>& deck, int n); //����� ���������� ��������� ����� � ���� ������
		
};