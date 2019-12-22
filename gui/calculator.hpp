#ifndef COURSE_CONSOLE_CALCULATOR_HPP
#define COURSE_CONSOLE_CALCULATOR_HPP

#include "helpers.hpp"

namespace nt {
  class NanoUI {
  public:
    NanoUI(sf::RenderWindow&);
    void emag();
    void setEmagged(bool);
    sf::Texture& getBackground()
    {
      return background_;
    }
    sf::Texture& getIcon()
    {
      return icon_;
    }
    sf::Texture& getLogo()
    {
      return logo_;
    }
    sf::Texture& getEye()
    {
      return eye_;
    }
    sf::Color& getColor()
    {
      return bgColor_;
    }

  private:
    void update();
    sf::RenderWindow& window_;
    sf::Texture background_;
    sf::Texture icon_;
    sf::Texture logo_;
    sf::Texture eye_;
    sf::Color bgColor_;
    bool emagged_;
  };
}

#endif //COURSE_CONSOLE_CALCULATOR_HPP
