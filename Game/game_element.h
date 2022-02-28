#include <iostream>
#include "cpputils/graphics/image.h"

#ifndef GAME_ElEMENT_H
#define GAME_ElEMENT_H

class GameElement {
 private:
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active_ = true;

 public:
  // default constructor
  GameElement() : x_(0), y_(0), width_(50), height_(50) {}
  // non-default constructor
  GameElement(int x, int y, int width, int height)
      : x_(x), y_(y), width_(width), height_(height) {}
  int GetX() const;
  int GetY() const;
  void SetX(int x);
  void SetY(int y);
  int GetWidth() const;
  int GetHeight() const;
  // milestone-4
  virtual void Draw(graphics::Image &image) = 0;
  bool GetIsActive();
  void SetIsActive(bool active);
  virtual void Move(const graphics::Image &image) = 0;
  bool IntersectsWith(GameElement *game);
  bool IsOutOfBounds(const graphics::Image &image);
};

#endif  // GAME_ElEMENT_H
