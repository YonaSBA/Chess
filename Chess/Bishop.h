#pragma once

#include "Piece.h"
#include <cmath>

class Bishop : public Piece
{
public:

	// C'tor:
	Bishop(string color, Squere location);
	// D'tor:
	~Bishop();

	// Other methods:
	
	/* Checking the legality of the displacement according to the rules of the game. */
	void move(Board* board, Squere src, Squere dest, char* result);
};