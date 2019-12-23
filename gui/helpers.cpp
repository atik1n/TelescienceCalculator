#include "helpers.hpp"

nt::DrawQueue::DrawQueue(sf::Color& color) :
    color_(color)
{ }

void nt::DrawQueue::clear()
{
  queue_.clear();
}

void nt::DrawQueue::draw(sf::RenderWindow& window) const
{
  window.clear(color_);
  for (auto it : queue_) {
    window.draw(*it.second);
  }
  window.display();
}

// Очень небезопасный код, хах
void nt::DrawQueue::pop(const sf::Drawable& object)
{
  for (auto it = queue_.begin(); it != queue_.end();) {
    if (it->second == &object) {
      it = queue_.erase(it);
    } else {
      it++;
    }
  }
}

void nt::DrawQueue::push(char z, sf::Drawable& object)
{
  queue_.insert(std::make_pair(z, &object));
}

short int nt::stringToInt(const std::string& string)
{
  return std::stoi(string);
}
