#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

/*  ласс, описыващий методы вывода текущей информации о событи€х в игре */
class Debug
{
	public:
		void write_list_card_from_deck(vector <Card>& deck); //метод показыающий список карт в колоде
		void write_list_active_players(vector <Player>& active_players); //метод, который показывает какие игроки активные есть в списке
		void write_list_card_from_players(Player player); //метод, показывающий карты в руке игрока
		void write_player_boom_info(Player player); //метод вывода информации о том, что игрок взорвалс€
		void write_player_winner_info(Player player); //метод вывода информации о том, что игрок победил
		void write_took_card(Player player, Card card); //метод вывода инфы о том, что игрок вз€л карту
};