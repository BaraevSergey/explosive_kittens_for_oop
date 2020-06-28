#include "debug.h"


/* Метод, показывающий список карт в колоде. Переменные:
	- vector <Card>& deck* - набор действующих карт */
void Debug::write_list_card_from_deck(vector <Card>& deck)
{
    cout << "Карты в колоде:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

/* Метод, показывающий список карт в колоде. Переменные:
	- vector <Card>& deck* - набор действующих карт
	- vector <Player>& active_players - набор активных игроков для игры */
void Debug::write_list_active_players(vector <Player>& active_players) 
{
    cout << "\nИгроки активные:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }
    cout << "\n";
}

/* Метод, показывающий карты в руке игрока. Переменные:
	- Player player - текущий игрок */
void Debug::write_list_card_from_players(Player player)
{
    cout << "У игрока " + player.name + " сейчас в руке:\n";
    for (Card card : player.hand)
    {
        cout << card.name + ";";
    }
    cout << "\n\n";
}

/* метод, показываюший информацию о "взрыве" игрока
	- Player player - текущий игрок */
void Debug::write_player_boom_info(Player player)
{
	cout << "Игрок " + player.name + " взорвался\n\n";
}

/* метод, показываюший информацию о победе игрока
	- Player player - текущий игрок */
void Debug::write_player_winner_info(Player player)
{
	cout << "Игрок " + player.name + " победил!\n";
}

/* метод, показываюший информацию о том, что игрок взял карту
	- Player player - текущий игрок
	- Card card - текущая карта*/
void Debug::write_took_card(Player player, Card card)
{
    cout << "Игрок " + player.name + " взял карту " + card.name + "\n";
}