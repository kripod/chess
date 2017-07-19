#include <algorithm>
#include <stdexcept>
#include <vector>
#include "board.h"
#include "color.h"
#include "piece.h"
#include "point.h"

std::vector<Point> Piece::GetLegalMoves(const Board& board, const Point& origin_pos, const Point& blocked_pos) const {
  std::vector<Point> result;

  for (auto direction : GetMoveDirections(board, origin_pos)) {
    for (auto target_pos = origin_pos + direction; board.Includes(target_pos) && target_pos != blocked_pos; target_pos += direction) {
      auto target_piece = board.At(target_pos);

      // Discard every move which collides with a piece of the same color
      if (target_piece != nullptr && target_piece->color == color) break;

      result.push_back(target_pos);

      // Don't allow leap-over moves
      if (target_piece != nullptr) break;

      // Only repeat moves in turn if allowed
      if (!can_repeat_moves_in_turn) break;
    }
  }

  return result;
}

std::vector<Point> Piece::GetLegalMoves(const Board& board) const {
  return GetLegalMoves(board, board.GetPos(this));
}

void Piece::Move(const Board& board, const Point& origin_pos, const Point& target_pos) {
  auto legal_moves = GetLegalMoves(board, origin_pos);

  if (std::find(legal_moves.begin(), legal_moves.end(), target_pos) == legal_moves.end()) {
    throw std::logic_error("Cannot move piece to the given position.");
  }

  num_moves_ += 1;
}
