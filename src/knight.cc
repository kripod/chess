#include <vector>
#include "knight.h"
#include "point.h"

const std::vector<Point> Knight::kMoveDirections = {
  {-2, -1},
  {-2, 1},
  {-1, -2},
  {-1, 2},
  {1, -2},
  {1, 2},
  {2, -1},
  {2, 1},
};
