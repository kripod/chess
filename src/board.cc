#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include "bishop.h"
#include "board.h"
#include "color.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "piece.h"
#include "point.h"
#include "queen.h"
#include "rook.h"

Board::Board() : squares_{{nullptr}} {
  size_t y = 0;

  for (auto color : {Color::kWhite, Color::kBlack}) {
    // Place special pieces which are in pair
    for (int xOffset = 0; xOffset < int(width()); xOffset += width() - 1) {
      squares_[y][size_t(std::abs(xOffset - 0))] = new Rook{color};
      squares_[y][size_t(std::abs(xOffset - 1))] = new Knight{color};
      squares_[y][size_t(std::abs(xOffset - 2))] = new Bishop{color};
    }

    // Place queen
    squares_[y][3] = new Queen{color};

    // Place king
    auto king = new King{color};
    squares_[y][4] = king;
    kings_[color] = king;

    // Place pawns
    y += color == Color::kWhite ? 1 : -1;
    for (size_t x = 0; x < width(); ++x) {
      squares_[y][x] = new Pawn{color};
    }

    y = height() - 1;
  }
}

Board::~Board() {
  for (size_t y = 0; y < height(); ++y) {
    for (size_t x = 0; x < width(); ++x) {
      delete squares_[y][x];
    }
  }
}

bool Board::Includes(const Point& point) {
  return point.x >= 0 && point.y >= 0 && point.x < int(width()) && point.y < int(height());
}

Point Board::GetPos(const Piece* piece) const {
  for (size_t y = 0; y < height(); ++y) {
    for (size_t x = 0; x < width(); ++x) {
      if (squares_[y][x] == piece) {
        return {int(x), int(y)};
      }
    }
  }

  throw std::logic_error("Piece cannot be found on board.");
}

void Board::Move(const Point& origin_pos, const Point& target_pos) {
  auto origin_piece = At(origin_pos);
  origin_piece->Move(*this, origin_pos, target_pos);

  delete At(target_pos);
  At(target_pos) = origin_piece;
  At(origin_pos) = nullptr;
}

void Board::Exchange(const Point& origin_pos, const Point& target_pos, Piece* target_piece) {
  delete At(target_pos);
  At(target_pos) = target_piece;

  delete At(origin_pos);
  At(origin_pos) = nullptr;
}

void PrintColumnIds(std::ostream& os, const Board& board) {
  os << "  ";

  for (size_t x = 0; x < board.width(); ++x) {
    os << board.GetColumnId(x);
  }

  os << std::endl;
}

void PrintHorizontalFrame(std::ostream& os, const Board& board) {
  os << " +";

  for (size_t x = 0; x < board.width(); ++x) {
    os << "-";
  }

  os << "+" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
  PrintColumnIds(os, board);
  PrintHorizontalFrame(os, board);

  for (int y = board.height() - 1; y >= 0; --y) {
    auto row_id = board.GetRowId(y);
    os << row_id << "|";

    for (size_t x = 0; x < board.width(); ++x) {
      auto piece = board[y][x];
      if (piece != nullptr) {
        os << char(piece->color == Color::kWhite ? piece->short_name : tolower(piece->short_name));
      } else {
        os << ".";
      }
    }

    os << "|" << row_id << "\n";
  }

  PrintHorizontalFrame(os, board);
  PrintColumnIds(os, board);

  return os;
}
