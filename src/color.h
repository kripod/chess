#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <iostream>

enum class Color {
  kWhite,
  kBlack,
};

std::ostream& operator<<(std::ostream& os, const Color& color);

#endif // COLOR_H_INCLUDED
