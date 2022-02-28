#include "opponent.h"
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"

// opponent player
// draws the opponent
void Opponent::Draw(graphics::Image &opponent) {
  graphics::Image dino;
  dino.Load("dino.bmp");
  for (int i = 0; i < GetWidth(); i++) {
    for (int k = 0; k < GetHeight(); k++) {
      opponent.SetColor(GetX() + i, GetY() + k, dino.GetColor(i, k));
    }
  }
}
// this function is responsible for checking whether the object is inside the
// bounds of the game screen
void Opponent::Move(const graphics::Image &image) {
  SetX(GetX() + 1);
  SetY(GetY() + 1);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}

// opponent OpponentProjectile
// draws the o-projectile
void OpponentProjectile::Draw(graphics::Image &opponent_projectile) {
  graphics::Image light;
  light.Load("light.bmp");
  for (int i = 0; i < GetWidth(); i++) {
    for (int k = 0; k < GetHeight(); k++) {
      opponent_projectile.SetColor(GetX() + i, GetY() + k,
                                   light.GetColor(i, k));
    }
  }
}
// this function is responsible for checking whether the object is inside the
// bounds of the game screen
void OpponentProjectile::Move(const graphics::Image &image) {
  SetX(GetX() + 3);
  SetY(GetY() + 3);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}
// milestone 5
std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  if (rate_ >= 10) {
    rate_ = 0;
    std::unique_ptr<OpponentProjectile> light =
        std::make_unique<OpponentProjectile>();
    return std::move(light);
  } else {
    rate_++;
    return nullptr;
  }
}
