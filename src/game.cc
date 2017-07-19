#include "bishop.h"
#include "color.h"
#include "game.h"
#include "king.h"
#include "knight.h"
#include "movement.h"
#include "piece.h"
#include "queen.h"
#include "rook.h"

Game::Game() : active_color_{Color::kWhite}, is_active_color_in_check_{false}, has_ended_{false}, board{} {}

void Game::TakeTurn(Movement movement) {
  auto movement_origin_pos = movement.origin_pos(*this);
  auto movement_target_pos = movement.target_pos(*this);
  auto active_color_king = board.kings()[active_color_];

  if (movement.origin_short_name() == 'K' ? active_color_king->IsInCheck(board, movement_target_pos) : (active_color_king->IsInCheck(board, board.GetPos(active_color_king), movement_origin_pos) && active_color_king->IsInCheck(board, board.GetPos(active_color_king), movement_target_pos))) {
    throw std::logic_error("Cannot move to a position which puts the king in check.");
  }

  if (movement.promoted_short_name() == '\0') {
    // Execute regular move
    board.Move(movement_origin_pos, movement_target_pos);

  } else {
    // Execute pawn promotion
    Piece* target_piece;

    switch (movement.promoted_short_name()) {
      case 'N':
        target_piece = new Knight{active_color_};
        break;

      case 'B':
        target_piece = new Bishop{active_color_};
        break;

      case 'R':
        target_piece = new Rook{active_color_};
        break;

      case 'Q':
        target_piece = new Queen{active_color_};
        break;

      default:
        target_piece = nullptr;
    }

    board.Exchange(movement_origin_pos, movement_target_pos, target_piece);
  }

  auto prev_active_color = active_color_;
  active_color_ = active_color_ == Color::kWhite ? Color::kBlack : Color::kWhite;
  active_color_king = board.kings()[active_color_];

  // Check whether the active color is in check
  is_active_color_in_check_ = active_color_king->IsInCheck(board);

  // Check whether the active color was given a checkmate
  if (is_active_color_in_check_ && !active_color_king->CanEvadeCheck(board)) {
    winner_color_ = prev_active_color;
    has_ended_ = true;
  }
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
  os << game.board;
  return os;
}
