#ifndef COURSE_CONSOLE_CALIBRATOR_HPP
#define COURSE_CONSOLE_CALIBRATOR_HPP

#include "data.hpp"

class Calibrator
{
public:
  Calibrator(const ExperimentData&, const ExperimentData&, const std::string&);
  calibration_t operator ()()
  {
    return calibration_;
  }

private:
  ExperimentData experimentA_;
  ExperimentData experimentB_;
  calibration_t calibration_;
};

#endif //COURSE_CONSOLE_CALIBRATOR_HPP
