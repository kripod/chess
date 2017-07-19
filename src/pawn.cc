#include <vector>
#include "board.h"
#include "color.h"
#include "pawn.h"
#include "piece.h"
#include "point.h"

std::vector<Point> Pawn::GetMoveDirections(const Board& board, const Point& origin_pos) const {
  std::vector<Point> result;
  int offset_sign = color == Color::kWhite ? 1 : -1;

  // 1 square forward if the way is not blocked by an other piece
  auto target_pos = origin_pos + Point{0, offset_sign};
  auto target_piece = board.At(target_pos);
  if (target_piece == nullptr) {
    result.push_back(Point{0, offset_sign});
  }

  // 1 square diagonal if there is a piece of an other color at the target position
  for (int x_sign = -1; x_sign <= 1; x_sign += 2) {
    auto target_offset = Point{x_sign, offset_sign};
    target_pos = origin_pos + target_offset;
    target_piece = board.At(target_pos);
    if (target_piece != nullptr && target_piece->color != color) {
      result.push_back(target_offset);
    }
  }

  // 2 squares forward on the first move if the way is not blocked by an other piece
  if (num_moves() == 0) {
    auto target_offset = Point{0, 2 * offset_sign};
    target_pos = origin_pos + target_offset;
    target_piece = board.At(target_pos);
    if (target_piece == nullptr) {
      result.push_back(target_offset);
    }
  }

  return result;
}
