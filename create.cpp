#include "create.h"

void Create::create_players(int number, vector <Player>& active_players)
{
    for (int i = 0; i < number; i++) 
    {
        Player temp_player("Player" + to_string(i + 1));
        active_players.push_back(temp_player);
    }
}
void Create::create_card_neutral(int number_of_card, vector <Card>& deck)
{
    for (int i = 0; i < number_of_card; i++)
    {
        Card temp_card("Обычная карта", 0);
        deck.push_back(temp_card);
    }
}
void Create::create_card_bomb(int number_of_bomb, vector <Card>& deck)
{
    for (int i = 0; i < number_of_bomb; i++)
    {
        Card temp_card("Взрывная карта", 1);
        deck.push_back(temp_card);
    }
}