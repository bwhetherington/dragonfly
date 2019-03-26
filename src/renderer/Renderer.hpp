#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "RenderPass.hpp";

namespace df {

class Renderer {
 public:
  Renderer(sf::Window* window);
  void draw();

 protected:
  virtual void drawPass(RenderPass& pass);

 private:
  sf::Window* m_window;
};

}