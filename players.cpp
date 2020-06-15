// класс игороков
#include <vector>
using namespace std;
class Player
{
	string name;
	vector <Card> hand; // Вектор из объектов класса card. Содержит карты, принадлежащие игроку.
	
	public: Player(string input)
	{
		name = input;
	}

}