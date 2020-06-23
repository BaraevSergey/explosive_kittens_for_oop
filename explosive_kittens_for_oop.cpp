#include <iostream>
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

void action_card(const vector<Player>& Players, Player Active_Player, int id_action);
int main()
{
    setlocale(LC_ALL, "Russian");

    vector <Card> deck; // вектор колоды
    vector <Player> active_players; // вектор игроков
    vector <Card> active_deck; // вектор активной колоды
    int num_of_players = 2; // переменная для задания количества игроков
    int num_of_cards = 13; // количество карт в колоде
    int num_of_boom = num_of_players - 1;// количество взрывных котят в колод
    int num_of_norm = num_of_cards - num_of_boom; // количество "нейтральных" карт в колоде
    
    for (int i = 0; i < num_of_players; i++) //создал цикл заполнения игроков
    {
        Player temp_player("Player"+to_string(i+1));
        cout << temp_player.name+"\n";
        active_players.push_back(temp_player);
    }


    
    for (int i = 0; i < num_of_boom; i++) //присваиваем свойство для взрывных карт
    {
        Card temp_card("Взрывной котенок", 1);
        deck.push_back(temp_card);
    }
    for (int i = 0; i < num_of_norm; i++) // присваивание свойств нейтральным картам
    {
        Card temp_card("Обычная карта", 0);
        deck.push_back(temp_card);
    }
    action_card(active_players, active_players[0], 1);
    system("pause");
}

void action_card(const vector<Player>& Players, Player Active_Player, int id_action)
{
    switch (id_action)
    {
    case 0: //ничего
        break;
    case 1: //котенок
    {
        for (int i = 0; i != Players.size(); i++)
        {
            cout << 1;
        }
    }
    default:
        break;
    }
}