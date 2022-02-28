#include "game_element.h"
#include <iostream>
#include "cpputils/graphics/image.h"

int GameElement::GetX() const { return x_; }
int GameElement::GetY() const { return y_; }
void GameElement::SetX(int x) { x_ = x; }
void GameElement::SetY(int y) { y_ = y; }
int GameElement::GetWidth() const { return width_; }
int GameElement::GetHeight() const { return height_; }
// milestone-4
bool GameElement::GetIsActive() { return is_active_; }
void GameElement::SetIsActive(bool active) { is_active_ = active; }
// checks if it intersects with the parameter
bool GameElement::IntersectsWith(GameElement* game) {
  return !(x_ > game->GetX() + game->GetWidth() ||
           game->GetX() > GetX() + GetWidth() ||
           y_ > game->GetY() + game->GetHeight() ||
           game->GetY() > GetY() + GetHeight());
}
// checks if it is outside the bounds of the game screen
bool GameElement::IsOutOfBounds(const graphics::Image& image) {
  if (GetX() < 0 || GetX() + GetWidth() > image.GetWidth() || GetY() < 0 ||
      GetY() + GetHeight() > image.GetHeight()) {
    return true;
  } else {
    return false;
  }
}
