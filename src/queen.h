#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include <vector>
#include "bishop.h"
#include "board.h"
#include "color.h"
#include "piece.h"
#include "point.h"
#include "rook.h"

struct Queen : public Rook, public Bishop {
  Queen(Color color) : Piece{'Q', true, color}, Rook{color}, Bishop{color} {}

  std::vector<Point> GetMoveDirections(const Board& board, const Point& origin_pos) const override;
};

#endif // QUEEN_H_INCLUDED
