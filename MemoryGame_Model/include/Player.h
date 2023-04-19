//***************************************************************************
// File name:  Player.h
// Author:     chadd williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************

#pragma once
#include <string>

class Player
{
public:

  Player () = default;
  Player (std::string cName);
  virtual ~Player() {};
  
  void setName (std::string cName);
  std::string getName () const;

  int getScore () const;
  void incrementScore ();
  void resetScore ();

private:

  std::string mcName;
  int mScore = 0;

};