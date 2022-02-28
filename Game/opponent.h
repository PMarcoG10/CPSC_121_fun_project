#include <iostream>
#include <memory>
#include "cpputils/graphics/image.h"
#include "game_element.h"

#ifndef OPPONENT_H
#define OPPONENT_H

class OpponentProjectile : public GameElement {
 private:
 public:
  // default constructor
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  // non-default constructor
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &opponent_projectile) override;
  void Move(const graphics::Image &image) override;
};

class Opponent : public GameElement {
 private:
  int rate_ = 0;

 public:
  // default constructor
  Opponent() : Opponent(0, 0) {}
  // non-default constructor
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  void Draw(graphics::Image &opponent) override;
  void Move(const graphics::Image &image) override;
  // milestone-5
  std::unique_ptr<OpponentProjectile> LaunchProjectile();
};
#endif  // OPPONENT_H
