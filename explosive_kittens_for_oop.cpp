#include <iostream>
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    vector <Card> deck; // вектор колоды
    vector <Player> active_players; // вектор игроков
    vector <Card> active_deck; // вектор активной колоды

    int num_of_players; // переменная для задания количества игроков
    cout << "Введите количество игроков: ";
    cin >> num_of_players;
    Player* p = new Player[num_of_players]; // создание заданного количества игроков

    int num_of_cards = 13; // количество карт в колоде
    int num_of_boom = num_of_players - 1;// количество взрывных котят в колоде
    int num_of_norm = num_of_cards - num_of_boom; // количество "нейтральных" карт в колоде
    Card* boom = new Card[num_of_boom];// создание взрывных карт
    for (int i = 0; i <= num_of_boom; i++) //присваиваем сойство для взрывных карт
    {
        boom[i].id_action = 1;
    }
    Card* norm = new Card[num_of_norm];// создание "нейтральных" карт
    for (int i = 0; i <= num_of_norm; i++) // присваивание свойств нейтральным картам
    {
        norm[i].id_action = 2;
    }
    system("pause");
}

