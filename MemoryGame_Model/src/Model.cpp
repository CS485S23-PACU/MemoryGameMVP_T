//***************************************************************************
// File name:  Model.cpp
// Author:     chadd williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************
#include "Model.h"

//***************************************************************************
// Constructor: Model
//
// Description: Create board with given seed, make two players.
//
// Parameters:  seed - the seed for srand()
//
// Returned:    None
//***************************************************************************
Model::Model (int seed)
{
  mpcBoard = std::make_shared<Board> (seed);
  setPlayerName (0, "you");
  setPlayerName (1, "computer");
}

//***************************************************************************
// Destructor:  ~Model
//
// Description: delete the Board
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Model::~Model ()
{
}

//***************************************************************************
// Function:    isBoardDone
//
// Description: Determine if the board is full of flipped cards
//
// Parameters:  None
//
// Returned:    bool - true if full, false otherwise
//***************************************************************************
bool Model::isBoardDone () const
{
  return mpcBoard->isBoardDone();
}

//***************************************************************************
// Function:    isWinner
//
// Description: Determine if the current player won
//
// Parameters:  None
//
// Returned:    bool - true if winner, false otherwise
//***************************************************************************
bool Model::isWinner () const
{
  return (mcVecPlayers[mCurrentTurn].getScore () >
    mcVecPlayers[(mCurrentTurn + 1) % 2].getScore ());
}

//***************************************************************************
// Function:    getCurrentPlayerName
//
// Description: Get the current player's name
//
// Parameters:  None
//
// Returned:    std::string - the name
//***************************************************************************
std::string Model::getCurrentPlayerName () const
{
  return mcVecPlayers[mCurrentTurn].getName ();
}

//***************************************************************************
// Function:    getCurrentPlayerScore
//
// Description: Get the current player's score
//
// Parameters:  None
//
// Returned:    int - the score
//***************************************************************************
int Model::getCurrentPlayerScore () const
{
  return mcVecPlayers[mCurrentTurn].getScore();
}

//***************************************************************************
// Function:    setPlayerName
//
// Description: Set the player's name
//
// Parameters:  index - the index (0 or 1) of the player
//              name - the player's  name
//
// Returned:    None
//***************************************************************************
void Model::setPlayerName (std::size_t index, std::string name)
{
  if( index >= mcVecPlayers.size())
  {
    mcVecPlayers.push_back (Player (name));
  }
  else
  {
    mcVecPlayers[index].setName (name);
  }
}

//***************************************************************************
// Function:    flip
//
// Description: flip the card at x,y, if legal. Track the two cards
//              flipped during one player's turn
//
// Parameters:  x - x coordinate of the card
//              y - y coordiante of the card
//
// Returned:    bool - true if successful, false otherwise
//***************************************************************************

bool Model::flip (int x, int y)
{
  bool bRetVal = false;
  if (legalMove (x, y))
  {    
    if (NOT_FLIPPED == mLastX1)
    {
      mLastX1 = x;
      mLastY1 = y;
      bRetVal = true;
    }
    else if( NOT_FLIPPED == mLastX2)
    {
      mLastX2 = x;
      mLastY2 = y;
      bRetVal = true;
    }
    if (bRetVal)
    {
      mpcBoard->flip (x, y);
    }
  }
  return bRetVal;
}

//***************************************************************************
// Function:    legalMove
//
// Description: Check to see if the card at position (x,y) is a legal flip
//
// Parameters:  x - x coordinate of the card
//              y - y coordiante of the card
//
// Returned:    bool - true if legal, false otherwise
//***************************************************************************
bool Model::legalMove (int x, int y) const
{
  return mpcBoard->legalFlip (x, y);
}

//***************************************************************************
// Function:    resetGame
//
// Description: Rset the board and scores
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Model::resetGame ()
{
  mpcBoard->reset ();
  mLastX1 = NOT_FLIPPED;
  mLastY1 = NOT_FLIPPED;
  mLastX2 = NOT_FLIPPED;
  mLastY2 = NOT_FLIPPED;
  mcVecPlayers[0].resetScore ();
  mcVecPlayers[1].resetScore ();

}

//***************************************************************************
// Function:    advanceTurn
//
// Description: Advance turn to next player, update score, flip cards 
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Model::advanceTurn ()
{
  if (NOT_FLIPPED != mLastX1 && NOT_FLIPPED != mLastX2)
  {
    if (!mpcBoard->match (mLastX1, mLastY1, mLastX2, mLastY2))
    {
      mpcBoard->putFaceDown (mLastX1, mLastY1);
      mpcBoard->putFaceDown (mLastX2, mLastY2);
    }
    else
    {
      mcVecPlayers[mCurrentTurn].incrementScore ();

      mpcBoard->replace (mLastX1, mLastY1);
      mpcBoard->replace (mLastX2, mLastY2);
    }
    mLastX1 = NOT_FLIPPED;
    mLastY1 = NOT_FLIPPED;
    mLastX2 = NOT_FLIPPED;
    mLastY2 = NOT_FLIPPED;

    mCurrentTurn = (mCurrentTurn + 1) % 2;
  }
}

//***************************************************************************
// Function:    getCard
//
// Description: Get the display value of the card at (x,y)
//
// Parameters:  x - x coordinate of the card
//              y - y coordiante of the card
//
// Returned:    std::string the display value of the card
//***************************************************************************
std::string Model::getCard (int x, int y) const
{
  return mpcBoard->getCard(x,y);
}
