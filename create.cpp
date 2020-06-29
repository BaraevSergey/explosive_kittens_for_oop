#include "create.h"
#include <ctime>

void Create::create_players(int number, vector <Player>& active_players)
{
    /*
    int number - ���������� �������
    vector <Player>& active_players - ������, ���������� �������� �������
    */
    for (int i = 0; i < number; i++) 
    {
        Player temp_player("Player" + to_string(number-i)); // �������� ������� ������ Player
        active_players.push_back(temp_player); // ���������� ������� ������ � ����� ������� �������� �������
    }
}
void Create::create_card_neutral(int number_of_card, vector <Card>& deck)
{
    /*
    int number_of_card - ����������� ���������� ����������� ����
    vector <Card>& deck - ������ ���� (������)
    */
    for (int i = 0; i < number_of_card; i++)
    {
        Card temp_card("�������", 0);// �������� ������� ������ Card
        deck.push_back(temp_card);// ���������� ����� � ����� ������
    }
}
void Create::create_card_bomb(int number_of_bomb, vector <Card>& deck)
{
    /*
    int number_of_bomb - ����������� ���������� �������� ����
    vector <Card>& deck - ������ ���� (������)
    */
    for (int i = 0; i < number_of_bomb; i++)
    {
        Card temp_card("��������", 1);// �������� ������� ������ Card
        deck.push_back(temp_card);// ���������� ����� � ����� ������
    }
}
void Create::create_card_defuse(int number_of_defuse, vector <Card> & deck, vector <Player> & players)
{
    /*
    int number_of_defuse - ����������� ���������� ��������������� ����
    */
	for (int i = 0; i < number_of_defuse-players.size(); i++) //������� � ������ �����
	{
		Card temp_card("��������������", 2);// �������� ������� ������ Card
		deck.push_back(temp_card);// ���������� ����� � ����� ������
	}
    for (Player &player : players) //����� ������ �� �����
    {
        Card temp_card("��������������", 2);// �������� ������� ������ Card
        player.hand.push_back(temp_card);
    }
}
void Create::mix_deck(vector <Card>& deck)
{
    /*
    vector <Card>& deck - ������ ���� (������)
    */
    srand(time(0));
    vector <Card> tmp_deck;// �������� ���������������� ������� ����
    int tmp = 0;//��������������� ����������
    while (deck.size() != 0)
    {
        tmp = rand() % deck.size();// ����� ���������� ����� �� 0 �� deck.size()
        tmp_deck.push_back(deck.at(tmp));// ���������� ����� �� ��������� �������� �� ������� deck � ����� ������� tmp_deck
        deck.erase(deck.begin() + tmp);// �������� ����� �� ������� deck
    }
    deck = tmp_deck;//������� ���� � �������� ������
}

void Create::hand_filling(vector <Player>& Players, vector <Card>& deck, int n) 
{
    srand(time(0));
    for (int j = 0; j != n-1; j++) // ��������� n-1 ����, ��������� ����� ����������� �� ������ � ������ ������
    {
        for (int i = 0; i != Players.size(); i++) //�� ������� ������� ������ �� ����� �����
        {
            int tmp = rand() % deck.size();
            Players[i].hand.push_back(deck[tmp]); 
            deck.erase(deck.begin() + tmp); //�� �������� ������� ����� �� ������
        }
    }
}

void Create::create_card_leave(int number_of_leave, vector <Card>& deck)
{
	/*
	int number_of_bomb - ����������� ���������� �������� ����
	vector <Card>& deck - ������ ���� (������)
	*/
	for (int i = 0; i < number_of_leave; i++)
	{
		Card temp_card("������", 3);// �������� ������� ������ Card
		deck.push_back(temp_card);// ���������� ����� � ����� ������
	}
}
