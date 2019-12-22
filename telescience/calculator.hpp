#ifndef COURSE_CONSOLE_CALCULATOR_HPP
#define COURSE_CONSOLE_CALCULATOR_HPP
#include "calibrator.hpp"

class Calculator
{
public:
  Calculator(const calibration_t&);
  ExperimentData calculate(const point_t&, const point_t&) const;
  void recalibrate(const calibration_t&);
private:
  calibration_t delta_;
};

#endif //COURSE_CONSOLE_CALCULATOR_HPP
