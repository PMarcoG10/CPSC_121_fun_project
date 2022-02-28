#include "game.h"
#include <iostream>
#include <vector>

Player &Game::GetPlayer() { return knight_; }
std::vector<std::unique_ptr<Opponent>> &Game::GetOpponents() { return dino_; }
std::vector<std::unique_ptr<OpponentProjectile>>
    &Game::GetOpponentProjectiles() {
  return light_;
}
std::vector<std::unique_ptr<PlayerProjectile>> &Game::GetPlayerProjectiles() {
  return dagger_;
}
graphics::Image &Game::GetGameScreen() { return game_; }
void Game::CreateOpponents() {
  Opponent dino;
  dino.SetX(40);
  dino.SetY(10);
  dino_.push_back(std::make_unique<Opponent>(dino));
  Opponent dino2;
  dino2.SetX(90);
  dino2.SetY(10);
  dino_.push_back(std::make_unique<Opponent>(dino2));
  Opponent dino3;
  dino3.SetX(130);
  dino3.SetY(10);
  dino_.push_back(std::make_unique<Opponent>(dino3));
  Opponent dino4;
  dino4.SetX(170);
  dino4.SetY(10);
  dino_.push_back(std::make_unique<Opponent>(dino4));
}
void Game::Init() {
  knight_.SetX(300);
  knight_.SetY(25);
  // milestone-4
  game_.AddMouseEventListener(*this);
  game_.AddAnimationEventListener(*this);
}
void Game::UpdateScreen() {
  // const graphics::Color bluish(127, 229, 240);
  const graphics::Color white(255, 255, 255);
  const graphics::Color black(0, 0, 0);
  game_.DrawRectangle(0, 0, 800, 600, white);
  // this sets text onto the score
  game_.DrawText(10, 10, "Score: " + std::to_string(score_), 25, black);

  if (knight_.GetIsActive()) {
    knight_.Draw(game_);
  } else {
    game_.DrawText(200, 200, "GAME OVER", 100, black);
  }
  for (int i = 0; i < dino_.size(); i++) {
    if (dino_[i]->GetIsActive()) {
      dino_[i]->Draw(game_);
    }
  }
  for (int i = 0; i < dagger_.size(); i++) {
    if (dagger_[i]->GetIsActive()) {
      dagger_[i]->Draw(game_);
    }
  }
  for (int i = 0; i < light_.size(); i++) {
    if (light_[i]->GetIsActive()) {
      light_[i]->Draw(game_);
    }
  }
}
void Game::Start() { game_.ShowUntilClosed("Game Thing"); }
// milestone-4
// moves the opponent and projectiles
void Game::MoveGameElements() {
  for (int i = 0; i < dino_.size(); i++) {
    dino_[i]->Move(game_);
  }
  for (int i = 0; i < light_.size(); i++) {
    light_[i]->Move(game_);
  }
  for (int i = 0; i < dagger_.size(); i++) {
    dagger_[i]->Move(game_);
  }
}
// checks for intersection - opponenent and player
void Game::FilterIntersections() {
  for (int i = 0; i < dino_.size(); i++) {
    if (dino_[i]->GetIsActive() && knight_.GetIsActive() &&
        knight_.IntersectsWith(dino_[i].get())) {
      dino_[i]->SetIsActive(false);
      knight_.SetIsActive(false);
    } else {
      for (int j = 0; j < dagger_.size(); j++) {
        if (dino_[i]->GetIsActive() && dagger_[j]->GetIsActive() &&
            dagger_[j]->IntersectsWith(dino_[i].get())) {
          if (knight_.GetIsActive()) {
            score_++;
          }
          dino_[i]->SetIsActive(false);
          dagger_[j]->SetIsActive(false);
        }
      }
    }
  }
  for (int i = 0; i < light_.size(); i++) {
    if (light_[i]->GetIsActive() && knight_.GetIsActive() &&
        knight_.IntersectsWith(light_[i].get())) {
      light_[i]->SetIsActive(false);
      knight_.SetIsActive(false);
    }
  }
}
void Game::OnAnimationStep() {
  if (dino_.size() == 0) {
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  game_.Flush();
}
// this controls the player with the mouse
void Game::OnMouseEvent(const graphics::MouseEvent &mouse) {
  mouse.GetMouseAction();
  if (mouse.GetX() > 0 && mouse.GetY() > 0 && mouse.GetX() < game_.GetWidth() &&
      mouse.GetY() < game_.GetHeight()) {
    knight_.SetX(mouse.GetX() - knight_.GetWidth() / 2);
    knight_.SetY(mouse.GetY() - knight_.GetHeight() / 2);
  }
  if (mouse.GetMouseAction() == graphics::MouseAction::kPressed) {
    std::unique_ptr<PlayerProjectile> dagger =
        std::make_unique<PlayerProjectile>(mouse.GetX(), mouse.GetY() + 25);
    dagger_.push_back(std::move(dagger));
  }
  if (mouse.GetMouseAction() == graphics::MouseAction::kDragged) {
    std::unique_ptr<PlayerProjectile> dagger =
        std::make_unique<PlayerProjectile>(mouse.GetX(), mouse.GetY() + 25);
    dagger_.push_back(std::move(dagger));
  }
}
// milestone-5
int Game::GetScore() { return score_; }
bool Game::HasLost() { return !(knight_.GetIsActive()); }
void Game::RemoveInactive() {
  for (int i = 0; i < dino_.size(); i++) {
    if (dino_[i]->GetIsActive() == false) {
      dino_.erase(dino_.begin() + i);
      i -= 1;
    }
  }
  for (int i = 0; i < light_.size(); i++) {
    if (light_[i]->GetIsActive() == false) {
      light_.erase(light_.begin() + i);
      i -= 1;
    }
  }
  for (int i = 0; i < dagger_.size(); i++) {
    if (dagger_[i]->GetIsActive() == false) {
      dagger_.erase(dagger_.begin() + i);
      i -= 1;
    }
  }
}
void Game::LaunchProjectiles() {
  for (int i = 0; i < dino_.size(); i++) {
    std::unique_ptr<OpponentProjectile> light = dino_[i]->LaunchProjectile();
    if (light != nullptr) {
      light->SetX(dino_[i]->GetX());
      light->SetY(dino_[i]->GetY());
      light_.push_back(std::move(light));
    }
  }
}
