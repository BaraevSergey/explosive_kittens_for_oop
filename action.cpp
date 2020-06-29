#include "action.h"
#include "debug.h"
#include <ctime>

void Action::get_card(vector<Player>& Players, Card card, int n)
{
    /*
    Players - ������ ������� ��������
    card - �����, ������� ����� �����
    n - ������ ������ � ������ ��������, ������� ����� �����
    */
    Debug debug;
    switch (card.id_action) //������� id �������� �����
    {
    case 0: //���� �������
    case 2: //���� �����������
    case 3: //���� ������
    case 4: //���� ���������� � �������
    {
        Players[n].hand.push_back(card); //������ ������ � ���� ������
        Player temp = Players[n]; //����� ������ ������� �����
        Players.erase(Players.begin() + n); // ��������� ����� ������ � ������ ������� �������� �������
        Players.insert(Players.begin(), temp); //������� �� ����� ������� ���
    }
    break;
    case 1: //���� ����� ������
    {
        debug.write_player_boom_info(Players[n]); //������� ���������� � ������ ������
        Players.erase(Players.begin() + n); //������� ��� �� ������ ��������
        break;
    }
    default:
        break;
    }
}

void Action::card_in_hand(vector <Card>& deck, vector<Player>& Players, Card card, int nc, int np)
{
    /*
    deck - ������ ����
    Players - ������ ������� ��������
    card - �����, ������� ����� �����
    nc - ������ ����� � ���� ������
    np - ������ ������ � ������ ��������
    */
    switch (card.id_action) //������� �������� ����� ������� �����
    {
    case 0: //���� �������
    case 1: //�������(�� ���� �� ������ ���� ���� �������)
        break; //������ �� ������ ����
    case 2: // ���� ������� ����� �����������
    {
        srand(time(0)); //������ ����������� 
        Card temp_card; 
        temp_card = deck.back(); //����� ��������� ����� �� ������(�����) ��� �����������
        if (deck.size() > 1) // ������� �� ������, ���� ������� ������ ���� ����� � ������, ����� ������������� �� �����
            {
                deck.pop_back(); //������� �������� ����� �� �������� ������
                deck.insert(deck.begin() + rand() % deck.size(), temp_card); // ���������� �������� ����� � ������ � ��������� �����
            }
        Players[np].hand.erase(Players[np].hand.begin() + nc); // �������� � ������ ����� ��������������
        Player temp = Players[np]; 
        Players.erase(Players.begin() + np);  //������� ������ � �����
        Players.insert(Players.begin(), temp); //������ � ������ ��� 
    }
    default:
        break;
    }
}