
#include "Chessboard.hpp"
#include "Piece.hpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>


using namespace std;


//---------Constructors---------//

Chessboard::Chessboard()
{
	//DESCRIPTION:
	//Aquest constructor inicialitza el tauler a una peça gènerica temporal
	// 
	//PARAMETERS:
	//Cap necessari
	//
	//RETURN:
	//No retorna res, nomès inicialitza cada posicio a una peça gènerica
	for (int i = 0; i < NUM_COLS; i++)
	{
		for (int j = 0; j < NUM_ROWS; j++)
		{
			m_board[i][j] = Piece();
		}
	}
}


//---------Necessari caronte---------//

ChessPieceColor Chessboard::GetPieceColorAtPos(const ChessPosition& pos) const //Obté el color d'una peça en una posicio X
{
	return(m_board[pos.getX()][pos.getY()].getColor());
}

ChessPieceType Chessboard::GetPieceTypeAtPos(const ChessPosition& pos) const //Obté el tipus d'una peça en una posicio X
{
	return(m_board[pos.getX()][pos.getY()].getTipus());
}


//---------Funcions---------//

bool existeix(int x, int y) //Esta aquí per un error molt raro on x = 8 i columnes = 8 diu que x < Columnes = false;
{
	if (x < NUM_COLS && x >= 0)
	{
		if (y < NUM_ROWS && y >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void Chessboard::setPiece(const Piece& piece, const ChessPosition& posicio)
//DESCRIPTION:
//Aquest Mètode de Chessboard col·loca una peça en una posicio determinada
// 
//PARAMETERS:
//piece: peça a col·locar
//posicio: posició on col·locar la peça
//
//RETURN:
//No retorna res, nomès assigna una peça a una posicio concreta del tauler/array.
{
	m_board[posicio.getX()][posicio.getY()] = piece;
} //

void Chessboard::LoadBoardFromFile(const string& path) //Carrega un txt de posicions
{
	ifstream fitxer;
	fitxer.open(path);

	if (fitxer.is_open())
	{
		Piece piece1;
		ChessPosition piecePosition;
		string h;
		string i;

		fitxer >> h >> i;
		piece1.setTipus(i[0]);
		piece1.setColor(h[0]);
		while (!fitxer.eof())
		{
			setPiece(piece1, ChessPosition(i.substr(1, 2)));
			fitxer >> h >> i;
			piece1.setTipus(i[0]);
			piece1.setColor(h[0]);
		}

		setPiece(piece1, ChessPosition(i.substr(1, 2)));
		fitxer >> h >> i;
		piece1.setTipus(i[0]);
		piece1.setColor(h[0]);

		fitxer.close();

	}
}

VecOfPositions  Chessboard::GetValidMoves(const ChessPosition& pos) const //Obtenim tots els moviments vàlids de una peça en una posició donada
{
	vector <ChessPosition> moviments_valids;
	moviments_valids.resize(0);

	int x = pos.getX();
	int y = pos.getY();

	int i[8] = { 2, 2, -2, -2, 1,  1, -1, -1 }; //Moviments X Cavall
	int j[8] = { 1, -1, 1, -1, 2, -2,  2, -2 }; //Moviments Y Cavall

	int reiX[8] = { 1,  1, -1, -1, 1, -1,  0,  0 }; //Moviments X Rei
	int reiY[8] = { 1, -1,  1, -1, 0,  0,  1, -1 }; //Moviments Y Rei

	bool trobat = false;

	ChessPosition generic;
	ChessPieceType pesa = m_board[x][y].getTipus();
	ChessPieceColor color = m_board[x][y].getColor();

	switch (pesa)
	{
		//-----------Rei-----------//

	case CPT_King:
		x = pos.getX();
		y = pos.getY();

		for (int r = 0; r < 8; r++)
		{

			generic.setX(x + reiX[r]);
			generic.setY(y + reiY[r]);

			if ((generic.existeix() == true) && (m_board[x + reiX[r]][y + reiY[r]].getColor() != color))
			{
				moviments_valids.push_back(generic);
			}
		}
		break;


		//-----------Reina-----------//

	case CPT_Queen:

		//---Files---//
		x = pos.getX() + 1;
		y = pos.getY();
		while ((x < NUM_COLS) && (trobat == false))
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);

			}
			x++;
		}
		trobat = false;

		x = pos.getX() - 1;
		y = pos.getY();
		while (x >= 0 && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				if (generic.existeix() == true)
				{
					moviments_valids.push_back(generic);
				}
			}
			x--;
		}
		trobat = false;

		//---Columnes---//
		x = pos.getX();
		y = pos.getY() - 1;
		while (y >= 0 && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					if (generic.existeix() == true)
					{
						if (generic.existeix() == true)
						{
							moviments_valids.push_back(generic);
						}
					}
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				if (generic.existeix() == true)
				{
					moviments_valids.push_back(generic);
				}
				y--;
			}
		}
		trobat = false;

		x = pos.getX();
		y = pos.getY() + 1;
		while (y < NUM_ROWS && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			y++;
		}
		trobat = false;

		//---Diagonals---//
		x = pos.getX() + 1;
		y = pos.getY() + 1;
		while (((x < NUM_COLS) && (y < NUM_ROWS)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x++;
			y++;
		}
		trobat = false;

		x = pos.getX() - 1;
		y = pos.getY() - 1;
		while (((x >= 0) && (y >= 0)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x--;
			y--;
		}
		trobat = false;

		x = pos.getX() + 1;
		y = pos.getY() - 1;
		while (((x < NUM_COLS) && (y >= 0)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
				break;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x++;
			y--;
		}
		trobat = false;

		x = pos.getX() - 1;
		y = pos.getY() + 1;
		while (((x >= 0) && (y < NUM_ROWS)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
				break;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x--;
			y++;
		}
		trobat = false;

		break;


		//-----------Torre-----------//

	case CPT_Rook:
		//---Files---//
		x = pos.getX() + 1;
		y = pos.getY();
		while ((x < NUM_COLS) && (trobat == false))
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);

			}
			x++;
		}
		trobat = false;

		x = pos.getX() - 1;
		y = pos.getY();
		while (x >= 0 && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				if (generic.existeix() == true)
				{
					moviments_valids.push_back(generic);
				}
			}
			x--;
		}
		trobat = false;

		//---Columnes---//
		x = pos.getX();
		y = pos.getY() - 1;
		while (y >= 0 && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					if (generic.existeix() == true)
					{
						if (generic.existeix() == true)
						{
							moviments_valids.push_back(generic);
						}
					}
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				if (generic.existeix() == true)
				{
					moviments_valids.push_back(generic);
				}
				y--;
			}
		}
		trobat = false;

		x = pos.getX();
		y = pos.getY() + 1;
		while (y < NUM_ROWS && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			y++;
		}
		trobat = false;

		break;


		//----------|Alfil|----------//

	case CPT_Bishop:
		//---Diagonals---//
		x = pos.getX() + 1;
		y = pos.getY() + 1;
		while (((x < NUM_COLS) && (y < NUM_ROWS)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x++;
			y++;
		}
		trobat = false;

		x = pos.getX() - 1;
		y = pos.getY() - 1;
		while (((x >= 0) && (y >= 0)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x--;
			y--;
		}
		trobat = false;

		x = pos.getX() + 1;
		y = pos.getY() - 1;
		while (((x < NUM_COLS) && (y >= 0)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
				break;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x++;
			y--;
		}
		trobat = false;

		x = pos.getX() - 1;
		y = pos.getY() + 1;
		while (((x >= 0) && (y < NUM_ROWS)) && trobat == false)
		{
			if (m_board[x][y].getTipus() != CPT_EMPTY)
			{
				if (m_board[x][y].getColor() != color)
				{
					generic.setX(x);
					generic.setY(y);
					moviments_valids.push_back(generic);
				}
				trobat = true;
				break;
			}
			else
			{
				generic.setX(x);
				generic.setY(y);
				moviments_valids.push_back(generic);
			}
			x--;
			y++;
		}
		trobat = false;

		break;


		//-----------Cavall-----------//

	case CPT_Knight:

		x = pos.getX();
		y = pos.getY();

		for (int r = 0; r < 8; r++)
		{

			generic.setX(x + i[r]);
			generic.setY(y + j[r]);

			if ((generic.existeix() == true) && (m_board[x + i[r]][y + j[r]].getColor() != color))
			{
				moviments_valids.push_back(generic);
			}
		}
		break;


		//-----------Peo-----------//

	case CPT_Pawn:
		if (color == CPC_Black)
		{
			//----Avanç----//
			if (m_board[x][y - 1].getTipus() == CPT_EMPTY)
			{
				generic.setX(x);
				generic.setY(y - 1);
				moviments_valids.push_back(generic);

				if ((m_board[x][y - 2].getTipus() == CPT_EMPTY) && (y == 6))
				{
					generic.setX(x);
					generic.setY(y - 2);
					moviments_valids.push_back(generic);
				}
			}


			//----Captures----//
			generic.setX(x + 1);
			generic.setY(y - 1);
			if (m_board[x + 1][y - 1].getColor() == CPC_White && generic.existeix() == true)
			{
				moviments_valids.push_back(generic);
			}

			generic.setX(x - 1);
			generic.setY(y - 1);
			if (m_board[x - 1][y - 1].getColor() == CPC_White && generic.existeix() == true)
			{
				moviments_valids.push_back(generic);
			}
			break;
		}
		else if (color == CPC_White)
		{
			//----Avanç----//
			if (m_board[x][y + 1].getTipus() == CPT_EMPTY)
			{
				generic.setX(x);
				generic.setY(y + 1);
				moviments_valids.push_back(generic);

				if ((m_board[x][y + 2].getTipus() == CPT_EMPTY) && (y == 1))
				{
					generic.setX(x);
					generic.setY(y + 2);
					moviments_valids.push_back(generic);
				}
			}

			//----Captures----//
			generic.setX(x + 1);
			generic.setY(y + 1);
			if (m_board[x + 1][y + 1].getColor() == CPC_Black && generic.existeix() == true)
			{
				moviments_valids.push_back(generic);
			}

			generic.setX(x - 1);
			generic.setY(y - 1);
			if (m_board[x - 1][y + 1].getColor() == CPC_Black && generic.existeix() == true)
			{
				moviments_valids.push_back(generic);
			}
			break;
		}
	}
	return moviments_valids;
}

bool Chessboard::MovePiece(const ChessPosition& posFrom, ChessPosition& posTo) //Mou una peça d'una posició a una altra tenint en compte la resta
{
	Piece piece;
	Piece buit;

	for (int i = 0; i < size(GetValidMoves(posFrom)); i++)
	{
		if (GetValidMoves(posFrom)[i] == posTo)
		{
			piece = m_board[posFrom.getX()][posFrom.getY()];
			m_board[posFrom.getX()][posFrom.getY()] = buit;
			m_board[posTo.getX()][posTo.getY()] = piece;

			return true;
		}
	}
	return false;
}

string Chessboard::ToString() const	//Converteix el tauler en una string fàcilment visible
{
	string final;
	ChessPieceType tipus;

	for (int i = NUM_COLS - 1; i >= 0; i--)
	{
		cout << (i + 1);
		final.append("i + 1");

		for (int j = 0; j < NUM_ROWS; j++)
		{
			if (m_board[j][i].getTipus() == CPT_EMPTY)
			{
				cout << "__";
				final.append("__");
			}
			else
			{
				if (m_board[j][i].getColor() == CPC_White)
				{
					cout << "w";
					final.append("w");
				}
				else
				{
					cout << "b";
					final.append("b");
				}

				tipus = m_board[j][i].getTipus();

				switch (tipus)
				{
				case CPT_King:
					cout << "R";
					final.append("R");
					break;

				case CPT_Queen:
					cout << "D";
					final.append("D");
					break;

				case CPT_Rook:
					cout << "T";
					final.append("T");
					break;

				case CPT_Bishop:
					cout << "A";
					final.append("A");
					break;

				case CPT_Knight:
					cout << "C";
					final.append("C");
					break;

				case CPT_Pawn:
					cout << "P";
					final.append("P");
					break;

				default:
					cout << "ERROR";
					final.append("ERROR");
					break;
				}
			}
			cout << " ";
			final.append(" ");
		}
		cout << endl;
		final.append("\n");
	}

	
	cout << (" a  b  c  d  e  f  g  h") << endl;
	final.append(" a  b  c  d  e  f  g  h");
	

	return final;

}

