#include "Knight.h"

Knight::Knight(string color, Squere location) :
	Piece(color, location) {}

Knight::~Knight() {}

void Knight::move(Board* board, Squere src, Squere dest, char* result)
{
	if (abs(dest.getRow() - src.getRow()) == 2 AND abs(dest.getColumn() - src.getColumn()) == 1 OR
		abs(dest.getRow() - src.getRow()) == 1 AND abs(dest.getColumn() - src.getColumn()) == 2)
	{
		strcpy(result, "0");
	}
	else
	{
		strcpy(result, "6");
	}
}