#include "nanoUI.hpp"

nt::NanoUI::NanoUI(sf::RenderWindow& window) :
    window_(window),
    emagged_(false)
{
  update();
}

void nt::NanoUI::emag()
{
  emagged_ = !emagged_;
  update();
}

void nt::NanoUI::setEmagged(bool emagged)
{
  emagged_ = emagged;
  update();
}

void nt::NanoUI::update()
{
  background_.loadFromFile(nt::bg[emagged_]);
  icon_.loadFromFile(nt::icon[emagged_]);
  sf::Image icon = icon_.copyToImage();
  window_.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
  logo_.loadFromFile(nt::logo[emagged_]);
  eye_.loadFromFile(nt::eye[emagged_]);
  bgColor_ = nt::bgColor[emagged_];
}
