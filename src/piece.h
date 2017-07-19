#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <vector>
#include "board.h"
#include "color.h"
#include "point.h"

class Board;

class Piece {
  size_t num_moves_;

 protected:
  /**
   * Létrehoz egy új bábut.
   * @param short_name A bábu egy betűs rövidítése.
   * @param can_repeat_moves_in_turn Meghatározza, hogy a bábu tudja-e ismételni egy körben egy adott lépéstípusát.
   * @param color A bábu színe.
   */
  Piece(char short_name, bool can_repeat_moves_in_turn, Color color) : num_moves_{0}, short_name{short_name}, can_repeat_moves_in_turn{can_repeat_moves_in_turn}, color{color} {}

 public:
  /**
   * A bábu egy betűs rövidítése.
   */
  const char short_name;

  /**
   * Meghatározza, hogy a bábu tudja-e ismételni egy körben egy adott lépéstípusát.
   */
  const bool can_repeat_moves_in_turn;

  /**
   * A bábu színe.
   */
  const Color color;

  virtual ~Piece() {}

  /**
   * A bábu lépéseinek száma. (Meghatározza, hogy a bábu létrehozása óta hány körben volt aktív.)
   */
  size_t num_moves() const { return num_moves_; }

  /**
   * Meghatározza a bábu lehetséges mozgási irányait.
   * @param board Játéktábla, melyen a bábut mozgatni szeretnénk.
   * @param origin_pos A bábu kiindulási koordinátái.
   * @return A bábu lehetséges mozgási irányai.
   */
  virtual std::vector<Point> GetMoveDirections(const Board& board, const Point& origin_pos) const = 0;

  /**
   * Meghatározza a bábu lehetséges lépéseit.
   * @param board Játéktábla, melyen a bábut mozgatni szeretnénk.
   * @param origin_pos A bábu kiindulási koordinátái.
   * @param blocked_pos Pozíció a játéktáblán, melyet egy másik színű bábu által elfoglaltnak tekintünk.
   * @return A bábu lehetséges lépései (egy körben).
   */
  std::vector<Point> GetLegalMoves(const Board& board, const Point& origin_pos, const Point& blocked_pos = {-1, -1}) const;

  /**
   * Meghatározza a bábu lehetséges lépéseit.
   * @param board Játéktábla, melyen a bábut mozgatni szeretnénk.
   * @return A bábu lehetséges lépései (egy körben).
   */
  std::vector<Point> GetLegalMoves(const Board& board) const;

  /**
   * Megpróbálja elmozdítani a bábut egy kívánt helyről egy másikra, ellenőrizve a lépés helyességét.
   * @param board Játéktábla, melyen a bábut mozgatni szeretnénk.
   * @param origin_pos A bábu kiindulási koordinátái.
   * @param target_pos A bábu cél koordinátái.
   */
  void Move(const Board& board, const Point& origin_pos, const Point& target_pos);
};

#endif // PIECE_H_INCLUDED
