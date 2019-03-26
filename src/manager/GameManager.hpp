#pragma once

#include "../util/Clock.hpp"
#include "../util/time.hpp"
#include "Manager.hpp"

namespace df {

class GameManager : public Manager {
 private:
  GameManager();
  GameManager(const GameManager&);
  void operator=(const GameManager&);

  Clock m_clock;
  bool m_is_game_over;
  Time m_target_duration;

 public:
  static GameManager& getInstance();

  void setTargetDuration(Time target_duration);
  Time getTargetDuration() const;

  int startUp() override;
  void shutDown() override;

  void run();

  void setGameOver(bool is_game_over);

  bool isGameOver() const;
};

}  // namespace df