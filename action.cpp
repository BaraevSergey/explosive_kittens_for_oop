#include "action.h"
#include "debug.h"

void Action::action_card(vector<Player>& Players, Player Active_Player, Card card)
#include <ctime>

void Action::get_card(vector<Player>& Players, Card card, int n)
{
    // n - ïîçèöèÿ èãðîêà â ñïèñêå àêòèâíûõ èãðîêîâ
    Debug debug;
    switch (card.id_action)
    {
    case 0: //íè÷åãî
    case 2:
    {
        Players[n].hand.push_back(card);
        Player temp = Players[n];
        Players.erase(Players.begin() + n); // ïåðåíîñ èãðîêà â íà÷àëî âåêòîðà àêòèâíûõ èãðîêîâ
        Players.insert(Players.begin(), temp);
    }
    break;
    case 1: //êîòåíîê
    {
        debug.write_player_boom_info(Players[n]);
        Players.erase(Players.begin() + n);
        break;
    }
    
    default:
        break;
    }
}

void Action::card_in_hand(vector <Card>& deck, vector<Player>& Players, Card card, int nc, int np)
{
    // nc - èíäåêñ êàðòû â ðóêå
    // np - ïîçèöèÿ èãðîêà â ñïèñêå àêòèâíûõ èãðîêîâ
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
        if (deck.size() > 1) // åñëè â êîëîäå áîëüøå îäíîé êàðòû, òî çàìåøèâàåì âçðûâíóþ â ðàíäîìíîå ìåñòî
            {
                deck.pop_back(); //óäàëÿåì âçðûâíóþ êàðòó èç îñíîâíîé êîëîäû
                deck.insert(deck.begin() + rand() % deck.size(), temp_card); // çàìåøèâàåì âçðûâíóþ êàðòó â êîëîäó
            }
        Players[np].hand.erase(Players[np].hand.begin() + nc); // óäàëåíèå îáåçâðåäà èç ðóêè
        Player temp = Players[np];
        Players.erase(Players.begin() + np); // ïåðåíîñ èãðîêà â íà÷àëî âåêòîðà àêòèâíûõ èãðîêîâ
        Players.insert(Players.begin(), temp);
    }
    default:
        break;
    }
}