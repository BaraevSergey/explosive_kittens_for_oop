#include "action.h"
#include "debug.h"
#include <ctime>

void Action::get_card(vector<Player>& Players, Player Active_Player, Card card)
{
    Debug debug;
    switch (card.id_action)
    {
    case 0: //ничего
    case 2:
    {
        for (int i = 0; i != Players.size(); i++)
        {
            if (Active_Player.name == Players[i].name)
            {
                Active_Player.hand.push_back(card);
                debug.write_list_card_from_players(Active_Player);
                Players.erase(Players.begin() + i);
                Players.insert(Players.begin(), Active_Player);
               
            }
            else
            {

            }

        }
    }
    break;
    case 1: //котенок
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
    // n - индекс обезвреда
    switch (card.id_action)
    {
    case 0:
    case 1:
        break;
    case 2:
    {
        srand(time(0));
        vector <Card> tmp_deck;
        for (int i = 0; i != Players.size(); i++)
        {
            if (active_player.name == Players[i].name)
            {
                tmp_deck.push_back(deck.back()); // переносим взрывную карту в вспомогательный вектор
                deck.pop_back(); //удаляем взрывную карту из основной колоды
                deck.insert(deck.begin() + rand() % deck.size(), tmp_deck.back()); // замешиваем взрывную карту в колоду
                active_player.hand.erase(active_player.hand.begin() + n); // удаление обезвреда
                Players.erase(Players.begin() + i);
                Players.insert(Players.begin(), active_player);
            }
        }
    }
    default:
        break;
    }
}