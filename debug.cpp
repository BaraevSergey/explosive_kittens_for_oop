#include "debug.h"

void Debug::write_list_card_from_deck(vector <Card>& deck)
{	
	/*
	deck - набор различных карт
	card_deck.name - название карт, находящихся в колоде
	*/

    cout << "Карты в колоде:\n";
    for (Card card_deck : deck)
    {
        cout << card_deck.name + "\n";
    }
}

void Debug::write_list_active_players(vector <Player>& active_players)
{
	/*
	active_players - cписок активных игроков
	player.name - имя активного игрока
	*/
    cout << "\nИгроки активные:\n";
    for (Player player : active_players)
    {
        cout << player.name + "\n";
    }
    cout << "\n";
}

void Debug::write_list_card_from_players(Player player)
{
	/*
	player - игрок, карты которого мы показываем
	player.name - имя активного игрока
	player.hand - карты в руке игрока
	card.name - название карты, которую берет игрок
	*/
    cout << "У игрока " + player.name + " сейчас в руке:\n";
    for (Card card : player.hand)
    {
        cout << card.name + ";";
    }
    cout << "\n\n";
}

void Debug::write_player_boom_info(Player player)
{
	/*
	player - игрок, карты которого мы показываем
	player.name - имя активного игрока
	*/
	cout << "Игрок " + player.name + " взорвался\n\n";
}

void Debug::write_player_winner_info(Player player)
{
	/*
	player - игрок, карты которого мы показываем
	player.name - имя активного игрока
	*/
	cout << "Игрок " + player.name + " победил!\n";
}

void Debug::write_took_card(Player player, Card card)
{
	/*
	player - игрок, карты которого мы показываем
	card - карта, которую мы показываем
	player.name - имя активного игрока
	card.name - название карты, которую берет игрок
	*/
    cout << "Игрок " + player.name + " взял карту " + card.name + "\n";
}

void Debug::write_player_defuse_info(Player player)
{
	/*
	player - игрок, карты которого мы показываем
	player.name - имя активного игрока
	*/
	cout << "Игрок " + player.name + " сыграл карту обезвредить!\n";
}