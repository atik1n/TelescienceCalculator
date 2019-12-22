#include "calibrator.hpp"

#include <stdexcept>

Calibrator::Calibrator(const ExperimentData& A, const ExperimentData& B, const std::string& name) :
    experimentA_(A),
    experimentB_(B)
{
  double distanceA = experimentA_.getDistance();
  double distanceB = experimentB_.getDistance();
  double sqrtDistanceA = std::sqrt(distanceA);
  double sqrtDistanceB = std::sqrt(distanceB);
  telepad_t telepadA = experimentA_.getSettings();
  telepad_t telepadB = experimentB_.getSettings();;

  double phiA = experimentA_.getAngle() - telepadA.phi;
  double phiB = experimentB_.getAngle() - telepadB.phi;

  double phi = std::round((phiA + phiB) / 2);
  calibration_.phi = (phi > 15) ? phi - 360 : phi;

  double power = (sqrtDistanceA * telepadB.power - sqrtDistanceB * telepadA.power)/
      (sqrtDistanceB - sqrtDistanceA);
  calibration_.power = std::round(power);

  double radiansA = (10 * distanceA) / std::pow((telepadA.power + power), 2);
  double thetaA = telepadA.theta - 0.5 * toDegrees(std::asin(radiansA));

  double radiansB = (10 * distanceB) / std::pow((telepadB.power + power), 2);
  double thetaB = telepadB.theta - 0.5 * toDegrees(std::asin(radiansB));

  if ((radiansA > 1) || (radiansB > 1)) {
    throw std::runtime_error("asin(1.0000...). Recalibrate crystal.");
  }

  double theta = std::round((thetaA + thetaB) / 2);
  calibration_.theta = (theta > 25) ? theta - 360 : -theta;

  calibration_.name = name;
}