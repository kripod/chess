#include <vector>
#include "board.h"
#include "point.h"
#include "queen.h"

std::vector<Point> Queen::GetMoveDirections(const Board& board, const Point& origin_pos) const {
  auto result = Rook::GetMoveDirections(board, origin_pos);
  auto diagonal_directions = Bishop::GetMoveDirections(board, origin_pos);
  result.insert(result.end(), diagonal_directions.begin(), diagonal_directions.end());

  return result;
}
