#pragma once

#include "Piece.h"

class Qween : public Piece
{
public:

	// C'tor:
	Qween(string color, Squere location);
	// D'tor:
	~Qween();

	// Other methods:

	/* Checking the legality of the displacement according to the rules of the game. */
	void move(Board* board, Squere src, Squere dest, char* result);
};