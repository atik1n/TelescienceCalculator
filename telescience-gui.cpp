#include "gui/exodusMap.hpp"
#include "gui/helpers.hpp"
#include "gui/nanoUI.hpp"
#include <SFML/Graphics.hpp>
#include <gui/helpers.hpp>

char emagged = 0;

int main()
{
  // Стартовая настройка окна
  sf::RenderWindow window(
      sf::VideoMode(800, 650),
      "NanoTrasen Telescience calculator",
      sf::Style::Titlebar | sf::Style::Close
  );
  nt::NanoUI nanoUI(window);
  nt::DrawQueue queue(nanoUI.getColor());

  sf::Font anka;
  anka.loadFromFile(nt::ankaCoder[1]);
  sf::Text ntText("NanoTrasen Telescience Calculator", anka);
  ntText.setPosition(42, 3);
  ntText.setCharacterSize(18);
  ntText.setFillColor(nt::colors.label);
  queue.push(1, ntText);

  sf::Sprite ntLogo(nanoUI.getLogo());
  ntLogo.setPosition(755, 3);
  queue.push(2, ntLogo);

  sf::Sprite ntEye(nanoUI.getEye());
  ntEye.setPosition(10, 3);
  queue.push(2, ntEye);

  sf::Sprite ntBg(nanoUI.getBackground());
  queue.push(-1, ntBg);

  nt::ExodusMap map;
  map.getMap().setSize(sf::Vector2f(350, 350));
  map.getMap().setPosition(15, 45);
  queue.push(3, map.getMap());

  nt::Label calibrationLabel;
  calibrationLabel.setPosition(380, 40);
  calibrationLabel.setSize(0, 20);
  calibrationLabel.setString("Calibration");
  calibrationLabel.setBold(true);
  queue.push(4, calibrationLabel.getDrawable());

  nt::Label telepadLabel;
  telepadLabel.setPosition(400, 65);
  telepadLabel.setSize(0, 16);
  telepadLabel.setString("Telepad coordinates");
  queue.push(4, telepadLabel.getDrawable());

  int telepadX;
  nt::TextBox<int> telepadXBox(telepadX);
  telepadXBox.setPosition(400, 90);
  telepadXBox.setSize(180, 16);
  telepadXBox.setString("170");
  queue.push(4, telepadXBox.getDrawable());

  int telepadY;
  nt::TextBox<int> telepadYBox(telepadY);
  telepadYBox.setPosition(590, 90);
  telepadYBox.setSize(180, 16);
  telepadYBox.setString("133");
  queue.push(4, telepadYBox.getDrawable());

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
