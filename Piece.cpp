#include "Piece.hpp"
#include <string>
#include <iostream>
using namespace std;

void Piece::setColor(int x)
{
	//DESCRIPTION:
	//Aquest mètode inicialitza el color d´una peça a partir d´un codi ASCII.
	//
	//PARAMETERS:
	//x: codi ASCII que determina el color de la peça.
	//
	//RETURN:
	//Es un void, no retorna res.
	x = x - 48;
	switch (x)
	{
	case 0:
		m_color = CPC_White;
		break;

	case 1:
		m_color = CPC_Black;
		break;

	default:
		m_color = CPC_NONE;
		break;
	}
}

void Piece::setTipus(char x)
{
	//DESCRIPTION:
	//Aquest mètode inicialitza el tipus de la peça a partir d´un caracter.
	//
	//PARAMETERS:
	//x: caracter que determina el tipus de la peça.
	//
	//RETURN:
	//Es un void, no retorna res.
	switch (x)
	{
	case 'R':
		m_type = CPT_King;
		break;

	case 'D':
		m_type = CPT_Queen;
		break;

	case 'T':
		m_type = CPT_Rook;
		break;

	case 'A':
		m_type = CPT_Bishop;
		break;

	case 'C':
		m_type = CPT_Knight;
		break;

	case 'P':
		m_type = CPT_Pawn;
		break;

	default:
		m_type = CPT_EMPTY;
	}
}

Piece& Piece::operator=(const Piece& piece)
{
	//DESCRIPTION:
	//Aquest operador s´encarrega de poder igualar una peça a l´altre, transferint tota la informació de la segona a la primera.
	//
	//PARAMETERS:
	//piece: membre de la clase Piece que conté la informació a transmetre a la primera peça.
	//
	//RETURN:
	//Retorna la primera peça modificada.
	if (&piece != this)
	{
		m_color = piece.m_color;
		m_type = piece.m_type;

	}
	return *this;
}




