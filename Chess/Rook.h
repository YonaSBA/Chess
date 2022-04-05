#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:

	// C'tor:
	Rook(string color, Squere location);
	// D'tor:
	~Rook();

	// Other methods:

	/* Checking the legality of the displacement according to the rules of the game. */
	void move(Board* board, Squere src, Squere dest, char* result);
};