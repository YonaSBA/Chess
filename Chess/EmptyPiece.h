#pragma once

#include "Piece.h"

class EmptyPiece : public Piece
{
public:

	// C'tor:
	EmptyPiece(string color, Squere location);
	// D'tor:
	~EmptyPiece();

	// Other methods:

	/* Checking the legality of the displacement according to the rules of the game. */
	void move(Board* board, Squere src, Squere dest, char* result);
};