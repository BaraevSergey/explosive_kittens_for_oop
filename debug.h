#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Debug
{
	/* Класс, описывающий методы вывода информации о событиях происходящих в игре */

public:
	void write_list_card_from_deck(vector <Card>& deck); //метод показыающий список карт в колоде
	void write_list_active_players(vector <Player>& active_players); //метод, который показывает какие игроки активные в списке есть
	void write_list_card_from_players(Player player); //метод, показывающий карты в руке игрока
	void write_player_boom_info(Player player); //метод вывода информации о том, что игрок взорвался
	void write_player_winner_info(Player player); //метод вывода информации о том, что игрок победил
	void write_player_defuse_info(Player player); //метод, показывающий информацию о том, что игрок сыграл карту обезвредить
	void write_took_card(Player player, Card card); //метод вывода информации о том, что игрок взял карту
};