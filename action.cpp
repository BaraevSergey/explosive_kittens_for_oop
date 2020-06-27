#include "action.h"
#include "debug.h"
#include <ctime>

void Action::get_card(vector<Player>& Players,Player active_player, Card card, int n)
{
    // n - ������� ������ � ������ �������� �������
    Debug debug;
    switch (card.id_action)
    {
    case 0: //������
    case 2:
    {
        active_player.hand.push_back(card);
        Players.erase(Players.begin() + n); // ������� ������ � ������ ������� �������� �������
        Players.insert(Players.begin(), active_player);
    }
    break;
    case 1: //�������
    {
        debug.write_player_boom_info(Players[n]);
        Players.erase(Players.begin() + n);
        break;
    }
    
    default:
        break;
    }
}

void Action::card_in_hand(vector <Card>& deck, vector<Player>& Players, Player active_player, Card card, int n, int np)
{
    // n - ������ ����� � ����
    // np - ������� ������ � ������ �������� �������
    switch (card.id_action)
    {
    case 0:
    case 1:
        break;
    case 2:
    {
        srand(time(0));
        Card temp_card;
        temp_card = deck.back();
        if (deck.size() > 1) // ���� � ������ ������ ����� �����, �� ���������� �������� � ��������� �����
            {
                deck.pop_back(); //������� �������� ����� �� �������� ������
                deck.insert(deck.begin() + rand() % deck.size(), temp_card); // ���������� �������� ����� � ������
            }
        active_player.hand.erase(active_player.hand.begin() + n); // �������� ��������� �� ����
        Players.erase(Players.begin() + np); // ������� ������ � ������ ������� �������� �������
        Players.insert(Players.begin(), active_player);
    }
    default:
        break;
    }
}