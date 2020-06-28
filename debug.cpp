#include "debug.h"

void Debug::write_list_card_from_deck(vector <Card>& deck)
{	
	/*
	deck - ����� ��������� ����
	card_deck.name - �������� ����, ����������� � ������
	*/

    cout << "����� � ������:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

void Debug::write_list_active_players(vector <Player>& active_players)
{
	/*
	active_players - c����� �������� �������
	player.name - ��� ��������� ������
	*/
    cout << "\n������ ��������:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }
    cout << "\n";
}

void Debug::write_list_card_from_players(Player player)
{
	/*
	player - �����, ����� �������� �� ����������
	player.name - ��� ��������� ������
	player.hand - ����� � ���� ������
	card.name - �������� �����, ������� ����� �����
	*/
    cout << "� ������ " + player.name + " ������ � ����:\n";
    for (Card card : player.hand)
    {
        cout << card.name + ";";
    }
    cout << "\n\n";
}

void Debug::write_player_boom_info(Player player)
{
	/*
	player - �����, ����� �������� �� ����������
	player.name - ��� ��������� ������
	*/
	cout << "����� " + player.name + " ���������\n\n";
}

void Debug::write_player_winner_info(Player player)
{
	/*
	player - �����, ����� �������� �� ����������
	player.name - ��� ��������� ������
	*/
	cout << "����� " + player.name + " �������!\n";
}

void Debug::write_took_card(Player player, Card card)
{
	/*
	player - �����, ����� �������� �� ����������
	card - �����, ������� �� ����������
	player.name - ��� ��������� ������
	card.name - �������� �����, ������� ����� �����
	*/
    cout << "����� " + player.name + " ���� ����� " + card.name + "\n";
}

void Debug::write_player_defuse_info(Player player)
{
	/*
	player - �����, ����� �������� �� ����������
	player.name - ��� ��������� ������
	*/
	cout << "����� " + player.name + " ������ ����� �����������!\n";
}