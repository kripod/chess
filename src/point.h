#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <string>

struct Point {
  /**
   * X koordináta.
   */
  int x;

  /**
   * Y koordináta.
   */
  int y;

  /**
   * Létrehoz egy új pontot.
   * @param x X koordináta.
   * @param y Y koordináta.
   */
  Point(int x = 0, int y = 0) : x{x}, y{y} {}

  /**
   * Létrehoz egy új pontot.
   * @param input A pont koordinátái algebrai jelöléssel meghatározva.
   */
  Point(std::string input);

  Point& operator+=(const Point& rhs);
};

Point operator+(Point lhs, Point rhs);
bool operator==(const Point& lhs, const Point& rhs);
bool operator!=(const Point& lhs, const Point& rhs);

#endif // POINT_H_INCLUDED
