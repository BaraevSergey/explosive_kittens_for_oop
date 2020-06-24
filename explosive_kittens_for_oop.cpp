﻿#include <iostream>
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
        active_players.push_back(temp_player);
    }
 
    for (int i = 0; i < num_of_norm; i++) // присваивание свойств нейтральным картам
    {
        Card temp_card("Обычная карта", 0);
        deck.push_back(temp_card);
    }


    for (int i = 0; i < num_of_boom; i++) //присваиваем свойство для взрывных карт


    for (int i = 0; i < num_of_norm; i++) // присваивание свойств нейтральным картам

    {
        Card temp_card("Обычная карта", 0);
        deck.push_back(temp_card);
    }

    
    while (active_players.size() != 1)
    {
        //ход первого игрока
        active_players.at(0).hand.push_back(deck[0]); // добавляем в руку игроку верхнюю карту из колоды
        cout << "Player1 взял карту" << "\n";
        if (deck[0].id_action == 1)// проверяем свойство карты
        {
            active_players.erase(active_players.begin()); //удаляем игрока, если карта взрывная
            cout << "Player1 взорвался!" << "\n";
        }
        deck.erase(deck.begin()); //удаляем верхнюю карту из колоды

        if (deck.size() == 0) //если колода пуста, то прерываем игру
        {
            break;
        }

        //ход второго игрока
        active_players.at(1).hand.push_back(deck[0]);
        cout << "Player2 взял карту" << "\n";
        if (deck[0].id_action == 1)
        {
            active_players.erase(active_players.begin() + 1);
            cout << "Player2 взорвался!" << "\n";
        }
        deck.erase(deck.begin()); 

        if (deck.size() == 0)
        {
            break;
        }

    }



    for (int i = 0; i < num_of_boom; i++) //присваиваем свойство для взрывных карт
    {
        Card temp_card("Взрывной котенок", 1);
        deck.push_back(temp_card);
    }
   

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
            if (Active_Player.name == Players[i].name)
            {
                //Players.erase(Players.begin() + i);
                //не работает (
                //удаляем из списка игроков игрока по идее
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