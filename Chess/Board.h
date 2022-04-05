#pragma once

#include "Squere.h"
#include "Piece.h"
#include <vector>

#define KINGS 2
#define PAWNS 16

class Piece;

class Board
{
public:

	// C'tors:
	Board();														
	Board(Piece* Pieces[][RIB]);									
	// D'tor:
	~Board();														

	// Getters:
	Board* getBoard();
	bool getPawnFirstStep(int pawn);
	Piece* getPiece(Squere location) const;
	Squere getKingLoacation(bool color) const;

	// Setters:
	void setPawnFirstStep(const int pawn, const bool first);
	void setPawnFirstSteps(const bool pawnsfirstSteps[PAWNS]);
	void setKingLoacation(const bool color, const Squere location);

	// Operators overloading:
	Board& operator=(const Board& other);

	// Other methods:

	/* Checks if a tool in the squere belongs to the player whose turn it is to play. */
	bool itsMe(Board* board, Squere location, string color);		

	/* Switches between two tool locations. */
	void swap(Squere src, Squere dest);

	/* The eating (removal, swaping and creating an empty tool instead, returns the tool that eaten) function and its cancellation. */
	Piece* eat(Squere src, Squere dest);
	void cancel(Squere src, Squere dest, Piece* p);

private:

	Piece* _pieces[RIB][RIB];
	Squere _kingLocation[KINGS];
	bool _pawnsFirstSteps[PAWNS];
};