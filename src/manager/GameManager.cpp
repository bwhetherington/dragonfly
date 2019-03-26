#include "GameManager.hpp"
#include <cstdio>
#include "../util/sleep.hpp"
#include "../util/time.hpp"
#include "LogManager.hpp"

using namespace df;

GameManager::GameManager() {
  setType("GameManager");
  m_clock = Clock();
  m_is_game_over = false;
  m_target_duration = time::fromSeconds(1);
}

void GameManager::setGameOver(bool is_game_over) {
  m_is_game_over = is_game_over;
}

bool GameManager::isGameOver() const { return m_is_game_over; }

void GameManager::setTargetDuration(Time target_duration) {
  m_target_duration = target_duration;
}

Time GameManager::getTargetDuration() const { return m_target_duration; }

void GameManager::run() {
  LogManager& logger = LogManager::getInstance();
  Time loop_time, sleep_time, actual_sleep_time, adjust_time = 0;
  while (!isGameOver()) {
    m_clock.delta();

    // Do necessary updates
    logger.info("game update");

    loop_time = m_clock.split();
    sleep_time = getTargetDuration() - loop_time - adjust_time;
    m_clock.delta();
    microSleep(sleep_time);
    actual_sleep_time = m_clock.split();
    adjust_time = actual_sleep_time - sleep_time;
  }
}

int GameManager::startUp() {
  LogManager& logger = LogManager::getInstance();
  logger.trace("Starting up %s", getType().c_str());
  return 1;
}

void GameManager::shutDown() {
  LogManager& logger = LogManager::getInstance();
  logger.trace("Shutting down %s", getType().c_str());
}

GameManager& GameManager::getInstance() {
  static GameManager manager;
  return manager;
}