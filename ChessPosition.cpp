#include "ChessPosition.hpp"
#include "GameInfo.h"
#include "Piece.hpp"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;


/* Coordinate system:
    Y (rows)
  . ^
  . |  ***Black***
  4 |
  3 |
  2 |
  1 |  ***White***
 (0,0)----------> X (cols)
      a b c ...
*/

//---------Operadors---------//
bool ChessPosition::operator==(const ChessPosition& posicio) const
{
    if ((m_posX == posicio.getX()) && (m_posY == posicio.getY()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& output, ChessPosition const& posicio)
{
    char x;
    switch (posicio.getX())
    {
    case 0:
        x = 'a';
        break;
    case 1:
        x = 'b';
        break;
    case 2:
        x = 'c';
        break;
    case 3:
        x = 'd';
        break;
    case 4:
        x = 'e';
        break;
    case 5:
        x = 'f';
        break;
    case 6:
        x = 'g';
        break;
    case 7:
        x = 'h';
        break;
    default:
        x = 'E';
    }
    output << x << posicio.getY() + 1;
    return output;
}


//---------Funcions---------//

ChessPosition::ChessPosition(const string& x)
{
    //DESCRIPTION:
    //Aquest constructor inicialitza una posició a partir d´un string. Convert els valors del string a int.
    // 
    //
    //PARAMETERS:
    //X: string que conté la posició del txt d´una jugada.
    //
    //RETURN:
    //No retorna res, nomès crea una posició amb X i Y determinada per la string.


    m_posX = x[0] - 97;
    m_posY = x[1] - 49;
}

void ChessPosition::setChessPosition(const string& x)
{
    //DESCRIPTION:
    //Aquest métode inicialitza la x i la y en funció del valor d´un string.
    //
    //PARAMETERS:
    //X: string que conté la posició del txt d´una jugada.
    //
    //RETURN:
    //No retorna res, nomès inicialitza la x i la y d´una ChessPosition.

    m_posX = x[0] - 97;
    m_posY = x[1] - 49;
}

bool ChessPosition::existeix() const
{
    int x = m_posX;
    int y = m_posY;

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

