#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED

#include <vector>
#include "board.h"
#include "color.h"
#include "piece.h"
#include "point.h"

class Rook : virtual public Piece {
  static const std::vector<Point> kMoveDirections;

 public:
  Rook(Color color) : Piece{'R', true, color} {}

  std::vector<Point> GetMoveDirections(const Board&, const Point&) const override {
    return kMoveDirections;
  }
};

#endif // ROOK_H_INCLUDED
