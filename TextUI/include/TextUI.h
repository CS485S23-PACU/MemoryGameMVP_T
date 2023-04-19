//***************************************************************************
// File name:  TextUI.h
// Author:     chadd williams
// Date:       3/39/2017
// Class:      CS485
// Assignment: TextUI
// Purpose:    Provide event based TextUI
//***************************************************************************
#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ITextUIWidget.h"
#include <functional>
#include <memory>

class TextUI
{
public:
  TextUI (std::ostream& rcOut, std::istream& rcIn);
  ~TextUI ();

  void addWidget (int x, int y, std::shared_ptr<ITextUIWidget> pcWidget);

  void drawScreen () ;
  void clearScreen () const;
  void displayEventMenu () const;
  void UIEventLoop ();
  void registerEvent (std::string name,
    std::function<void (std::string)> func);
private:
 

  struct compare {
    size_t operator()(const std::pair<int,int> &rcLeft, 
      const std::pair<int, int> &rcRight) const
    {
      if (rcLeft.first == rcRight.first)
      {
        return rcLeft.second < rcRight.second;
      }
      return rcLeft.first < rcRight.first;
    }
  };

  std::map<std::pair<int,int>, std::shared_ptr<ITextUIWidget>, struct compare> mWidgets;
  std::istream& mrcIn;
  std::ostream& mrcOut;
  std::map<std::string,
    std::function<void ( std::string)>> mEventMap;


};
