#include "gui/calculator.hpp"
#include "gui/helpers.hpp"
#include <SFML/Graphics.hpp>

char emagged = 0;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 650), "NanoTrasen Telescience calculator");
  nt::NanoUI nanoUI(window);
  nt::DrawQueue queue(nanoUI.getColor());

  sf::Font anka;
  anka.loadFromFile(nt::ankaCoder);
  sf::Text ntText("NanoTrasen Telescience Calculator", anka);
  ntText.setPosition(8, 3);
  ntText.setCharacterSize(18);
  ntText.setFillColor(nt::fgColor);
  queue.push(1, ntText);

  sf::Sprite ntLogo(nanoUI.getLogo());
  ntLogo.setPosition(755, 3);
  queue.push(2, ntLogo);

  sf::Sprite ntBg(nanoUI.getBackground());
  queue.push(-1, ntBg);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    queue.draw(window);
  }

  return 0;
}
