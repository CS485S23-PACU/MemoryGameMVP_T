#include "Model.h"
#include <iostream>

void printBoard (const Model &rcModel)
{
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "  0 1 2 3\n";
  for (int y = 0; y < Board::BOARD_SIZE; ++y)
  {
    std::cout << y << " ";
    for (int x = 0; x < Board::BOARD_SIZE; ++x)
    {
      std::cout << rcModel.getCard (x, y) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}

int main ()
{
  Model cTheModel;

  int x1, y1, x2, y2;
 
  //cTheModel.setPlayerName (0, "chadd");
  //cTheModel.setPlayerName (1, "bob");

  while (!cTheModel.isBoardDone ())
  {
    system ("clear");
    std::cout << " --------START--------------\n";
    printBoard (cTheModel);

    std::cout << " Enter x1 y1 x2 y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    cTheModel.flip (x1, y1);
    
    cTheModel.flip(x2, y2);

    printBoard (cTheModel);

    std::cout << cTheModel.getCurrentPlayerName () << " ";
    std::cout << cTheModel.getCurrentPlayerScore ();

    cTheModel.advanceTurn ();
    std::cout << "\n--------END--------------\n";
    // system ("pause");  // windows
    // mac/linux
    std::cin.get(); // read the trailing \n from x1..y2
    std::cin.get(); // wait for the user to press enter
    
  }

  return EXIT_SUCCESS;
}