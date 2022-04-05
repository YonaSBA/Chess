#include "Qween.h"
#include "Bishop.h"
#include "Rook.h"

Qween::Qween(string color, Squere location) :
	Piece(color, location) {}

Qween::~Qween() {}

void Qween::move(Board* board, Squere src, Squere dest, char* result)
{
	Rook qweenR(_color, _location);
	Bishop qweenB(_color, _location);
	char resultR[2] = { 0 }, resultB[2] = { 0 };

	qweenR.move(board, src, dest, resultR);
	qweenB.move(board, src, dest, resultB);

	if (!strcmp(resultB, "0") OR !strcmp(resultR, "0"))
	{
		strcpy(result, "0");
	}
	else
	{
		strcpy(result, "6");
	}

	qweenR.~Rook();
	qweenB.~Bishop();
}