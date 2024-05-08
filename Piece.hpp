#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <vector>
#include "GameInfo.h"
using namespace std;

//Tipus de peces
typedef enum {
    CPT_King,
    CPT_Queen,
    CPT_Rook,
    CPT_Bishop,
    CPT_Knight,
    CPT_Pawn,
    CPT_EMPTY
} ChessPieceType;

//Colors possible a cada casella
typedef enum {
    CPC_White,
    CPC_Black,
    CPC_NONE
} ChessPieceColor;


class Piece {

public:
    Piece() { m_type = CPT_EMPTY, m_color = CPC_NONE; } //Constructor per inicialitzar la peça

    void setTipus(char x); //setter 1.1
    void setTipus(const ChessPieceType& x) { m_type = x; } //setter 1.2
    void setColor(int x); //setter 2.1
    void setColor(ChessPieceColor x) { m_color = x; } //setter 2.2

    ChessPieceType getTipus() const { return m_type; } //getter
    ChessPieceColor getColor() const { return m_color; } //getter

    Piece& operator=(const Piece& piece); //Operador "=" per a peces

private:
    ChessPieceType  m_type; //Tipus de peça
    ChessPieceColor m_color; //Colors de la peça
};


#endif /* Piece_hpp */
