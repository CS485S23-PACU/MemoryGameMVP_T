//***************************************************************************
// File name:  Model.h
// Author:     chadd williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************

#pragma once
#include "Board.h"
#include "Player.h"
#include <vector>
#include <memory>

class Model
{
public:

  Model (int seed = 1);
  ~Model ();

  bool isBoardDone () const;
  bool isWinner () const;
  std::string getCurrentPlayerName () const;
  int getCurrentPlayerScore () const;

  void setPlayerName (std::size_t index, std::string name);

  bool flip (int x, int y);

  bool legalMove (int x, int y) const;

  void resetGame ();

  void advanceTurn ();

  std::string getCard (int x, int y) const;


private:

  std::shared_ptr<Board> mpcBoard;
  std::vector<Player> mcVecPlayers;
  int mCurrentTurn = 0;
  static const int NOT_FLIPPED = -1;
  int mLastX1 = NOT_FLIPPED, mLastY1 = NOT_FLIPPED;
  int mLastX2= NOT_FLIPPED, mLastY2 = NOT_FLIPPED;
};