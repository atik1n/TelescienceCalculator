#ifndef COURSE_CONSOLE_EXODUSMAP_HPP
#define COURSE_CONSOLE_EXODUSMAP_HPP

#include "helpers.hpp"

namespace nt {
  class ExodusMap {
  public:
    ExodusMap();
    sf::RectangleShape& getMap()
    {
      return map_;
    }
    void setPoint(int, int);
    void setPointSize(unsigned int);
    void render();
  private:
    sf::Texture exodusTexture_;
    sf::RenderTexture renderTarget_;
    sf::RectangleShape map_;
    sf::RectangleShape exodus_;
    sf::Color pointColor_;
    sf::Vector2i pointPos_;
    unsigned int pointSize_;
  };
}

#endif //COURSE_CONSOLE_EXODUSMAP_HPP
