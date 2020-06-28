#include "Player.h"

/* ќбъ€вленние переменных и их принадлежности к классу Player смвым*/
Player::Player(string input)
{
	name = input;
}
Player::Player(const Player& player)//конструктор копировани€
{
	name = player.name;
	hand = player.hand;
}