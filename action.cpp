#include "action.h"
#include "debug.h"
#include <ctime>

void Action::get_card(vector<Player>& Players, Card card, int n)
{
    /*
    Players - список игроков активных
    card - карта, которую берет игрок
    n - индекс игрока в списке активных, который берет карту
    */
    Debug debug;
    switch (card.id_action) //смотрим id действия карты
    {
    case 0: //если обычная
    case 2: //если обезвредить
    case 3: //если слиняй
    case 4: //если посмотреть в будущее
    {
        Players[n].hand.push_back(card); //просто кладем в руку игрока
        Player temp = Players[n]; //берем игрока который ходит
        Players.erase(Players.begin() + n); // переносим этого игрока в начало вектора активных игроков
        Players.insert(Players.begin(), temp); //удаляем из конца вектора его
    }
    break;
    case 1: //если карта взрыва
    {
        debug.write_player_boom_info(Players[n]); //выводим информацию о взрыве игрока
        Players.erase(Players.begin() + n); //удаляем его из списка активных
        break;
    }
    default:
        break;
    }
}

void Action::card_in_hand(vector <Card>& deck, vector<Player>& Players, Card card, int nc, int np)
{
    /*
    deck - колода карт
    Players - список игроков активных
    card - карта, которой ходит игрок
    nc - индекс карты в руке игрока
    np - индекс игрока в списке активных
    */
    switch (card.id_action) //смотрим действие карты которой ходят
    {
    case 0: //если обычная
    case 1: //котенок(по идее не зайдет даже сюда никогда)
        break; //ничего не делаем пока
    case 2: // если сыграна карта обезвредить
    {
        srand(time(0)); //рандом понадобится 
        Card temp_card; 
        temp_card = deck.back(); //берем последнюю карту из колоды(взрыв) для замешивания
        if (deck.size() > 1) // условие на случай, если остался только один взрыв в колоде, тогда перемешивание не нужно
            {
                deck.pop_back(); //удаляем взрывную карту из основной колоды
                deck.insert(deck.begin() + rand() % deck.size(), temp_card); // замешиваем взрывную карту в колоду в случайное место
            }
        Players[np].hand.erase(Players[np].hand.begin() + nc); // забираем у игрока карту обезвреживания
        Player temp = Players[np]; 
        Players.erase(Players.begin() + np);  //удаляем игрока с конца
        Players.insert(Players.begin(), temp); //ставим в начало его 
    }
    default:
        break;
    }
}