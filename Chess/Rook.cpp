#include "Rook.h"
#include "Board.h"

Rook::Rook(string color, Squere location) :
	Piece(color, location) {}

Rook::~Rook() {}

void Rook::move(Board* board, Squere src, Squere dest, char* result)
{
	Squere check(0, 0);
	int i = 0, min = 0, max = 0;
	bool flag = true, srcBigger = false;

	bool row = src.getRow() == dest.getRow();
	bool column = src.getColumn() == dest.getColumn();

	if (row OR column)
	{
		if (row)
		{
			check.setRow(src.getRow());
			srcBigger = src.getColumn() > dest.getColumn();
			min = srcBigger ? dest.getColumn() : src.getColumn();
			max = srcBigger ? src.getColumn() : dest.getColumn();
		}
		else
		{
			check.setColumn(src.getColumn());
			srcBigger = src.getRow() > dest.getRow();
			min = srcBigger ? dest.getRow() : src.getRow();
			max = srcBigger ? src.getRow() : dest.getRow();
		}

		for (i = min + 1; i < max && flag; i++)
		{
			row ? check.setColumn(i) : check.setRow(i);
			if (!board->getPiece(check)->itsEmpty())
			{
				strcpy(result, "6");
				flag = !flag;
			}
		}
	}
	else
	{
		strcpy(result, "6");
	}

	if (strcmp(result, "6"))
	{
		strcpy(result, "0");
	}
}