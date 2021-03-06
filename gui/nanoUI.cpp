#include "nanoUI.hpp"
#include "helpers.hpp"

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


nt::Label::Label()
{
  font_.loadFromFile(nt::ankaCoder[0]);
  label_.setFont(font_);
  label_.setFillColor(nt::colors.label);
  label_.setCharacterSize(24);
}

void nt::Label::setBold(bool bold)
{
  font_.loadFromFile(nt::ankaCoder[bold]);
  label_.setFont(font_);
}
