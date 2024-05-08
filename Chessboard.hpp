#ifndef Chessboard_hpp
#define Chessboard_hpp

#include <stdio.h>
#include <vector>
#include "Piece.hpp"
#include "GameInfo.h"
#include "ChessPosition.hpp"

//MALOOOOO

//Vector de posicions on en guardarem algunes del m�tode GetValidMoves
typedef vector<ChessPosition> VecOfPositions;


class Chessboard {

public:
    //-------Constructors-------//
    Chessboard(); //Inicialitza el tauler


    //---------Principal---------//
    void            setPiece(const Piece& piece, const ChessPosition& pos);             //Col�loca una pe�a en una posicio determinada
    void            LoadBoardFromFile(const string& path);                              //C�rrega la posicio de les peces guardades en un txt
    VecOfPositions  GetValidMoves(const ChessPosition& pos) const;                     //Dona els moviments v�lids d'una pe�a en una posici� X
    bool            MovePiece(const ChessPosition& posFrom, ChessPosition& posTo);     //Mou una pe�a d'una posicio a una altra
    string          ToString() const;                                                  //Converteix el tauler en una string 
    Piece           getCasella(int x, int y) const { return m_board[x][y]; }

    //------Necessari Caronte------//
    ChessPieceColor GetPieceColorAtPos(const ChessPosition& pos) const; //
    ChessPieceType GetPieceTypeAtPos(const ChessPosition& pos) const;


private:
    Piece m_board[NUM_COLS][NUM_ROWS]; //Tauler bidimensional  8*8
};
#endif /* Chessboard_hpp */
