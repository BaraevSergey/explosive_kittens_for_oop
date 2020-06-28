#include "debug.h"

void Debug::write_list_card_from_deck(vector <Card>& deck)
{
	/*
	deck - колода карт
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
	player - игрок, карты который взрывается
	*/
	cout << "Игрок " + player.name + " взорвался\n\n";
}

void Debug::write_player_winner_info(Player player)
{
	/*
	player - игрок, который победил
	*/
	cout << "Игрок " + player.name + " победил!\n";
}

void Debug::write_took_card(Player player, Card card)
{
	/*
	player - игрок, который взял карту
	card - карта, которую взял игрок
	*/
	cout << "Игрок " + player.name + " взял карту " + card.name + "\n";
}

void Debug::write_player_defuse_info(Player player)
{
	/*
	player - игрок, карты который сыграл карту обезвредить
	*/
	cout << "Игрок " + player.name + " сыграл карту обезвредить!\n\n";
}