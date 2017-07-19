#include <vector>
#include "bishop.h"
#include "point.h"

const std::vector<Point> Bishop::kMoveDirections = {
  {-1, -1},
  {-1, 1},
  {1, -1},
  {1, 1},
};
