#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "Board.h"

using namespace std;

class Board;

class Piece
{
public:

	// C'tors:
	Piece(string color, Squere location);
	Piece(string color, Squere location, bool itsPawn);
	// D'tor:
	virtual ~Piece();
	
	// Getters:
	string getColor() const;
	Squere getLocation() const;

	// Setters:
	void setLocation(const Squere location);

	// Other methods:

	/* Returns if a tool is pawn. */
	bool itsPawn();

	/* Returns if a tool(squere) is empty. */
	bool itsEmpty();

	/* Checking the legality of the displacement according to the rules of the game. */
	virtual void move(Board* board, Squere src, Squere dest, char* result) = 0;

protected:

	string _color;
	Squere _location;
	bool _itsPawn;
};