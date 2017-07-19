#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED

#include <vector>
#include "board.h"
#include "color.h"
#include "piece.h"
#include "point.h"

class Bishop : virtual public Piece {
  static const std::vector<Point> kMoveDirections;

 public:
  Bishop(Color color) : Piece{'B', true, color} {}

  std::vector<Point> GetMoveDirections(const Board&, const Point&) const override {
    return kMoveDirections;
  }
};

#endif // BISHOP_H_INCLUDED
