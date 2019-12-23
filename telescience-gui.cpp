#include <list>
#include "gui/exodusMap.hpp"
#include "gui/helpers.hpp"
#include "gui/nanoUI.hpp"
#include "telescience/calculator.hpp"
#include <SFML/Graphics.hpp>

char emagged = 0;

int main()
{
  // Стартовая настройка окна
  sf::RenderWindow window(
      sf::VideoMode(800, 600),
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

  // Координты телепада
  nt::Label telepadLabel;
  telepadLabel.setPosition(400, 65);
  telepadLabel.setSize(0, 16);
  telepadLabel.setString("Telepad coordinates");
  queue.push(4, telepadLabel.getDrawable());

  short int telepadX;
  nt::TextBox<short int> telepadXBox(telepadX);
  telepadXBox.setPosition(400, 90);
  telepadXBox.setSize(180, 16);
  telepadXBox.setString("170");
  queue.push(4, telepadXBox.getDrawable());

  short int telepadY;
  nt::TextBox<short int> telepadYBox(telepadY);
  telepadYBox.setPosition(590, 90);
  telepadYBox.setSize(180, 16);
  telepadYBox.setString("133");
  queue.push(4, telepadYBox.getDrawable());

  // Координаты №1
  nt::Label experiment1Label;
  experiment1Label.setPosition(400, 125);
  experiment1Label.setSize(0, 16);
  experiment1Label.setString("Experiment #1 coordinates");
  queue.push(4, experiment1Label.getDrawable());

  short int experiment1X;
  nt::TextBox<short int> experiment1XBox(experiment1X);
  experiment1XBox.setPosition(400, 150);
  experiment1XBox.setSize(180, 16);
  experiment1XBox.setString(std::string());
  queue.push(4, experiment1XBox.getDrawable());

  short int experiment1Y;
  nt::TextBox<short int> experiment1YBox(experiment1Y);
  experiment1YBox.setPosition(590, 150);
  experiment1YBox.setSize(180, 16);
  experiment1YBox.setString(std::string());
  queue.push(4, experiment1YBox.getDrawable());

  // Координаты №2
  nt::Label experiment2Label;
  experiment2Label.setPosition(400, 185);
  experiment2Label.setSize(0, 16);
  experiment2Label.setString("Experiment #2 coordinates");
  queue.push(4, experiment2Label.getDrawable());

  short int experiment2X;
  nt::TextBox<short int> experiment2XBox(experiment2X);
  experiment2XBox.setPosition(400, 210);
  experiment2XBox.setSize(180, 16);
  experiment2XBox.setString(std::string());
  queue.push(4, experiment2XBox.getDrawable());

  short int experiment2Y;
  nt::TextBox<short int> experiment2YBox(experiment2Y);
  experiment2YBox.setPosition(590, 210);
  experiment2YBox.setSize(180, 16);
  experiment2YBox.setString(std::string());
  queue.push(4, experiment2YBox.getDrawable());

  // Направление и возвышение
  nt::Label bearingLabel;
  bearingLabel.setPosition(400, 245);
  bearingLabel.setSize(0, 16);
  bearingLabel.setString("Bearing");
  queue.push(4, bearingLabel.getDrawable());

  short int bearing;
  nt::TextBox<short int> bearingBox(bearing);
  bearingBox.setPosition(400, 270);
  bearingBox.setSize(180, 16);
  bearingBox.setString(std::string());
  queue.push(4, bearingBox.getDrawable());

  nt::Label elevationLabel;
  elevationLabel.setPosition(590, 245);
  elevationLabel.setSize(0, 16);
  elevationLabel.setString("Elevation");
  queue.push(4, elevationLabel.getDrawable());

  short int elevation;
  nt::TextBox<short int> elevationBox(elevation);
  elevationBox.setPosition(590, 270);
  elevationBox.setSize(180, 16);
  elevationBox.setString(std::string());
  queue.push(4, elevationBox.getDrawable());

  // Мощности
  nt::Label power1Label;
  power1Label.setPosition(400, 305);
  power1Label.setSize(0, 16);
  power1Label.setString("Power #1");
  queue.push(4, power1Label.getDrawable());

  short int power1;
  nt::TextBox<short int> power1Box(power1);
  power1Box.setPosition(400, 330);
  power1Box.setSize(180, 16);
  power1Box.setString(std::string());
  queue.push(4, power1Box.getDrawable());

  nt::Label power2Label;
  power2Label.setPosition(590, 305);
  power2Label.setSize(0, 16);
  power2Label.setString("Power #2");
  queue.push(4, power2Label.getDrawable());

  short int power2;
  nt::TextBox<short int> power2Box(power2);
  power2Box.setPosition(590, 330);
  power2Box.setSize(180, 16);
  power2Box.setString(std::string());
  queue.push(4, power2Box.getDrawable());

  nt::Label statusLabel;
  statusLabel.setPosition(20, 400);
  statusLabel.setSize(0, 16);
  statusLabel.setString("Please, enter calibration data.");
  statusLabel.setLabelColor(sf::Color::Red);
  queue.push(4, statusLabel.getDrawable());

  // Целевые координаты
  nt::Label targetLabel;
  targetLabel.setPosition(20, 430);
  targetLabel.setSize(0, 16);
  targetLabel.setString("Target coordinates");
  queue.push(4, targetLabel.getDrawable());

  short int targetX;
  nt::TextBox<short int> targetXBox(targetX);
  targetXBox.setPosition(20, 455);
  targetXBox.setSize(180, 16);
  targetXBox.setString(std::string());
  queue.push(4, targetXBox.getDrawable());

  short int targetY;
  nt::TextBox<short int> targetYBox(targetY);
  targetYBox.setPosition(210, 455);
  targetYBox.setSize(180, 16);
  targetYBox.setString(std::string());
  queue.push(4, targetYBox.getDrawable());

  nt::Label bearingResultLabel;
  bearingResultLabel.setPosition(20, 505);
  bearingResultLabel.setSize(0, 16);
  bearingResultLabel.setString("Bearing: ???");
  queue.push(4, bearingResultLabel.getDrawable());

  nt::Label elevationResultLabel;
  elevationResultLabel.setPosition(20, 535);
  elevationResultLabel.setSize(0, 16);
  elevationResultLabel.setString("Elevation: ???");
  queue.push(4, elevationResultLabel.getDrawable());

  nt::Label powerResultLabel;
  powerResultLabel.setPosition(20, 565);
  powerResultLabel.setSize(0, 16);
  powerResultLabel.setString("Power: ???");
  queue.push(4, powerResultLabel.getDrawable());

  std::list<nt::TextBox<short int>*> textBoxes;
  textBoxes.push_back(&telepadXBox);
  textBoxes.push_back(&telepadYBox);
  textBoxes.push_back(&experiment1XBox);
  textBoxes.push_back(&experiment1YBox);
  textBoxes.push_back(&experiment2XBox);
  textBoxes.push_back(&experiment2YBox);
  textBoxes.push_back(&bearingBox);
  textBoxes.push_back(&elevationBox);
  textBoxes.push_back(&power1Box);
  textBoxes.push_back(&power2Box);
  textBoxes.push_back(&targetXBox);
  textBoxes.push_back(&targetYBox);
  nt::TextBox<short int>* activeBox = nullptr;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::MouseButtonPressed) {
        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos);

        for (auto textBox : textBoxes) {
          auto draw = dynamic_cast<sf::RectangleShape*>(&textBox->getDrawable());
          textBox->active = draw->getGlobalBounds().contains(translated_pos);
          if (textBox->active) {
            activeBox = textBox;
          }
          textBox->render();
        }
      }

      if ((event.type == sf::Event::TextEntered) && (activeBox != nullptr))
      {
        if(event.text.unicode == 's') {
          nanoUI.emag();
        }

        if(isdigit(event.text.unicode))
        {
          std::string string = activeBox->getString();
          string += event.text.unicode;
          activeBox->setString(string);
        }
        //erase on backspace press     !!does not work properly?what is wrong with it??
        if(event.text.unicode == '\b')
        {
          std::string string = activeBox->getString();
          if (string.size() != 0) {
            string = string.substr(0, string.size() - 1);
            activeBox->setString(string);
          }
        }

        bool calibrated = true;
        try {
          for (auto textBox : textBoxes) {
            textBox->loadValue(nt::stringToInt);
          }
        } catch (...) {
          calibrated = false;
        }

        if (calibrated) {
          statusLabel.setLabelColor(sf::Color::Green);
          statusLabel.setString("Calibration done!");

          try {
            point_t telepad = {telepadX, telepadY};
            telepad_t settingsFirst = {bearing, elevation, power1};
            telepad_t settingsSecond = {bearing, elevation, power2};
            point_t destinationFirst = {experiment1X, experiment1Y};
            point_t destinationSecond = {experiment2X, experiment2Y};

            ExperimentData experimentFirst(telepad, destinationFirst, settingsFirst);
            ExperimentData experimentSecond(telepad, destinationSecond, settingsSecond);
            calibration_t delta = Calibrator(experimentFirst, experimentSecond, "gui")();
            Calculator calculator = Calculator(delta);

            point_t target = {targetX, targetY};
            telepad_t result = calculator.calculate(telepad, target).getSettings();

            std::string bearingStr = "Bearing: ";
            bearingStr.append(std::to_string(result.phi));
            std::string elevationStr = "Elevation: ";
            elevationStr.append(std::to_string(result.theta));
            std::string powerStr = "Power: ";
            powerStr.append(std::to_string(result.power));

            bearingResultLabel.setString(bearingStr);
            elevationResultLabel.setString(elevationStr);
            powerResultLabel.setString(powerStr);

            map.setPoint(targetX, targetY);
          } catch (std::exception& e) {
            statusLabel.setLabelColor(sf::Color::Red);
            statusLabel.setString(e.what());
            bearingResultLabel.setString("Bearing: ?%4#22");
            elevationResultLabel.setString("Elevation: *5$32%");
            powerResultLabel.setString("Power: ^75$2");
          }
        } else {
          statusLabel.setLabelColor(sf::Color::Red);
          statusLabel.setString("Please, enter calibration data.");
          bearingResultLabel.setString("Bearing: ???");
          elevationResultLabel.setString("Elevation: ???");
          powerResultLabel.setString("Power: ???");
        }
      }
    }

    queue.draw(window);
  }

  return 0;
}
