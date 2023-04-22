//****************************************************************************
// File name:	driver.cpp
// Author:		chadd williams
// Date:		  5/23/2017
// Class:		  CS 485
// Assignment:ModelViewPresenter TextUI
// Purpose:		Demonstrate MVP
//****************************************************************************
#include <iostream>
#include <chrono>
#include <thread>
#include "TextUI.h"
#include "TextUITextWidget.h"


auto gpcText = std::make_shared<TextUITextWidget>("Hello", "data");

void onSetData(std::string cData)
{
  gpcText->setData(cData);
}

//***************************************************************************
// Function:    main
//
// Description: Launch the TextUI
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
/*int main ()
{
  TextUI cView(std::cout, std::cin);

  cView.addWidget(1,1, gpcText);
  cView.registerEvent("SETDATA", 
  std::bind
  (onSetData, std::placeholders::_1));

  cView.UIEventLoop ();

  return EXIT_SUCCESS;
}*/