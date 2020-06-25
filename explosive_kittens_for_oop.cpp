#include <iostream>
#include <vector>
#include "card.h"
#include "Player.h"
using namespace std;


//для этого метода создай класс Action
void action_card(vector<Player>& Players, Player Active_Player, Card card); // метод выполнения действий карт

//для этих создай класс Create
void create_players(int n, vector <Player>& active_players); // метод создания игроков
void create_card_bomb(int n_b, vector <Card>& deck); // создание карт бомбочек
void create_card_neutral(int number_of_card, vector <Card>& deck); //создание карт нейтральных

//для этих создай класс Debug
void write_list_card_from_deck(vector <Card>& deck); //метод показыающий список карт в колоде
void write_list_active_players(vector <Player>& active_players); //метод, который показывает какие игроки активные в списке есть
void write_list_card_from_players(Player player); //метод, показывающий карты в руке игрока
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
    
    create_players(num_of_players, active_players);
    create_card_bomb(num_of_boom, deck);
    create_card_neutral(num_of_norm, deck);


    while (active_players.size() != 1)
    {
        for (int i = 0; i < active_players.size(); i++)
        {
            //берется карта, либо в руку кладется либо игрок умирает
            action_card(active_players, active_players[i], deck.back());
            //ту карту которую взяли удаляем из колоды
            deck.pop_back();
        }
       
      
    }
    system("pause");
        
}


void action_card(vector<Player>& Players, Player Active_Player, Card card)
{
    switch (card.id_action)
    {
    case 0: //ничего
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
    case 1: //котенок
        {
            for (int i = 0; i != Players.size(); i++)
            {
                if (Active_Player.name == Players[i].name)
                {
                    Players.erase(Players.begin() + i);
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

void create_players(int number, vector <Player>& active_players) //создание игроков
{
    for (int i = 0; i < number; i++) //создал цикл заполнения игроков
    {
        Player temp_player("Player" + to_string(i + 1));
        active_players.push_back(temp_player);
    }
}

void create_card_bomb(int number_of_card, vector <Card>& deck) //создание карт бомбочек
{
    for (int i = 0; i < number_of_card; i++) 
    {
        Card temp_card("Взрывная карта", 1);
        deck.push_back(temp_card);
    }
}

void create_card_neutral (int number_of_card, vector <Card>& deck) //создание карт нейтральных
{
    for (int i = 0; i < number_of_card; i++) 
    {
        Card temp_card("Обычная карта", 0);
        deck.push_back(temp_card);
    }
}


void write_list_card_from_deck(vector <Card>& deck) //метод показыающий список карт в колоде
{
    cout << "Карты в колоде:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

void write_list_active_players(vector <Player>& active_players) //метод, который показывает какие игроки активные в списке есть
{
    
    cout << "\nИгроки активные:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }

}

void write_list_card_from_players(Player player) //метод, показывающий карты в руке игрока
{
    cout << "У игрока " + player.name + " сейчас в руке:\n";
    for (Card card : player.hand)
    {
        cout << card.name + "\n";
    }
}