#include "debug.h"


/* �����, ������������ ������ ���� � ������. ����������:
	- vector <Card>& deck* - ����� ����������� ���� */
void Debug::write_list_card_from_deck(vector <Card>& deck)
{
    cout << "����� � ������:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

/* �����, ������������ ������ ���� � ������. ����������:
	- vector <Card>& deck* - ����� ����������� ����
	- vector <Player>& active_players - ����� �������� ������� ��� ���� */
void Debug::write_list_active_players(vector <Player>& active_players) 
{
    cout << "\n������ ��������:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }
    cout << "\n";
}

/* �����, ������������ ����� � ���� ������. ����������:
	- Player player - ������� ����� */
void Debug::write_list_card_from_players(Player player)
{
    cout << "� ������ " + player.name + " ������ � ����:\n";
    for (Card card : player.hand)
    {
        cout << card.name + ";";
    }
    cout << "\n\n";
}

/* �����, ������������ ���������� � "������" ������
	- Player player - ������� ����� */
void Debug::write_player_boom_info(Player player)
{
	cout << "����� " + player.name + " ���������\n\n";
}

/* �����, ������������ ���������� � ������ ������
	- Player player - ������� ����� */
void Debug::write_player_winner_info(Player player)
{
	cout << "����� " + player.name + " �������!\n";
}

/* �����, ������������ ���������� � ���, ��� ����� ���� �����
	- Player player - ������� �����
	- Card card - ������� �����*/
void Debug::write_took_card(Player player, Card card)
{
    cout << "����� " + player.name + " ���� ����� " + card.name + "\n";
}