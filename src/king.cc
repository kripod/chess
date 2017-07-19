#include <algorithm>
#include <vector>
#include "board.h"
#include "king.h"
#include "point.h"

bool King::IsInCheck(const Board& board, const Point& origin_pos, const Point& blocked_pos) const {
  for (size_t y = 0; y < board.height(); ++y) {
    for (size_t x = 0; x < board.width(); ++x) {
      if (blocked_pos != Point{int(x), int(y)}) {
        auto piece = board[y][x];
        if (piece != nullptr && piece->color != color) {
          auto piece_legal_moves = piece->GetLegalMoves(board, Point{int(x), int(y)}, blocked_pos);

          // Check whether the legal moves of the opponent include the origin position
          if (std::find(piece_legal_moves.begin(), piece_legal_moves.end(), origin_pos) != piece_legal_moves.end()) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

bool King::IsInCheck(const Board& board) const {
  return IsInCheck(board, board.GetPos(this));
}

bool King::CanEvadeCheck(const Board& board, const Point& origin_pos) const {
  // Try evading the check by self
  for (Point target_pos : GetLegalMoves(board, origin_pos)) {
    if (!IsInCheck(board, target_pos)) {
      return true;
    }
  }

  // Try evading the check by an other piece of the same color
  for (size_t y = 0; y < board.height(); ++y) {
    for (size_t x = 0; x < board.width(); ++x) {
      auto piece = board[y][x];
      if (piece != nullptr && piece->color == color && piece != this) {
        for (auto target_pos : piece->GetLegalMoves(board, Point{int(x), int(y)})) {
          if (!IsInCheck(board, origin_pos, target_pos)) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

bool King::CanEvadeCheck(const Board& board) const {
  return CanEvadeCheck(board, board.GetPos(this));
}
