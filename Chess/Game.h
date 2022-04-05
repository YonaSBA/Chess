#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "Board.h"

#define KING_NEARBY 8

class Game
{
public:

	// C'tor:
	Game(Board board);
	// D'tor:
	~Game();

	// Getter:
	bool getTurn() const;
	
	// Setter:
	void setTurn(const bool turn);

	// Other methods:

	/* Convert the turn to color and vice versa */
	static string toColor(bool turn);
	static bool toBool(string color);
	
	/* The displacement (eating / replacing) function and its cancellation */
	Piece* move(Squere src, Squere dest, char* result);
	void cancel(Squere src, Squere dest, Piece* piece);

	/* The game processor - the "main", returns the final string to send to the frontend. */
	void engine(string msgFromGraphics, char* result);

	/* Chess and checkmate tests. */
	bool checkmate(Squere kingLocation);
	vector<Squere> chess(string playerColor, Squere kingLocation);

private:

	bool _turn;
	Board _board;
};

