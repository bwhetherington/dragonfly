#include "Renderer.hpp"
#include "RenderPass.hpp";

using namespace df;

void Renderer::draw() {
  RenderPass pass(m_window);
  drawPass(pass);

  // `pass` is automatically deallocated
}