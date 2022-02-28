#include <iostream>
#include <vector>
#include "cpputils/graphics/image_event.h"
#include "opponent.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 private:
  graphics::Image game_;
  std::vector<std::unique_ptr<Opponent>> dino_;
  std::vector<std::unique_ptr<OpponentProjectile>> light_;
  std::vector<std::unique_ptr<PlayerProjectile>> dagger_;
  Player knight_;
  int width_;
  int height_;
  int score_ = 0;
  bool life_ = true;

 public:
  // default  constructor
  Game() : game_(800, 600) {}
  // non-default constructor
  Game(int width, int height)
      : width_(width), height_(height), game_(width, height) {}
  Player &GetPlayer();
  std::vector<std::unique_ptr<Opponent>> &GetOpponents();
  std::vector<std::unique_ptr<OpponentProjectile>> &GetOpponentProjectiles();
  std::vector<std::unique_ptr<PlayerProjectile>> &GetPlayerProjectiles();
  graphics::Image &GetGameScreen();
  void CreateOpponents();
  void Init();
  void Start();
  // milestone-4
  void MoveGameElements();
  void FilterIntersections();
  void UpdateScreen();
  void OnAnimationStep();
  void OnMouseEvent(const graphics::MouseEvent &mouse);
  // milestone-5
  int GetScore();
  bool HasLost();
  void RemoveInactive();
  void LaunchProjectiles();
};

#endif  // GAME_H
