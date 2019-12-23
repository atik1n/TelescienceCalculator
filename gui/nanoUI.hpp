#ifndef COURSE_CONSOLE_NANOUI_HPP
#define COURSE_CONSOLE_NANOUI_HPP

#include <functional>
#include "helpers.hpp"

namespace nt {
  class NanoUI {
  public:
    NanoUI(sf::RenderWindow&);
    void emag();
    void setEmagged(bool);
    sf::Texture& getBackground()
    {
      return background_;
    }
    sf::Texture& getIcon()
    {
      return icon_;
    }
    sf::Texture& getLogo()
    {
      return logo_;
    }
    sf::Texture& getEye()
    {
      return eye_;
    }
    sf::Color& getColor()
    {
      return bgColor_;
    }

  private:
    void update();
    sf::RenderWindow& window_;
    sf::Texture background_;
    sf::Texture icon_;
    sf::Texture logo_;
    sf::Texture eye_;
    sf::Color bgColor_;
    bool emagged_;
  };

  class Drawable {
  public:
    virtual sf::Drawable& getDrawagle() = 0;
  };

  class Label {
  public:
    Label();
    virtual sf::Drawable& getDrawable()
    {
      return label_;
    }
    std::string getString() const
    {
      return label_.getString();
    }
    virtual void setString(const std::string& string)
    {
      string_ = string;
      label_.setString(string_);
    }
    void setLabelColor(const sf::Color& color)
    {
      label_.setFillColor(color);
    }
    virtual void setPosition(float x, float y)
    {
      label_.setPosition(x, y);
    }
    virtual void setSize(int, int h)
    {
      label_.setCharacterSize(h);
    }
    void setBold(bool bold);
  protected:
    sf::Font font_;
    std::string string_;
    sf::Text label_;
  };

  template <typename T>
  class TextBox : public Label {
  public:
    TextBox(T&);
    sf::Drawable& getDrawable() override
    {
      return textBox_;
    }
    void setString(const std::string&) override;
    void setPosition(float x, float y) override
    {
      textBox_.setPosition(x, y);
    }
    void setSize(int, int) override;
    void loadValue(std::function<T(const std::string&)>);
  private:
    void render();
    sf::RenderTexture renderTarget_;
    sf::RectangleShape textBox_;
    T& valueRef_;
  };
}

template <typename T>
nt::TextBox<T>::TextBox(T& value) :
    valueRef_(value),
    Label()
{
  int w = 120;
  int h = label_.getCharacterSize() + 10;
  renderTarget_.create(w, h);
  renderTarget_.display();
  label_.setFillColor(sf::Color::White);
  label_.setPosition(5, 2);
  textBox_.setSize(sf::Vector2f(w, h));
  textBox_.setOutlineColor(sf::Color::White);
  textBox_.setOutlineThickness(2);
  render();
}

template <typename T>
void nt::TextBox<T>::render()
{
  renderTarget_.clear(nt::colors.activeOutline);
  renderTarget_.draw(label_);
  textBox_.setTexture(&renderTarget_.getTexture(), true);
}

template <typename T>
void nt::TextBox<T>::setString(const std::string& string)
{
  Label::setString(string);
  render();
}

template <typename T>
void nt::TextBox<T>::setSize(int w, int h)
{
  label_.setCharacterSize(h);
  renderTarget_.create(w, h + 10);
  renderTarget_.display();
  textBox_.setSize(sf::Vector2f(w, h + 10));
  render();
}

template <typename T>
void nt::TextBox<T>::loadValue(std::function<T(const std::string&)> trans)
{
  valueRef_ = trans(string_);
}

#endif //COURSE_CONSOLE_NANOUI_HPP
