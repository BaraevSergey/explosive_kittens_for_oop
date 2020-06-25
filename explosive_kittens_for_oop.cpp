#include <iostream>
#include <vector>
#include "card.h"
#include "Player.h"
#include "action.h"
#include "create.h"
#include "debug.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    vector <Card> deck; // вектор колоды
    vector <Player> active_players; // вектор игроков
    int num_of_players = 2; // переменная для задания количества игроков
    int num_of_cards = 13; // количество карт в колоде
    int num_of_boom = num_of_players - 1;// количество взрывных котят в колод
    int num_of_norm = num_of_cards - num_of_boom; // количество "нейтральных" карт в колоде
    
    Debug debug;
    Action action;
    Create create;
    create.create_players(num_of_players, active_players);
    create.create_card_bomb(num_of_boom, deck);
    create.create_card_neutral(num_of_norm, deck);
    create.mix_deck(deck);
    debug.write_list_card_from_deck(deck);
   
    while (active_players.size() != 1)
    {
        for (int i = 0; i < active_players.size(); i++)
        {
            //берется карта, либо в руку кладется либо игрок умирает
            action.action_card(active_players, active_players[i], deck.back());
            //ту карту которую взяли удаляем из колоды
            deck.pop_back();
        } 
    }
    system("pause");
}
