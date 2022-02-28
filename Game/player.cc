#include "player.h"
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

// player player
// draws the player
void Player::Draw(graphics::Image &player) {
  graphics::Image knight;
  knight.Load("knight.bmp");
  for (int i = 0; i < GetWidth(); i++) {
    for (int k = 0; k < GetHeight(); k++) {
      player.SetColor(GetX() + i, GetY() + k, knight.GetColor(i, k));
    }
  }
}
// does nothing for the mean time
void Player::Move(const graphics::Image &image) {}

// player PlayerProjectile
// draws the p-projectile
void PlayerProjectile::Draw(graphics::Image &playerprojectile) {
  graphics::Image dagger;
  dagger.Load("dagger.bmp");
  for (int i = 0; i < GetWidth(); i++) {
    for (int k = 0; k < GetHeight(); k++) {
      playerprojectile.SetColor(GetX() + i, GetY() + k, dagger.GetColor(i, k));
    }
  }
}
// this function is responsible for checking whether the object is inside the
// bounds of the game screen
void PlayerProjectile::Move(const graphics::Image &image) {
  SetX(GetX() - 3);
  SetY(GetY() - 3);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}
