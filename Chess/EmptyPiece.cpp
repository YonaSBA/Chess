#include "EmptyPiece.h"

EmptyPiece::EmptyPiece(string color, Squere location) :
	Piece(color, location) {}

EmptyPiece::~EmptyPiece() {}

void EmptyPiece::move(Board* board, Squere src, Squere dest, char* result)
{
	strcpy(result, "2");
}