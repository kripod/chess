#include <cctype>
#include <stdexcept>
#include <string>
#include "point.h"

Point::Point(std::string input) {
  if (input.length() < 2) {
    throw std::length_error("input");
  }

  x = tolower(input[0]) - 'a';
  y = input[1] - '1';
}

Point& Point::operator+=(const Point& rhs) {
  x += rhs.x;
  y += rhs.y;
  return *this;
}

Point operator+(Point lhs, Point rhs) {
  return lhs += rhs;
}

bool operator==(const Point& lhs, const Point& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Point& lhs, const Point& rhs) {
  return !(lhs == rhs);
}
