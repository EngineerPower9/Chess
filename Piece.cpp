#include "Piece.hpp"
#include <string>
#include <iostream>
using namespace std;

void Piece::setColor(int x)
{
	//DESCRIPTION:
	//Aquest m�tode inicialitza el color d�una pe�a a partir d�un codi ASCII.
	//
	//PARAMETERS:
	//x: codi ASCII que determina el color de la pe�a.
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
	//Aquest m�tode inicialitza el tipus de la pe�a a partir d�un caracter.
	//
	//PARAMETERS:
	//x: caracter que determina el tipus de la pe�a.
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
	//Aquest operador s�encarrega de poder igualar una pe�a a l�altre, transferint tota la informaci� de la segona a la primera.
	//
	//PARAMETERS:
	//piece: membre de la clase Piece que cont� la informaci� a transmetre a la primera pe�a.
	//
	//RETURN:
	//Retorna la primera pe�a modificada.
	if (&piece != this)
	{
		m_color = piece.m_color;
		m_type = piece.m_type;

	}
	return *this;
}




