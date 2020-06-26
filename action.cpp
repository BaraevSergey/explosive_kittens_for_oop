#include "action.h"
#include "debug.h"
void Action::action_card(vector<Player>& Players, Player Active_Player, Card card)
{
    Debug debug;
    switch (card.id_action)
    {
    case 0: //ничего
    {
        for (int i = 0; i != Players.size(); i++)
        {
            if (Active_Player.name == Players[i].name)
            {
                Players[i].hand.push_back(card);
                debug.write_list_card_from_players(Players[i]);
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
                Players.erase(Players.begin() + i);
                // debug.взрыв() метод напишет артем в дебаг
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