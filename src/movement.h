#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

#include <memory>
#include <string>
#include "point.h"

class Game;

class Movement {
  std::unique_ptr<Point> origin_pos_;
  std::unique_ptr<Point> target_pos_;
  char origin_short_name_;
  char promoted_short_name_;

 public:
  /**
   * Létrehoz egy lépést.
   * @param input Lépés algebrai jelöléssel
   */
  Movement(std::string input);

  /**
   * Meghatározza a léptetendő bábu kiindulási koordinátáit.
   * @param game Játék, amelyben kivitelezendő a lépés.
   * @return A léptetendő bábu kiindulási koordinátái.
   */
  Point origin_pos(const Game& game) const;

  /**
   * Meghatározza a léptetendő bábu cél koordinátáit.
   * @param game Játék, amelyben kivitelezendő a lépés.
   * @return A léptetendő bábu cél koordinátái.
   */
  Point target_pos(const Game& game) const;

  /**
   * A léptetendő bábu egy betűs rövidítése.
   */
  char origin_short_name() const { return origin_short_name_; }

  /**
   * A léptetett bábut leváltó bábu egy betűs rövidítése.
   */
  char promoted_short_name() const { return promoted_short_name_; }
};

#endif // MOVEMENT_H_INCLUDED
