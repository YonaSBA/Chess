#include "Piece.h"

Piece::Piece(string color, Squere location) :
	_color(color), _location(location), _itsPawn(false) {}

Piece::Piece(string color, Squere location, bool itsPawn) :
	_color(color), _location(location), _itsPawn(itsPawn) {}

Piece::~Piece() {}

string Piece::getColor() const
{
	return _color;
}

Squere Piece::getLocation() const
{
	return _location;
}

void Piece::setLocation(Squere location)
{
	_location = location;
}

bool Piece::itsPawn()
{
	return _itsPawn;
}

bool Piece::itsEmpty()
{
	string empty = "none";
	return getColor() == empty;
}