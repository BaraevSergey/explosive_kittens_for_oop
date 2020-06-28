#include "create.h"
#include <ctime>

/* Метод создания игроков. Переменные:
	 - int number - число игроков
	 - vector <Player>& active_players - набор активных игроков для игры */
void Create::create_players(int number, vector <Player>& active_players)
{
    for (int i = 0; i < number; i++) 
    {
        Player temp_player("Player" + to_string(number-i));
        active_players.push_back(temp_player);
    }
}

/* Метод создания "обычных" карт. Переменные:
	- number_of_card - число обычных карт в руке
	- vector <Card>& deck - набор действующих карт */
void Create::create_card_neutral(int number_of_card, vector <Card>& deck)
{
    for (int i = 0; i < number_of_card; i++)
    {
        Card temp_card("Обычная карта", 0);
        deck.push_back(temp_card);
    }
}

/* Метод создания "взрывных" карт. Переменные:
	- number_of_bomb - число взрывных карт в руке
	- vector <Card>& deck - набор действующих карт */
void Create::create_card_bomb(int number_of_bomb, vector <Card>& deck)
{
    for (int i = 0; i < number_of_bomb; i++)
    {
        Card temp_card("Взрывная карта", 1);
        deck.push_back(temp_card);
    }
}

/* Метод для замешивания всех карт. Переменные:
	- vector <Card>& deck - набор действующих карт */
void Create::mix_deck(vector <Card>& deck)
{
    srand(time(0));
    vector <Card> tmp_deck;
    int tmp = 0;
    while (deck.size() != 0)
    {
        tmp = rand() % deck.size();
        tmp_deck.push_back(deck.at(tmp));
        deck.erase(deck.begin() + tmp);
    }
    deck = tmp_deck;
}