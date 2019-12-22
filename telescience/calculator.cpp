#include "calculator.hpp"

Calculator::Calculator(const calibration_t& delta) :
    delta_(delta)
{ }

ExperimentData Calculator::calculate(const point_t& telepad, const point_t& position) const
{
  double phi = angle(position, telepad) - delta_.phi;
  double d = distance(telepad, position);

  int p = 0;
  for (auto &power : telepadPowers) {
    if (std::pow(power + delta_.power, 2) > 10 * d) {
      p = power;
      break;
    }
  }

  double theta = 0.5 * toDegrees(std::asin((10 * d) / std::pow((p + delta_.power), 2))) - delta_.theta;
  return ExperimentData(telepad, position, {(int)std::round(phi), (int)std::round(theta), p});
}

void Calculator::recalibrate(const calibration_t& delta)
{
  delta_ = delta;
}