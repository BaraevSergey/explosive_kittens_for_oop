#include <iostream>
#include <vector>
#include "card.h"
#include "Player.h"
using namespace std;

void action_card(vector<Player>& Players, Player Active_Player, Card card); // метод выполнения действий карт
void create_player(int n, vector <Player>& active_players); // метод создания игроков
void create_deck(int n_b, int n_n, vector <Card>& deck); // метод создания колоды
void out_deck(vector <Card>& deck); //метод вывода колоды
void out_players(vector <Player>& active_players); // метод вывода активных игроков

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
    
    create_player(num_of_players, active_players);
    create_deck(num_of_boom, num_of_norm, deck);
    out_deck(deck);
    out_players(active_players);

    while (active_players.size() != 1)
    {
        for (int i = 0; i < active_players.size(); i++)
        {
            //берется карта, либо в руку кладется либо игрок умирает
            action_card(active_players, active_players[i], deck.back());
            //ту карту которую взяли удаляем из колоды
            deck.pop_back();
        }
        //проверка какие карты в руке у игрока
        for (Player player : active_players)
        {
            cout << "У игрока " + player.name + " сейчас в руке:\n";
            for (Card card : player.hand)
            {
                cout << card.name + "\n";
            }
        }
      
    }
    system("pause");
        
}

// МНОГО МЕТОДОВ

void action_card(vector<Player>& Players, Player Active_Player, Card card)
//я создал метод тут , так как хз пока куда его
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

void create_player(int n, vector <Player>& active_players)
{
    for (int i = 0; i < n; i++) //создал цикл заполнения игроков
    {
        Player temp_player("Player" + to_string(i + 1));
        active_players.push_back(temp_player);
    }
}

void create_deck(int n_b, int n_n, vector <Card>& deck)
{
    for (int i = 0; i < n_b; i++) // присваивание свойств ВЗРЫВНЫМ картам
    {
        Card temp_card("Взрывная карта", 1);
        deck.push_back(temp_card);
    }

    for (int i = 0; i < n_n; i++) // присваивание свойств НЕЙТРАЛЬНЫМ картам

    {
        Card temp_card("Обычная карта", 0);
        deck.push_back(temp_card);
    }
}

void out_deck(vector <Card>& deck)
{
    cout << "Карты в колоде:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

void out_players(vector <Player>& active_players)
{
    //метод показа добавленных игроков
    cout << "\nИгроки активные:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }

}