#include <iostream>
#include <stdexcept>
#include <string>
#include "color.h"
#include "game.h"

int main()
{
  std::string input;

  do {
    Game game;

    do {
      std::cout << game << std::endl;
      if (game.is_active_color_in_check()) {
        std::cout << "You are in check!" << std::endl;
      }
      std::cout << game.active_color() << "> ";

      try {
        getline(std::cin, input);
        game.TakeTurn(input);
      } catch (const std::exception& e) {
        if (!std::cin.eof()) {
          std::cout << "ERROR: " << e.what() << std::endl;
        }
      }

      if (!std::cin.eof()) {
        std::cout << std::endl;
      }
    } while (!std::cin.eof() && !game.has_ended());

    std::cin.clear();

    if (game.has_ended()) {
      std::cout << game << std::endl;
      std::cout << *(game.winner_color()) << " wins!" << std::endl;
    } else {
      std::cout << std::endl << "No one has won." << std::endl;
    }

    std::cout << "Do you want to play again? [y/(n)]: ";
    getline(std::cin, input);
    std::cout << std::endl;
  } while (tolower(input[0]) == 'y');

  return 0;
}
