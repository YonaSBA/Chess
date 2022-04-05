#include "Squere.h"

Squere::Squere() :
	_row(0), _column(0) {}

Squere::Squere(int row, int column) :
	_row(row), _column(column) {}

Squere::Squere(const string location) :
	_row(8 - stoi(string(1, location[1]))), _column((int)char(location[0]) - LETTER_TO_NUM - 1) {}

Squere::~Squere() {}

int Squere::getRow() const
{
	return _row;
}

int Squere::getColumn() const
{
	return _column;
}

void Squere::setRow(const int row)
{
	_row = row;
}

void Squere::setColumn(const int column)
{
	_column = column;
}

bool Squere::itsValid()
{
	return getColumn() >= 0 AND getColumn() < RIB AND getRow() >= 0 AND getRow() < RIB;
}

Squere& Squere::operator=(const Squere& other)
{
	_row = other._row;
	_column = other._column;
	return *this;
}

bool operator==(const Squere& me, const Squere& other)
{
	return me._row == other._row AND me._column == other._column;
}