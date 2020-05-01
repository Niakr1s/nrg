#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <boost/signals2.hpp>
#include <string>

#include "manager.h"

namespace widgets {

class Button {
  sf::Font font_;
  sf::Text text_;
  bool selected_ = false;

 public:
  Button();
  Button(const std::string& str);
  Button(const std::string& str, float x, float y);
  Button(const std::string& str, float x, float y, const std::string& font_str);

  void setPosition(float x, float y);
  void setSelected(bool selected);

  template <class T>
  void draw(T& t) {
    selected_ ? text_.setFillColor(sf::Color::Green)
              : text_.setFillColor(sf::Color::White);
    t.draw(text_);
  }

  boost::signals2::signal<void()> clicked;

  const sf::Text& text() const;
  void setText(const std::string& text);
};

}  // namespace widgets

#endif  // BUTTON_H
