#include "action.h"
#include "debug.h"
#include <ctime>

void Action::get_card(vector<Player>& Players,Player active_player, Card card, int n)
{
    // n - позиция игрока в списке активных игроков
    Debug debug;
    switch (card.id_action)
    {
    case 0: //ничего
    case 2:
    {
        active_player.hand.push_back(card);
        Players.erase(Players.begin() + n); // перенос игрока в начало вектора активных игроков
        Players.insert(Players.begin(), active_player);
    }
    break;
    case 1: //котенок
    {
        debug.write_player_boom_info(Players[n]);
        Players.erase(Players.begin() + n);
        break;
    }
    
    default:
        break;
    }
}

void Action::card_in_hand(vector <Card>& deck, vector<Player>& Players, Player active_player, Card card, int n, int np)
{
    // n - индекс карты в руке
    // np - позиция игрока в списке активных игроков
    switch (card.id_action)
    {
    case 0:
    case 1:
        break;
    case 2:
    {
        srand(time(0));
        Card temp_card;
        temp_card = deck.back();
        if (deck.size() > 1) // если в колоде больше одной карты, то замешиваем взрывную в рандомное место
            {
                deck.pop_back(); //удаляем взрывную карту из основной колоды
                deck.insert(deck.begin() + rand() % deck.size(), temp_card); // замешиваем взрывную карту в колоду
            }
        active_player.hand.erase(active_player.hand.begin() + n); // удаление обезвреда из руки
        Players.erase(Players.begin() + np); // перенос игрока в начало вектора активных игроков
        Players.insert(Players.begin(), active_player);
    }
    default:
        break;
    }
}