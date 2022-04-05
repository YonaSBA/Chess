#include "King.h"
#include "Game.h"

King::King(string color, Squere location) :
	Piece(color, location) {}

King::~King() {}

void King::move(Board* board, Squere src, Squere dest, char* result) 
{
	if ((src.getRow() == dest.getRow() + 1 AND src.getColumn() == dest.getColumn() OR
		 src.getRow() == dest.getRow() - 1 AND src.getColumn() == dest.getColumn() OR
		 src.getRow() == dest.getRow() AND src.getColumn() == dest.getColumn() + 1 OR
		 src.getRow() == dest.getRow() AND src.getColumn() == dest.getColumn() - 1 OR
		 src.getRow() == dest.getRow() + 1 AND src.getColumn() == dest.getColumn() + 1 OR
		 src.getRow() == dest.getRow() - 1 AND src.getColumn() == dest.getColumn() - 1 OR
		 src.getRow() == dest.getRow() + 1 AND src.getColumn() == dest.getColumn() - 1 OR
		 src.getRow() == dest.getRow() - 1 AND src.getColumn() == dest.getColumn() + 1))
	{
		strcpy(result, "0");
	}
	else
	{
		strcpy(result, "6");
	}
}