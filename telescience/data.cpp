#include "data.hpp"
#include <algorithm>
#include <cmath>

double toDegrees(double radians)
{
  return radians * (180.0 / 3.141592653589793238463);
}

double distance(const point_t& a, const point_t& b)
{
  return std::sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

double angle(const point_t& a, const point_t& b)
{
  double angle = 450 - toDegrees(std::atan2(a.y - b.y,a.x - b.x));
  return (angle >= 360) ? angle - 360 : angle;
}

template <typename T>
bool in(const std::vector<T>& v, const T& x)
{
  return std::find(v.begin(), v.end(), x) != v.end();
}

telepad_t operator +(const telepad_t& settings, const calibration_t& delta)
{
  return {
    settings.phi + delta.phi,
    settings.theta + delta.theta,
    settings.power + delta.power
  };
}

ExperimentData::ExperimentData(const point_t& telepad, const point_t& destination, const telepad_t& settings) :
    telepadLocation_(telepad),
    destinationLocation_(destination),
    telepadSettings_(settings)
{ }

double ExperimentData::getAngle() const
{
  return angle(destinationLocation_, telepadLocation_);
}
