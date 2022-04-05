#include "Bishop.h"

Bishop::Bishop(string color, Squere location) :
	Piece(color, location) {}

Bishop::~Bishop() {} 

void Bishop::move(Board* board, Squere src, Squere dest, char* result)
{
	int i = 0;
	bool flag = true;
	Squere check(0, 0);
	
	bool srcColumnIsBigger = src.getColumn() > dest.getColumn();
	bool srcRowIsBigger = src.getRow() > dest.getRow();

	int maxRow = srcRowIsBigger ? src.getRow() : dest.getRow();
	int minRow = srcRowIsBigger ? dest.getRow() : src.getRow();

	int column = srcRowIsBigger ? dest.getColumn() : src.getColumn();

	if (abs(dest.getRow() - src.getRow()) == abs(dest.getColumn() - src.getColumn()))
	{
		for (i = minRow + 1; i < maxRow && flag; i++)
		{
			srcColumnIsBigger AND srcRowIsBigger OR !srcColumnIsBigger AND !srcRowIsBigger ? column++ : column--;

			check.setRow(i);
			check.setColumn(column);

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