#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include <vector>
#include "board.h"
#include "color.h"
#include "piece.h"
#include "point.h"

struct Pawn : public Piece {
  Pawn(Color color) : Piece('P', false, color) {}

  std::vector<Point> GetMoveDirections(const Board& board, const Point& origin_pos) const override;
};

#endif // PAWN_H_INCLUDED
