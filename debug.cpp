#include "debug.h"

void Debug::write_list_card_from_deck(vector <Card>& deck) //����� ����������� ������ ���� � ������
{
    cout << "����� � ������:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

void Debug::write_list_active_players(vector <Player>& active_players) //�����, ������� ���������� ����� ������ �������� � ������ ����
{

    cout << "\n������ ��������:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }
    cout << "\n";
}

void Debug::write_list_card_from_players(Player player) //�����, ������������ ����� � ���� ������
{
    cout << "� ������ " + player.name + " ������ � ����:\n";
    for (Card card : player.hand)
    {
        cout << card.name + ";";
    }
    cout << "\n\n";
}