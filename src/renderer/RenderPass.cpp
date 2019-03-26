#include "RenderPass.hpp"
#include <SFML/OpenGL.hpp>

using namespace df;

RenderPass::RenderPass(sf::Window* window) {
  m_window = window;
  window->setActive(true);
}

RenderPass::~RenderPass() {
  m_window->setActive(false);
  m_window = nullptr;
}