#include <iostream>
#include <vector>
#include "card.h"
#include "Player.h"
#include "action.h"
#include "create.h"
#include "debug.h"
#include "windows.h" 

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian"); //задаем русскую локаль
    vector <Card> deck; // вектор колоды карт
    vector <Player> active_players; // вектор игроков активных
    //штука ввода параметров из консоли по гиту не передается, пока оставим 
    //int num_of_players = atoi(argv[1]); // переменная для задания количества игроков
    int num_of_players = 3; //число игроков(можно менять)
    int num_of_cards = num_of_players * 12;// количество карт в колоде которое будет
    int num_of_boom = num_of_players - 1;// количество взрывных котят в колоде (игроки - 1 согласно правилам)
    int num_of_defuse = num_of_players + 2; //количество карт обезвредить в игре(по правилам - игроков+2)
    int num_of_norm = num_of_cards - num_of_boom - num_of_defuse - num_of_players * 2; // количество карт без действия пока в колоде
    int num_of_start_card = 4;// количество обычных карт в руке на начало игры
    
    Debug debug;
    Action action;
    Create create;
    create.create_players(num_of_players, active_players); //создаем игроков
    create.create_card_neutral(num_of_norm, deck);  //создаем карты без действия
    create.create_card_future(num_of_players, deck);
    create.hand_filling(active_players, deck, num_of_start_card);// выдаем обычные карты
    create.create_card_defuse(num_of_defuse, deck, active_players); //создаем карты обезвредить
    create.create_card_bomb(num_of_boom, deck); //создаем бомбы
    create.mix_deck(deck); //размешиваем колоду карт
    debug.write_list_card_from_deck(deck); //вывод информации о картах в колоде
    debug.write_list_active_players(active_players); //вывод информации о созданных игрока

    while (active_players.size() != 1) //цикл игры основоной
    {
        Sleep(300); //пауза для наглядности
        if (deck.back().id_action == 1) //если наверху колоды взрыв
        {
            debug.write_took_card(active_players.back(), deck.back()); //вывод о том что игрок берет карту
            int i = 0; //счетчик какая карта в руке по счету
            bool flag = true; //взрывается ли игрок
            for (Card card : active_players.back().hand) //смотрим каждую карту в руке активного игрока
            {
                if (card.id_action == 2) //если обезвредить
                {
                    debug.write_player_defuse_info(active_players.back()); //играем её
                    action.card_in_hand(deck, active_players, card, i, active_players.size() - 1); //обработка сыгрывания карты
                    flag = false; //спаслись
                    debug.write_list_card_from_players(active_players.front()); //вывод карт в руке игрока
                    break; //перестаем смотреть карты
                }
                i++;//если не обезвредить то повысим счетчик
            }
            if (flag) //если не спаслись
            {
                action.get_card(active_players, deck.back(), active_players.size() - 1); //берем взрыв, умираем
                deck.pop_back(); //удаляем взрыв из колоды
            }
        }
        else
        {
            debug.write_took_card(active_players.back(), deck.back()); //берется карта
            action.get_card(active_players, deck.back(), active_players.size() - 1); //событие взятия карты
            deck.pop_back(); //убирается карта из колоды 
            debug.write_list_card_from_players(active_players.front()); //вывод карт в руке игрока
            
        }
    }
    debug.write_player_winner_info(active_players[0]);
    system("pause");
}
