#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "board.h"
#include "color.h"
#include "point.h"
#include "queen.h"

struct King : public Queen {
  King(Color color) : Piece{'K', false, color}, Queen{color} {}

  bool IsInCheck(const Board& board, const Point& origin_pos, const Point& blocked_pos = {-1, -1}) const;
  bool IsInCheck(const Board& board) const;

  bool CanEvadeCheck(const Board& board, const Point& origin_pos) const;
  bool CanEvadeCheck(const Board& board) const;
};

#endif // KING_H_INCLUDED
