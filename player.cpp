#include "Player.h"

Player::Player(string input)
{
	name = input;
}
Player::Player(const Player& player)//����������� �����������
{
	name = player.name;
	hand = player.hand;
}