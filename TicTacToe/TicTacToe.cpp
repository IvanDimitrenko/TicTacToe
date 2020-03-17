#include<iostream>
#include<conio.h>
using namespace std;
const int r = 5; const int c = 5;
int turne = 0;
int player1, player2;
bool game = true;
char arr[c][r];
bool CONTROL();
void WALK();
void Start();
void Game();
void newgame();
void Print();
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "************************************************************\n"
		<< "******************** крестики и нолики *********************\n"
		<< "************************************************************\n\n \t version 0.1 , Patch 0.2\n \n";
	cout << "choose whose turne first\nplayer1 - X \nplayer2 - O\n\n  ";
	system("pause");
	system("cls");
	Print();

}
void WALK()
{
	char walk;
	turne % 2 == 1 ? walk = 'X' : walk = 'O';
	cout << endl << "Turn " << walk << endl << "counter: " << turne << endl;
	char play = _getch();

	switch (play)
{

	case '1': arr[4][0] = walk; break;
	case '2': arr[4][2] = walk; break;
	case '3': arr[4][4] = walk; break;
	case '4': arr[2][0] = walk; break;
	case '5': arr[2][2] = walk; break;
	case '6': arr[2][4] = walk; break;
	case '7': arr[0][0] = walk; break;
	case '8': arr[0][2] = walk; break;
	case '9': arr[0][4] = walk; break;
	default:
	{
		return WALK();
	}
}

}
void Start()
{
	for (int i = 0; i < c; i++)
	{
		cout << "\t    ";
		for (int y = 0; y < r; y++)
		{
			cout << arr[i][y];
		}
		cout << endl;
	}
	cout << "player1: " << player1 << " --vs-- " << player2 << " :player2" << endl;
	WALK();
	system("cls");

}

void Game()
{
	do
	{
		turne++;
		if (turne > 5)
		{
			game = CONTROL();
		}
		if (game == false)
		{
			turne % 2 == 1 ? player2++ : player1++;
			newgame();
		}
		if (turne >= 10)
		{
			newgame();
		}

		Start();
	} while (true);
}
bool CONTROL()
{
		if (arr[0][0] == arr[0][2] && arr[0][2] == arr[0][4] && arr[0][0] == 'X')
			return false;
		if (arr[2][0] == arr[2][2] && arr[2][2] == arr[2][4] && arr[2][0] == 'X')// кастиль который убрал почти все баги, я делал через цикл та куча багов
			return false;																// было не возможно играть
		if (arr[4][0] == arr[4][2] && arr[4][2] == arr[4][4] && arr[4][0] == 'X')// горизонталь
			return false;
		if (arr[0][0] == arr[0][2] && arr[0][2] == arr[0][4] && arr[0][0] == 'O')
			return false;
		if (arr[2][0] == arr[2][2] && arr[2][2] == arr[2][4] && arr[2][0] == 'O')
			return false;
		if (arr[4][0] == arr[4][2] && arr[4][2] == arr[4][4] && arr[4][0] == 'O')
			return false;

	for (int i = 0; i < 4; i += 2)
	 if (arr[0][i] == arr[2][i] && arr[2][i] == arr[4][i]) // цикл по вертекале
			return false;
		
	if (arr[0][0] == arr[2][2] && arr[2][2] == arr[4][4])
	{
		return false;
	}
	if (arr[4][0] == arr[2][2] && arr[2][2] == arr[0][4])// диагонали 
	{
		return false;
	}
	return true;
}
void newgame()
{
	game = true;
	turne = 0;
	return Print();
}
void Print()
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (i == 0 || i == 2 || i == 4)
				j % 2 == 0 ? arr[i][j] = ' ' : arr[i][j] = '|';
			if (i == 1 || i == 3)
				j % 2 == 0 ? arr[i][j] = '-' : arr[i][j] = '+';
		}
	}
	Game();
}