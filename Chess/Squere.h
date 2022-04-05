#pragma once

#include <iostream>
#include <string>

#define AND &&
#define OR ||

#define RIB 8
#define LETTER_TO_NUM 96

using namespace std;

class Squere
{
public:

	// C'tors:
	Squere();
	Squere(int row, int column);
	// Copy C'tor:
	Squere(const string location);
	// D'tor:
	~Squere();

	// Getters:
	int getRow() const;
	int getColumn() const;

	// Setters:
	void setRow(const int row);
	void setColumn(const int column);

	// Operators overloading:
	Squere& operator=(const Squere& other);
	friend bool operator==(const Squere& me, const Squere& other);

	// Other Methods:

	/* Checks if a squere is correct (values ​​in the board range). */
	bool itsValid();

protected:

	int _row;
	int _column;
};