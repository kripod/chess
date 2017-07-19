#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include "board.h"
#include "color.h"
#include "movement.h"

class Game {
  Color active_color_;
  bool is_active_color_in_check_;

  bool has_ended_;
  Color winner_color_;

 public:
  /**
   * A játékhoz köthető játéktábla.
   */
  Board board;

  Game();

  /**
   * Az éppen aktív játékos színe.
   */
  Color active_color() const { return active_color_; }

  /**
   * Ellenőrzi, hogy az éppen aktív játékos sakkban van-e.
   * @return Logikai igaz, ha az éppen aktív játékos sakkban van.
   */
  bool is_active_color_in_check() const { return is_active_color_in_check_; }

  /**
   * Meghatározza, hogy a játék véget ért-e már.
   */
  bool has_ended() const { return has_ended_; }

  /**
   * Meghatározza a győztes játékos színét. Amennyiben a játék még nem ért véget, `nullptr`-t ad vissza.
   */
  const Color* winner_color() const { return has_ended_ ? &winner_color_ : nullptr; }

  /**
   * Kör befejezése a megadott lépéssel, ellenőrizve annak helyességét.
   * @param movement Lépés, mellyel be kéne fejezni a kört.
   */
  void TakeTurn(Movement movement);
};

std::ostream& operator<<(std::ostream& os, const Game& game);

#endif // GAME_H_INCLUDED
