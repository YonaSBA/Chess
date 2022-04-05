#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:

	// C'tor:
	Knight(string color, Squere location);
	// D'tor:
	~Knight();
	
	// Other methods:

	/* Checking the legality of the displacement according to the rules of the game. */
	void move(Board* board, Squere src, Squere dest, char* result);
};