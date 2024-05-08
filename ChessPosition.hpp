#ifndef ChessPosition_hpp
#define ChessPosition_hpp

#include <stdio.h>
#include <string>
#include "Piece.hpp"
#include <vector>
#include "Piece.hpp"
#include "GameInfo.h"

using namespace std;


class ChessPosition {

public:

    //--------Constructors--------//
    ChessPosition(const string& x);
    ChessPosition() { m_posX = 0, m_posY = 0; }


    //--------Getters i Setters--------//
    void setX(int x) { m_posX = x; } //setter
    void setY(int y) { m_posY = y; } //setter
    int getX() const { return m_posX; } //getter
    int getY() const { return m_posY; } //getter
    void setChessPosition(const string& x); // Mètode string-->(x,y)


    //--------Operadors--------//
    bool operator==(const ChessPosition& posicio) const;

    //--------Funcions--------//
    bool existeix() const;

private:
    int m_posX; //Column Del 0-7
    int m_posY; //Row Del 0-7
};

ostream& operator<< (ostream& output, ChessPosition const& posicio);
#endif /* ChessPosition_hpp */

