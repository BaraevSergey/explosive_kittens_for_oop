#include "create.h"
#include <ctime>

void Create::create_players(int number, vector <Player>& active_players)
{
    /*
    int number - количество игроков
    vector <Player>& active_players - вектор, содержащий активных игроков
    */
    for (int i = 0; i < number; i++) 
    {
        Player temp_player("Player" + to_string(number-i)); // создание объекта класса Player
        active_players.push_back(temp_player); // добавление объекта класса в конец вектора активных игроков
    }
}
void Create::create_card_neutral(int number_of_card, vector <Card>& deck)
{
    /*
    int number_of_card - необходимое количество нейтральных карт
    vector <Card>& deck - вектор карт (колода)
    */
    for (int i = 0; i < number_of_card; i++)
    {
        Card temp_card("Обычная", 0);// создание объекта класса Card
        deck.push_back(temp_card);// добавление карты в конец колоды
    }
}
void Create::create_card_bomb(int number_of_bomb, vector <Card>& deck)
{
    /*
    int number_of_bomb - необходимое количество взрывных карт
    vector <Card>& deck - вектор карт (колода)
    */
    for (int i = 0; i < number_of_bomb; i++)
    {
        Card temp_card("Взрывная", 1);// создание объекта класса Card
        deck.push_back(temp_card);// добавление карты в конец колоды
    }
}
void Create::create_card_defuse(int number_of_defuse, vector <Card> & deck, vector <Player> & players)
{
    /*
    int number_of_defuse - необходимое количество обезвреживающих карт
    */
	for (int i = 0; i < number_of_defuse-players.size(); i++) //сначала в колоду карты
	{
		Card temp_card("Обезвреживание", 2);// создание объекта класса Card
		deck.push_back(temp_card);// добавление карты в конец колоды
	}
    for (Player &player : players) //затем игроку по одной
    {
        Card temp_card("Обезвреживание", 2);// создание объекта класса Card
        player.hand.push_back(temp_card);
    }
}
void Create::mix_deck(vector <Card>& deck)
{
    /*
    vector <Card>& deck - вектор карт (колода)
    */
    srand(time(0));
    vector <Card> tmp_deck;// создание вспомогательного вектора карт
    int tmp = 0;//вспомогательная переменная
    while (deck.size() != 0)
    {
        tmp = rand() % deck.size();// выбор случайного числа от 0 до deck.size()
        tmp_deck.push_back(deck.at(tmp));// добавление карты со случайным индексом из вектора deck в конец вектора tmp_deck
        deck.erase(deck.begin() + tmp);// удаление карты из вектора deck
    }
    deck = tmp_deck;//перенос карт в основную колоду
}

void Create::hand_filling(vector <Player>& Players, vector <Card>& deck, int n) 
{
    srand(time(0));
    for (int j = 0; j != n-1; j++) // заполняем n-1 карт, последняя будет обезвредить из колоды в другом методе
    {
        for (int i = 0; i != Players.size(); i++) //по очереди каждому игроку по одной карте
        {
            int tmp = rand() % deck.size();
            Players[i].hand.push_back(deck[tmp]); 
            deck.erase(deck.begin() + tmp); //не забываем удалить карту из колоды
        }
    }
}

void Create::create_card_leave(int number_of_leave, vector <Card>& deck)
{
	/*
	int number_of_bomb - необходимое количество взрывных карт
	vector <Card>& deck - вектор карт (колода)
	*/
	for (int i = 0; i < number_of_leave; i++)
	{
		Card temp_card("Слиняй", 3);// создание объекта класса Card
		deck.push_back(temp_card);// добавление карты в конец колоды
	}
}
