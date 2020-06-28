#include "action.h"
#include "debug.h"
/*	Метод описания действий при разыгровке карт - Action, где:
	- vector<Player>& Players - кол-во играющих игроков,
	- Player Active_Player - игрок, который делает ход(активный игрок),
	- Card card - карта разыгрываемая активным игроком
	*/
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