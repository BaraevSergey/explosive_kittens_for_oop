#pragma once
#include <vector>
#include "card.h"
#include "Player.h"

using namespace std;

class Create
{
	/*
	Класс для создания игроков и колоды карт
	*/
	public:
		void create_players(int n, vector <Player>& active_players); // метод создания игроков
		void create_card_bomb(int number_of_card, vector <Card>& deck); // метод создания взрывных карт
		void create_card_neutral(int number_of_card, vector <Card>& deck); // метод создания обычных карт
		void create_card_defuse(int number_of_defuse, vector <Card>& deck); //метод создания карт обезвреживания
		void mix_deck(vector <Card>& deck); // метод перемешивания колоды
		void hand_filling(vector <Player>& Players, vector <Card>& deck, int n); //метод добавления рандомной карты в руку игрока
		void hand_filling_defuse(vector <Player>& Players, vector <Card>& deck); // метод добавления в руку игрока обезвреживающей карты
};