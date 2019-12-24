#include "exodusMap.hpp"
#include "helpers.hpp"

nt::ExodusMap::ExodusMap() :
    pointColor_(nt::colors.activeOutline),
    pointPos_({170, 133}),
    pointSize_(3)
{
  renderTarget_.create(1024, 1024);
  renderTarget_.display();

  exodusTexture_.loadFromFile(nt::exodus);

  exodus_.setTexture(&exodusTexture_);
  exodus_.setSize(sf::Vector2f(1024, 1024));

  map_.setSize(sf::Vector2f(1024, 1024));
  map_.setOutlineColor(nt::colors.activeOutline);
  map_.setOutlineThickness(1);

  render();
}

void nt::ExodusMap::setPoint(int x, int y)
{
  pointPos_ = {x, y};
  render();
}

void nt::ExodusMap::setPointSize(unsigned int r)
{
  pointSize_ = r;
  render();
}

void nt::ExodusMap::render()
{
  renderTarget_.clear();
  renderTarget_.draw(exodus_);

  sf::RectangleShape point(sf::Vector2f(2 * pointSize_, 2 * pointSize_));
  int x = (pointPos_.x - 1) * 4 - pointSize_ + 1;
  int y = (256 - pointPos_.y) * 4 - pointSize_ + 1;
  point.setFillColor(nt::colors.pointColor);
  point.setOutlineColor(nt::colors.activeOutline);
  point.setOutlineThickness(2);
  point.setPosition(x, y);

  renderTarget_.draw(point);
  map_.setTexture(&renderTarget_.getTexture());
}
