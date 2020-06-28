#include "create.h"
#include <ctime>

/* Ěĺňîä ńîçäŕíč˙ čăđîęîâ. Ďĺđĺěĺííűĺ:
	 - int number - ÷čńëî čăđîęîâ
	 - vector <Player>& active_players - íŕáîđ ŕęňčâíűő čăđîęîâ äë˙ čăđű */
void Create::create_players(int number, vector <Player>& active_players)
{
    for (int i = 0; i < number; i++) 
    {
        Player temp_player("Player" + to_string(number-i));
        active_players.push_back(temp_player);
    }
}

/* Ěĺňîä ńîçäŕíč˙ "îáű÷íűő" ęŕđň. Ďĺđĺěĺííűĺ:
	- number_of_card - ÷čńëî îáű÷íűő ęŕđň â đóęĺ
	- vector <Card>& deck - íŕáîđ äĺéńňâóţůčő ęŕđň */
void Create::create_card_neutral(int number_of_card, vector <Card>& deck)
{
    for (int i = 0; i < number_of_card; i++)
    {
        Card temp_card("Îáű÷íŕ˙", 0);
        deck.push_back(temp_card);
    }
}

/* Ěĺňîä ńîçäŕíč˙ "âçđűâíűő" ęŕđň. Ďĺđĺěĺííűĺ:
	- number_of_bomb - ÷čńëî âçđűâíűő ęŕđň â đóęĺ
	- vector <Card>& deck - íŕáîđ äĺéńňâóţůčő ęŕđň */
void Create::create_card_bomb(int number_of_bomb, vector <Card>& deck)
{
    for (int i = 0; i < number_of_bomb; i++)
    {
        Card temp_card("Âçđűâíŕ˙", 1);
        deck.push_back(temp_card);
    }
}

void Create::create_card_defuse(int number_of_defuse, vector <Card> & deck)
{
	for (int i = 0; i < number_of_defuse; i++)
	{
		Card temp_card("Îáĺçâđĺćčâŕíčĺ", 2);
		deck.push_back(temp_card);
	}
}

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