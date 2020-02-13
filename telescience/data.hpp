#ifndef COURSE_CONSOLE_DATA_HPP
#define COURSE_CONSOLE_DATA_HPP
#include <cmath>
#include <string>
#include <vector>

// TYPES
struct point_t
{
  int x;
  int y;
};

const std::vector<int> telepadPowers = {
    5, 10, 20, 25, 30, 40, 50, 80, 100
};

struct telepad_t
{
  int phi;
  int theta;
  int power;
};

struct calibration_t : public telepad_t
{
  std::string name;
};

// OPERATORS & METHODS
double toDegrees(double);
double distance(const point_t&, const point_t&);
double angle(const point_t&, const point_t&);
template <typename T>
bool in(const std::vector<T>&, const T&);
telepad_t operator +(const telepad_t&, const calibration_t&);

// CLASSES
class ExperimentData
{
public:
  ExperimentData(const point_t&, const point_t&, const telepad_t&);

  point_t getTelepadLocation() const
  {
    return telepadLocation_;
  }
  point_t getDestinationLocation() const
  {
    return destinationLocation_;
  }
  telepad_t getSettings() const
  {
    return telepadSettings_;
  }
  double getDistance() const
  {
    return distance(telepadLocation_, destinationLocation_);
  }
  double getAngle() const;
private:
  point_t telepadLocation_;
  point_t destinationLocation_;
  telepad_t telepadSettings_;
};

#endif
