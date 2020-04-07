#include "button.h"

#include <iostream>

const sf::Text& Button::text() const { return text_; }

void Button::setText(const std::string& text) { text_.setString(text); }

Button::Button() : Button("") {}

Button::Button(const std::string& str) : Button(str, 0., 0.) {}

Button::Button(const std::string& str, float x, float y)
    : Button(str, x, y, "data/fonts/arial.ttf") {}

Button::Button(const std::string& str, float x, float y,
               const std::string& font_str) {
  font_.loadFromFile(font_str);
  text_ = sf::Text(str, font_);
  setPosition(x, y);
}

void Button::setPosition(float x, float y) { text_.setPosition(x, y); }

void Button::setSelected(bool selected) { selected_ = selected; }
