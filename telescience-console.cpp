#include <iostream>
#include "telescience/calculator.hpp"

int main()
{
  point_t telepad = {170, 133};
  telepad_t settingsFirst = {45, 22, 30};
  telepad_t settingsSecond = {45, 22, 40};
  point_t destinationFirst = {206, 178};
  point_t destinationSecond = {238, 217};

  ExperimentData experimentFirst(telepad, destinationFirst, settingsFirst);
  ExperimentData experimentSecond(telepad, destinationSecond, settingsSecond);

  calibration_t delta = Calibrator(experimentFirst, experimentSecond, "console")();
  std::cout << "name:  " << delta.name << " | "
            << "phi:   " << delta.phi << " | "
            << "theta: " << delta.theta << " | "
            << "power: " << delta.power << '\n';

  Calculator calculator = Calculator(delta);
  point_t aiSatelite = {164, 45};
  std::cout << "\nSat.x: " << aiSatelite.x << " | "
            << "Sat.y: " << aiSatelite.y << '\n';

  telepad_t result = calculator.calculate(telepad, destinationFirst).getSettings();
  std::cout << "\nphi:   " << result.phi << " | "
            << "theta: " << result.theta << " | "
            << "power: " << result.power << '\n';
  result = calculator.calculate(telepad, destinationSecond).getSettings();
  std::cout << "\nphi:   " << result.phi << " | "
            << "theta: " << result.theta << " | "
            << "power: " << result.power << '\n';
  result = calculator.calculate(telepad, aiSatelite).getSettings();
  std::cout << "\nphi:   " << result.phi << " | "
            << "theta: " << result.theta << " | "
            << "power: " << result.power << '\n';
  return 0;
}
