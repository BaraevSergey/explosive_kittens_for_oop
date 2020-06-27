#include <iostream>
#include <vector>
#include "card.h"
#include "Player.h"
#include "action.h"
#include "create.h"
#include "debug.h"
#include "windows.h" 

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    vector <Card> deck; // вектор колоды
    vector <Player> active_players; // вектор игроков
    //штука ввода параметров из консоли по гиту не передается, пока оставим 
    //int num_of_players = atoi(argv[1]); // переменная для задания количества игроков
    int num_of_players = 3;
    int num_of_cards = num_of_players * 6;// количество карт в колоде
    int num_of_boom = num_of_players - 1;// количество взрывных котят в колод
    int num_of_norm = num_of_cards - num_of_boom; // количество "нейтральных" карт в колоде
	int num_of_defuse = num_of_players + 2;
    
    Debug debug;
    Action action;
    Create create;
    create.create_players(num_of_players, active_players);
    create.create_card_neutral(num_of_norm, deck); 
    create.create_card_bomb(num_of_boom, deck);
	create.create_card_defuse(num_of_defuse, deck);
    create.mix_deck(deck);
    debug.write_list_card_from_deck(deck);
    debug.write_list_active_players(active_players);
    while (active_players.size() != 1)
    {
        Sleep(300);
        if (deck.back().id_action == 1)
        {
            debug.write_took_card(active_players.back(), deck.back());
            int i = 0; //счетчик какая карта в руке по счету
            bool flag = true;
            for (Card card : active_players.back().hand)
            {
                if (card.id_action == 2)
                {
                    debug.write_player_defuse_info(active_players.back());
                    action.card_in_hand(deck, active_players, active_players.back(), card, i);
                    flag = false;
                    debug.write_list_card_from_deck(deck);
                    break;
                }
                i++;
            }
            if (flag)
            {
                action.get_card(active_players, active_players.back(), deck.back());
                deck.pop_back();
                debug.write_list_card_from_players(active_players.back());
            }
        }
        else
        {
            debug.write_took_card(active_players.back(), deck.back());
            //берется карта, либо в руку кладется либо игрок умирает
            action.get_card(active_players, active_players.back(), deck.back());
            //ту карту которую взяли удаляем из колоды
            deck.pop_back();
            debug.write_list_card_from_players(active_players.back());
        }
    }
    debug.write_player_winner_info(active_players[0]);
    system("pause");
}
