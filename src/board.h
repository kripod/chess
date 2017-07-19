#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <map>
#include "color.h"
#include "piece.h"
#include "point.h"

class King;

class Board {
  static const size_t kWidth = 8;
  static const size_t kHeight = 8;

  Piece* squares_[kHeight][kWidth];

  std::map<Color, King*> kings_;

  Piece*& At(const Point& point) { return squares_[point.y][point.x]; }

 public:
  /**
   * Meghatározza egy sor azonosítóját algebrai jelöléssel.
   * @param y Y koordináta.
   * @return Sor azonosítója algebrai jelöléssel.
   */
  static size_t GetRowId(size_t y) { return y + 1; }

  /**
   * Meghatározza egy oszlop azonosítóját algebrai jelöléssel.
   * @param x X koordináta.
   * @return Oszlop azonosítója algebrai jelöléssel.
   */
  static char GetColumnId(size_t x) { return x + 'a'; }

  /**
   * A játéktábla szélessége.
   */
  static size_t width() { return kWidth; }

  /**
   * A játéktábla magassága.
   */
  static size_t height() { return kHeight; }

  /**
   * Eldönti egy pontról, hogy a játéktábla tartalmazza-e.
   * @param point Pont, amelyről el kell dönteni, hogy a játéktábla tartalmazza-e.
   * @return Logikai igaz, ha a játéktábla tartalmazza a megadott pontot.
   */
  static bool Includes(const Point& point);

  Board();
  ~Board();

  /**
   * A játéktáblán található király bábuk színenként csoportosítva.
   */
  std::map<Color, King*> kings() const { return kings_; }

  const Piece* const* operator[](size_t y) const { return squares_[y]; }

  const Piece* At(const Point& point) const { return squares_[point.y][point.x]; }

  /**
   * Megpróbálja meghatározni egy bábu koordinátáit.
   * @param piece Bábu, amely megtalálható a játéktáblán.
   * @return Játéktábla koordinátái.
   */
  Point GetPos(const Piece* piece) const;

  /**
   * Megpróbál elmozdítani egy bábut a kívánt helyről egy másikra, ellenőrizve a lépés helyességét.
   * @param origin_pos A bábu kiindulási koordinátái.
   * @param target_pos A bábu cél koordinátái.
   */
  void Move(const Point& origin_pos, const Point& target_pos);

  /**
   * Megpróbál beváltani egy bábut léptetése után egy másikra, ellenőrizve a lépés helyességét.
   * @param origin_pos A bábu kiindulási koordinátái.
   * @param target_pos A bábu cél koordinátái.
   * @param target_piece Új bábu, amelyre az eredetit le kéne váltani.
   */
  void Exchange(const Point& origin_pos, const Point& target_pos, Piece* target_piece);
};

std::ostream& operator<<(std::ostream& os, const Board& board);

#endif // BOARD_H_INCLUDED
