#include "Board.h"
#include "EmptyPiece.h"

Board::Board()
{
    Squere null;
    int i = 0, j = 0;

    for (i = 0; i < RIB; i++)
    {
        for (j = 0; j < RIB; j++)
        {
            _pieces[i][j] = NULL;
        }
    }

    _kingLocation[0] = null;
    _kingLocation[1] = null;

    for (i = 0; i < PAWNS; i++)
    {
        _pawnsFirstSteps[i] = false;
    }
}

Board::Board(Piece* pieces[][RIB])
{
    int i = 0, j = 0;

    for (i = 0; i < RIB; i++)
    {
        for (j = 0; j < RIB; j++)
        {
            _pieces[i][j] = pieces[i][j];
        }
    }

    _kingLocation[0] = Squere("d1");
    _kingLocation[1] = Squere("d8");

    for (i = 0; i < PAWNS; i++)
    {
        _pawnsFirstSteps[i] = true;
    }
}

Board::~Board() {}

Piece* Board::getPiece(Squere location) const
{
    return _pieces[location.getRow()][location.getColumn()];
}

Squere Board::getKingLoacation(bool color) const
{
    return _kingLocation[(int)color];
}

void Board::setPawnFirstStep(const int pawn, const bool first)
{
    _pawnsFirstSteps[pawn] = first;
}

void Board::setPawnFirstSteps(const bool pawnfirstStep[PAWNS])
{
    int i = 0;

    for (i = 0; i < PAWNS; i++)
    {
        _pawnsFirstSteps[i] = pawnfirstStep[i];
    }
}

void Board::setKingLoacation(const bool color, const Squere location)
{
    _kingLocation[(int)color] = location;
}

Board* Board::getBoard()
{
    return this;
}

bool Board::getPawnFirstStep(int pawn)
{
    return _pawnsFirstSteps[pawn];
}

bool Board::itsMe(Board* board, Squere location, string color)
{
    return board->getPiece(location)->getColor() == color;
}

Piece* Board::eat(Squere src, Squere dest)
{
    Piece* p = NULL;
    string n = "none";
    EmptyPiece* newPiece;
    newPiece = new EmptyPiece(n, src);
    p = _pieces[dest.getRow()][dest.getColumn()];
    _pieces[dest.getRow()][dest.getColumn()] = _pieces[src.getRow()][src.getColumn()];
    _pieces[dest.getRow()][dest.getColumn()]->setLocation(dest);
    _pieces[src.getRow()][src.getColumn()] = &(*newPiece);
    return p;
}

void Board::cancel(Squere src, Squere dest, Piece* p)
{
    _pieces[src.getRow()][src.getColumn()]->~Piece();
    _pieces[src.getRow()][src.getColumn()] = _pieces[dest.getRow()][dest.getColumn()];
    _pieces[src.getRow()][src.getColumn()]->setLocation(src);
    _pieces[dest.getRow()][dest.getColumn()] = p;
}

void Board::swap(Squere src, Squere dest)
{
    Piece* tempP = _pieces[src.getRow()][src.getColumn()];
    _pieces[src.getRow()][src.getColumn()] = _pieces[dest.getRow()][dest.getColumn()];
    _pieces[dest.getRow()][dest.getColumn()] = tempP;
    _pieces[src.getRow()][src.getColumn()]->setLocation(src);
    _pieces[dest.getRow()][dest.getColumn()]->setLocation(dest);
}

Board& Board::operator=(const Board& other)
{
    int i = 0, j = 0;

    for (i = 0; i < RIB; i++)
    {
        for (j = 0; j < RIB; j++)
        {
            _pieces[i][j] = other._pieces[i][j];
        }
    }

    _kingLocation[0] = other.getKingLoacation(false);
    _kingLocation[1] = other.getKingLoacation(true);

    setPawnFirstSteps(other._pawnsFirstSteps);

    return *this;
}