#include "action.h"

void Action::action_card(vector<Player>& Players, Player Active_Player, Card card)
{
    switch (card.id_action)
    {
    case 0: //������
    {
        for (int i = 0; i != Players.size(); i++)
        {
            if (Active_Player.name == Players[i].name)
            {
                Players[i].hand.push_back(card);
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