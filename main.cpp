#include <iostream>
#include <fstream>
#include "Chessboard.hpp"
#include "Piece.hpp"
#include "GameInfo.h"
#include "ChessPosition.hpp"
//#include "tauler_1.txt"

using namespace std;

int main()
{

	Chessboard x;
	x.LoadBoardFromFile("tauler_1.txt");
	//x.LoadBoardFromFile("C:\Users\arnau\OneDrive\Escriptori\ajedrez\ajedrezprova.txt");
	x.ToString();
	cout << endl << endl;
	//x.mostraTauler();

	return 0;
}