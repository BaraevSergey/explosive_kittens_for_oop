#include "action.h"
#include "debug.h"
#include <ctime>

void Action::get_card(vector<Player>& Players, Player Active_Player, Card card)
{
    Debug debug;
    switch (card.id_action)
    {
    case 0: //������
    case 2:
    {
        for (int i = 0; i != Players.size(); i++)
        {
            if (Active_Player.name == Players[i].name)
            {
                Active_Player.hand.push_back(card);
                Players.erase(Players.begin() + i);
                Players.insert(Players.begin(), Active_Player);
               
            }
            else
            {

            }

        }
    }
    break;
    case 1: //�������
    {
        for (int i = 0; i != Players.size(); i++)
        {
            if (Active_Player.name == Players[i].name)
            {
                debug.write_player_boom_info(Players[i]);
                Players.erase(Players.begin() + i);
                break;
            }
            else
            {

            }

        }
    }
    
    default:
        break;
    }
}

void Action::card_in_hand(vector <Card>& deck, vector<Player>& Players, Player active_player, Card card, int n)
{
    // n - ������ ����� � ����
    switch (card.id_action)
    {
    case 0:
    case 1:
        break;
    case 2:
    {
        srand(time(0));
        Card temp_card;
        for (int i = 0; i != Players.size(); i++)
        {
            if (active_player.name == Players[i].name)
            {
                temp_card = deck.back();
                deck.pop_back(); //������� �������� ����� �� �������� ������
                deck.insert(deck.begin() + rand() % deck.size(), temp_card); // ���������� �������� ����� � ������
                active_player.hand.erase(active_player.hand.begin() + n); // �������� ��������� �� ����
                Players.erase(Players.begin() + i);
                Players.insert(Players.begin(), active_player);
            }
        }
    }
    default:
        break;
    }
}