#include <algorithm>
#include <cctype>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>
#include "color.h"
#include "game.h"
#include "movement.h"
#include "piece.h"
#include "point.h"

Movement::Movement(std::string input) : origin_pos_{nullptr}, target_pos_{nullptr}, origin_short_name_{'P'}, promoted_short_name_{'\0'} {
  std::regex movement_regex{"([PNBRQK])?((?:[a-h][1-8]){0,2})([NBRQ])?", std::regex_constants::icase};
  std::smatch matches;

  if (std::regex_match(input, matches, movement_regex)) {
    if (matches[1].length() > 0) {
      origin_short_name_ = toupper(std::string{matches[1]}[0]);
    }

    std::string positions = matches[2];
    if (positions.length() >= 2) {
      if (positions.length() >= 4) {
        origin_pos_ = std::unique_ptr<Point>{new Point{positions}};
        target_pos_ = std::unique_ptr<Point>{new Point{positions.substr(2)}};
      } else {
        target_pos_ = std::unique_ptr<Point>{new Point{positions}};
      }
    }

    if (matches[3].length() > 0) {
      promoted_short_name_ = toupper(std::string{matches[3]}[0]);
    }
  }
}

Point Movement::origin_pos(const Game& game) const {
  if (origin_pos_ != nullptr) {
    if (!game.board.Includes(*origin_pos_) || game.board.At(*origin_pos_) == nullptr) {
      throw std::invalid_argument("Invalid origin coordinates.");
    }

    return *origin_pos_;
  }

  // Search for a matching movement on the given board
  Point result;
  auto isOneResultFound = false;
  auto resolved_target_pos = target_pos(game);

  for (size_t y = 0; y < game.board.height(); ++y) {
    for (size_t x = 0; x < game.board.width(); ++x) {
      auto piece = game.board[y][x];
      if (piece != nullptr && (piece->color == game.active_color() && piece->short_name == origin_short_name_)) {
        auto piece_legal_moves = piece->GetLegalMoves(game.board, Point{int(x), int(y)});

        // Check whether the legal moves include the specified target
        if (std::find(piece_legal_moves.begin(), piece_legal_moves.end(), resolved_target_pos) != piece_legal_moves.end()) {
          if (isOneResultFound) {
            throw std::logic_error("Ambiguous movement. Please specify the origin of the piece.");
          }

          result = Point{int(x), int(y)};
          isOneResultFound = true;
        }
      }
    }
  }

  if (!isOneResultFound) {
    throw std::logic_error("Invalid movement. None of the pieces can legally make the given move.");
  }

  return result;
}

Point Movement::target_pos(const Game& game) const {
  if (target_pos_ != nullptr) {
    if (!game.board.Includes(*target_pos_)) {
      throw std::invalid_argument("Invalid target coordinates.");
    }

    if (origin_short_name_ == 'P' && ((game.active_color() == Color::kBlack && target_pos_->y == 0) || (game.active_color() == Color::kWhite && target_pos_->y == int(game.board.height() - 1)))) {
      if (promoted_short_name_ == '\0') {
        throw std::logic_error("Pawn must be promoted when reaching the last rank of the board.");
      }

    } else if (promoted_short_name_ != '\0') {
      throw std::logic_error("Cannot promote given piece at its target position.");
    }

    return *target_pos_;
  }

  throw std::logic_error("Missing target coordinates.");
}
