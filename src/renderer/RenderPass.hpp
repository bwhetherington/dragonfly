#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

namespace df {

class RenderPass {
 public:
  // Creates a render pass, activating the window's OpenGL context
  RenderPass(sf::Window* window);

  // Destructs the render pass, deactivating the window's OpenGL context
  ~RenderPass();

  void drawComponents();

 private:
  // The SFML window associated wiht the render pass
  sf::Window* m_window;
};

}