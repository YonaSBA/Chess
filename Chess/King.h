#pragma once

#include "Piece.h"

class King : public Piece
{
public:

	// C'tor:
	King(string color, Squere location);
	// D'tor:
	~King();

	// Other methods:

	/* Checking the legality of the displacement according to the rules of the game. */
	void move(Board* board, Squere src, Squere dest, char* result);
};