#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:

	// C'tor:
	Pawn(string color, Squere location);
	// D'tor:
	~Pawn();

	// Other methods:

	/* Checking the legality of the displacement according to the rules of the game. */
	void move(Board* board, Squere src, Squere dest, char* result);

private:

	int _pawn;
	static int _pawns;
};