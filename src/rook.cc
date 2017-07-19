#include <vector>
#include "point.h"
#include "rook.h"

const std::vector<Point> Rook::kMoveDirections = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0},
};
