#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameElement {
 private:
 public:
  // default constructor
  Player() : Player(0, 0) {}
  // non-default constructor
  Player(int x, int y) : GameElement(x, y, 50, 50) {}
  void Draw(graphics::Image &player) override;
  void Move(const graphics::Image &image) override;
};

class PlayerProjectile : public GameElement {
 private:
 public:
  // default constructor
  PlayerProjectile() : PlayerProjectile(0, 0) {}
  // non-default constructor
  PlayerProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &playerprojectile) override;
  void Move(const graphics::Image &image) override;
};

#endif  // PLAYER_H
