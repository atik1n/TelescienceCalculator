#ifndef COURSE_CONSOLE_HELPERS_HPP
#define COURSE_CONSOLE_HELPERS_HPP

#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace nt {
  using drawMap = std::multimap<char, sf::Drawable*>;
  class DrawQueue {
  public:
    DrawQueue(sf::Color&);
    void clear();
    void draw(sf::RenderWindow&) const;
    void pop(const sf::Drawable&);
    void push(char, sf::Drawable&);
    void setColor(sf::Color& color)
    {
      color_ = color;
    }
  private:
    drawMap queue_;
    sf::Color& color_;
  };

  int stringToInt(const std::string& string);

  const sf::Color bgColor[] = {
      {39, 39, 39},
      {143, 20, 20}
  };

  const struct {
    sf::Color label = {233, 193, 131};
    sf::Color activeOutline = {64, 98, 138};
    sf::Color textBox = {64, 98, 138};
    sf::Color textBoxActive = {94, 128, 168};
  } colors;

  const std::string icon[] = {
      "resources/iconNT.png",
      "resources/iconSY.png"
  };
  const std::string bg[] = {
      "resources/uiBackground.png",
      "resources/uiBackground-Syndicate.png"
  };
  const std::string logo[] = {
      "resources/uiTitleFluff.png",
      "resources/uiTitleFluff-Syndicate.png"
  };
  const std::string eye[] = {
      "resources/eyeNT.png",
      "resources/eyeSY.png"
  };

  const std::string exodus = "resources/nanomap_exodus_1.png";

  const std::string ankaCoder[] = {
      "resources/AnkaCoder-r.ttf",
      "resources/AnkaCoder-b.ttf"
  };
}

#endif //COURSE_CONSOLE_DEFINES_HPP
