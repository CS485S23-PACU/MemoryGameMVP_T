//***************************************************************************
// File name:  Observable.h
// Author:     chadd williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************

#pragma once
#include "IObserver.h"
#include <vector>
#include <string>
#include <memory>

class Observable
{
public:

  Observable () = default;
  ~Observable () = default;

  virtual void addObserver (std::shared_ptr<IObserver> pcObs);
  virtual void removeObserver (std::shared_ptr<IObserver> pcObs);

  virtual void notifyAll (const std::string &rcData);


private:
  std::vector<std::shared_ptr<IObserver>> mcObservers;
};