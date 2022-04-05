/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Game.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Qween.h"
#include "Knight.h"
#include "Pawn.h"
#include "EmptyPiece.h"

int main(void)
{
	srand(time_t(NULL));

	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 0;
		}
	}
	
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	char result[2] = { 0 };
	string b = "black", w = "white", e = "none";

	King K(b, Squere("d8")), k(w, Squere("d1"));

	Qween Q(b, Squere("e8")), q(w, Squere("e1"));

	Rook R1(b, Squere("a8")), R2(b, Squere("h8")), r1(w, Squere("a1")), r2(w, Squere("h1"));

	Knight N1(b, Squere("b8")), N2(b, Squere("g8")), n1(w, Squere("b1")), n2(w, Squere("g1"));

	Bishop B1(b, Squere("c8")), B2(b, Squere("f8")), b1(w, Squere("c1")), b2(w, Squere("f1"));

	Pawn P1(b, Squere("a7")), P2(b, Squere("b7")), P3(b, Squere("c7")), P4(b, Squere("d7"));
	Pawn P5(b, Squere("e7")), P6(b, Squere("f7")), P7(b, Squere("g7")), P8(b, Squere("h7"));
	Pawn p1(w, Squere("a2")), p2(w, Squere("b2")), p3(w, Squere("c2")), p4(w, Squere("d2"));
	Pawn p5(w, Squere("e2")), p6(w, Squere("f2")), p7(w, Squere("g2")), p8(w, Squere("h2"));

	EmptyPiece e1(e, Squere("a6")), e2(e, Squere("b6")), e3(e, Squere("c6")), e4(e, Squere("d6"));
	EmptyPiece e5(e, Squere("e6")), e6(e, Squere("f6")), e7(e, Squere("g6")), e8(e, Squere("h6"));
	EmptyPiece e9(e, Squere("a5")), e10(e, Squere("b5")), e11(e, Squere("c5")), e12(e, Squere("d5"));
	EmptyPiece e13(e, Squere("e5")), e14(e, Squere("f5")), e15(e, Squere("g5")), e16(e, Squere("h5"));
	EmptyPiece e17(e, Squere("a4")), e18(e, Squere("b4")), e19(e, Squere("c4")), e20(e, Squere("d4"));
	EmptyPiece e21(e, Squere("e4")), e22(e, Squere("f4")), e23(e, Squere("g4")), e24(e, Squere("h4"));
	EmptyPiece e25(e, Squere("a3")), e26(e, Squere("b3")), e27(e, Squere("c3")), e28(e, Squere("d3"));
	EmptyPiece e29(e, Squere("e3")), e30(e, Squere("f3")), e31(e, Squere("g3")), e32(e, Squere("h3"));

	Piece* Pieces[RIB][RIB] = { { &R1, &N1, &B1, &K, &Q, &B2, &N2, &R2 },
							    { &P1, &P2, &P3, &P4, &P5, &P6, &P7, &P8 },
							    { &e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8 },
							    { &e9, &e10, &e11, &e12, &e13, &e14, &e15, &e16 },
							    { &e17,&e18, &e19, &e20, &e21, &e22, &e23, &e24 },
							    { &e25,&e26, &e27, &e28, &e29, &e30, &e31, &e32 },
							    { &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8 },
							    { &r1, &n1, &b1, &k, &q, &b2, &n2, &r2 } };

	Board br(Pieces);

	Game g(br);
							
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
		g.engine(msgFromGraphics, result);
		strcpy_s(msgToGraphics, result); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		******* JUST FOR EREZ DEBUGGING ******/

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
	g.~Game();
	return 0;
}