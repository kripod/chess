#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include <vector>
#include "board.h"
#include "color.h"
#include "piece.h"
#include "point.h"

class Knight : public Piece {
  static const std::vector<Point> kMoveDirections;

 public:
  Knight(Color color) : Piece{'N', false, color} {}

  std::vector<Point> GetMoveDirections(const Board&, const Point&) const override {
    return kMoveDirections;
  }
};

#endif // KNIGHT_H_INCLUDED
