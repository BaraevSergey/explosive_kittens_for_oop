#include "debug.h"

void Debug::write_list_card_from_deck(vector <Card>& deck) //метод показыающий список карт в колоде
{
    cout << " арты в колоде:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

void Debug::write_list_active_players(vector <Player>& active_players) //метод, который показывает какие игроки активные в списке есть
{

    cout << "\n»гроки активные:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }
    cout << "\n";
}

void Debug::write_list_card_from_players(Player player) //метод, показывающий карты в руке игрока
{
    cout << "” игрока " + player.name + " сейчас в руке:\n";
    for (Card card : player.hand)
    {
        cout << card.name + ";";
    }
    cout << "\n\n";
}