#include <SFML/Graphics.hpp>
#include <csignal>
#include <cstdio>
#include <iostream>
#include "DragonflyConfig.hpp"
#include "manager/GameManager.hpp"
#include "manager/LogManager.hpp"
#include "math/Vec2.hpp"
#include "util/time.hpp"

df::LogManager& log_manager = df::LogManager::getInstance();
df::GameManager& game_manager = df::GameManager::getInstance();

void shutDown(int s) {
  log_manager.warn("Shutting Dragonfly engine down");
  game_manager.shutDown();
  log_manager.shutDown();
  exit(0);
}

void initializeInterruptHandler() {
  //struct sigaction action;
  //action.sa_handler = shutDown;
  //sigemptyset(&action.sa_mask);
  //action.sa_flags = 0;
  //sigaction(SIGINT, &action, NULL);
}

int main(int argc, char** argv) {
  initializeInterruptHandler();

  // Configure managers
  log_manager.setLogLevel(df::TRACE);
  game_manager.setTargetDuration(df::time::fromMilli(16));

  // Start managers
  log_manager.startUp();
  game_manager.startUp();

  log_manager.info("Starting Dragonfly v%d.%d", Dragonfly_VERSION_MAJOR, Dragonfly_VERSION_MINOR);

  // Run the game loop
  game_manager.run();

  // Shut down
  shutDown(0);
}