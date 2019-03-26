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
  struct sigaction action;
  action.sa_handler = shutDown;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  sigaction(SIGINT, &action, NULL);
}

int main(int argc, char** argv) {
  initializeInterruptHandler();

  // Configure managers
  log_manager.setLogLevel(df::TRACE);
  game_manager.setTargetDuration(df::time::fromMilli(16));

  // Start managers
  log_manager.startUp();
  game_manager.startUp();

  // Run the game loop
  game_manager.run();

  // Shut down
  shutDown(0);

  // printf("Version: %d.%d\n", Dragonfly_VERSION_MAJOR,
  // Dragonfly_VERSION_MINOR);

  // sf::ContextSettings settings;
  // settings.antialiasingLevel = 8;
  // sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!",
  //                         sf::Style::Default, settings);
  // sf::CircleShape shape(100.f);
  // shape.setPosition(100, 50);

  // shape.setFillColor(sf::Color::Green);

  // while (window.isOpen()) {
  //   sf::Event event;
  //   while (window.pollEvent(event)) {
  //     if (event.type == sf::Event::Closed) window.close();
  //   }

  //   window.clear();
  //   window.draw(shape);
  //   window.display();
  // }

  return 0;
}