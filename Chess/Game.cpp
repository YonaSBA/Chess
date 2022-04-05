#include "Game.h"

Game::Game(Board board) :
    _turn(true)
{
    _board = board;
}

Game::~Game() {}

bool Game::getTurn() const
{
    return _turn;
}

void Game::setTurn(const bool turn)
{
    _turn = turn;
}

Piece* Game::move(Squere src, Squere dest, char* result)
{
    Piece* piece = NULL;

    if (src == _board.getKingLoacation(_turn))
    {
        _board.setKingLoacation(_turn, dest);
    }

    if (!_board.getPiece(dest)->itsEmpty() AND
        (_board.getPiece(src)->itsPawn() ? !strcmp(result, "9") : true))
    {
        if (_board.getPiece(src)->itsPawn())
        {
            strcpy(result, "0");
        }

        piece = _board.eat(src, dest);
    }
    else
    {
        _board.swap(src, dest);
    }

    return piece;
}

void Game::cancel(Squere src, Squere dest, Piece* piece)
{
    if (dest == _board.getKingLoacation(_turn))
    {
        _board.setKingLoacation(_turn, src);
    }

    if (piece)
    {
        _board.cancel(src, dest, piece);
    }
    else
    {
        _board.swap(dest, src);
    }
}

void Game::engine(string msgFromGraphics, char* result)
{
    Piece* piece = NULL;
    vector<Squere> checkMakers;
    Squere src(msgFromGraphics.substr(0, 2));
    Squere dest(msgFromGraphics.substr(2, 4));

    if (!src.itsValid() || !dest.itsValid())
    {
        strcpy(result, "5");
    }
    else if (src == dest)
    {
        strcpy(result, "7");
    }
    else if (!_board.itsMe(_board.getBoard(), src, toColor(_turn)))
    {
        strcpy(result, "2");
    }
    else if (_board.itsMe(_board.getBoard(), dest, toColor(_turn)))
    {
        strcpy(result, "3");
    }
    else
    {
        memset(result, 0, sizeof(result));

        _board.getPiece(src)->move(_board.getBoard(), src, dest, result);

        if (!strcmp(result, "0") OR !strcmp(result, "9"))
        {
            piece = move(src, dest, result);

            checkMakers = chess(toColor(!_turn), _board.getKingLoacation(_turn));
            if (!checkMakers.empty() AND !count(checkMakers.begin(), checkMakers.end(), dest))
            {
                cancel(src, dest, piece);
                strcpy(result, "4");
            }
            else
            {
                // Continue the movement:
                if (piece)
                {
                    piece->~Piece();
                }

                checkMakers = chess(toColor(_turn), _board.getKingLoacation(!_turn));
                if (!checkMakers.empty())
                {
                    if (checkmate(_board.getKingLoacation(!_turn)))
                    {
                        strcpy(result, "8");
                    }
                    else
                    {
                        strcpy(result, "1");
                    }
                }

                _turn = !_turn;
            }
        }
    }
}

bool Game::checkmate(Squere kingLocation)
{
    Piece* p = NULL;
    Squere location(0, 0);
    char result[2] = { 0 };
    int i = 0, j = 0, k = 0, counter = 0;
    bool pawnFirstStep[PAWNS], flag = true;

    Squere kingNearby[KING_NEARBY] = { Squere(kingLocation.getRow() + 1, kingLocation.getColumn()),
                                       Squere(kingLocation.getRow() - 1, kingLocation.getColumn()),
                                       Squere(kingLocation.getRow(), kingLocation.getColumn() + 1),
                                       Squere(kingLocation.getRow(), kingLocation.getColumn() - 1),
                                       Squere(kingLocation.getRow() + 1, kingLocation.getColumn() + 1),
                                       Squere(kingLocation.getRow() - 1, kingLocation.getColumn() - 1),
                                       Squere(kingLocation.getRow() + 1, kingLocation.getColumn() - 1),
                                       Squere(kingLocation.getRow() - 1, kingLocation.getColumn() + 1) };

    for (i = 0; i < KING_NEARBY; i++)
    {
        if (kingNearby[i].itsValid() AND !_board.itsMe(_board.getBoard(), kingNearby[i], toColor(!_turn)))
        {
            p = move(kingLocation, kingNearby[i], result);

            if (!chess(toColor(_turn), kingNearby[i]).empty())
            {
                cancel(kingLocation, kingNearby[i], p);

                // Save the original array before the test:
                for (j = 0; j < PAWNS; j++)
                {
                    pawnFirstStep[j] = _board.getPawnFirstStep(j);
                }

                // Check if other tools can protect the King:
                for (j = 0; j < RIB; j++)
                {
                    location.setRow(j);

                    for (k = 0; k < RIB; k++)
                    {
                        location.setColumn(k);

                        if (_board.getPiece(location)->getColor() == toColor(!_turn))
                        {
                            memset(result, 0, sizeof(result));

                            _board.getPiece(location)->move(&_board, location, kingLocation, result);

                            if (!strcmp(result, "0"))
                            {
                                flag = !flag;
                            }
                        }
                    }
                }

                _board.setPawnFirstSteps(pawnFirstStep); // Restore the original array after the test.

                if (flag)
                {
                    counter++;
                }
                else
                {
                    flag = !flag;
                }
            }
            else
            {
                cancel(kingLocation, kingNearby[i], p);
            }
        }
        else
        {
            counter++;
        }
    }

    return counter == KING_NEARBY;
}

vector<Squere> Game::chess(string playerColor, Squere kingLocation)
{
    int i = 0, j = 0;
    Squere location(0, 0);
    char result[2] = { 0 };
    bool pawnFirstStep[PAWNS];
    vector<Squere> checkMakers;

    // Save the original array before the test:
    for (i = 0; i < PAWNS; i++)
    {
        pawnFirstStep[i] = _board.getPawnFirstStep(i);
    }

    for (i = 0; i < RIB; i++)
    {
        location.setRow(i);

        for (j = 0; j < RIB; j++)
        {
            location.setColumn(j);

            if (_board.getPiece(location)->getColor() == playerColor)
            {
                memset(result, 0, sizeof(result));

                _board.getPiece(location)->move(&_board, location, kingLocation, result);

                if (_board.getPiece(location)->itsPawn() ? !strcmp(result, "9") : !strcmp(result, "0"))
                {
                    checkMakers.push_back(location);
                }
            }
        }
    }

    _board.setPawnFirstSteps(pawnFirstStep); // Restore the original array after the test.

    return checkMakers;
}

string Game::toColor(bool turn)
{
    string b = "black", w = "white";
    return turn ? b : w;
}

bool Game::toBool(string color)
{
    string b = "black";
    return !color.compare(b) ? true : false;
}