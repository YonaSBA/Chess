#include "Pawn.h"

int Pawn::_pawns = 0;

Pawn::Pawn(string color, Squere location) :
	Piece(color, location, true) , _pawn(_pawns++) {}

Pawn::~Pawn() {}

void Pawn::move(Board* board, Squere src, Squere dest, char* result)
{
	string b = "black";

	bool itsBlack = !b.compare(getColor());
	bool itsEmpty = board->getPiece(dest)->itsEmpty();
	bool itsEat = abs(dest.getColumn() - src.getColumn()) == 1 AND !itsEmpty;

	if ((src.getColumn() == dest.getColumn() AND itsEmpty) OR itsEat)
	{
		if (itsBlack AND src.getRow() + 1 == dest.getRow() OR
		   !itsBlack AND src.getRow() - 1 == dest.getRow())
		{
			itsEat ? strcpy(result, "9") : strcpy(result, "0");
		}
		else
		{
			strcpy(result, "6");
		}

		if (board->getPawnFirstStep(_pawn))
		{
			if (!strcmp(result, "6") AND
			(((itsBlack AND src.getRow() + 2 == dest.getRow() AND board->getPiece(Squere(src.getRow() + 1, src.getColumn()))->itsEmpty()) OR
			(!itsBlack AND src.getRow() - 2 == dest.getRow() AND board->getPiece(Squere(src.getRow() - 1, src.getColumn()))->itsEmpty()))))
			{
				strcpy(result, "0");
			}

			board->setPawnFirstStep(_pawn, false);
		}
	}
	else
	{
		strcpy(result, "6");
	}
}