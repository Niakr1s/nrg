#include "button.h"

#include <iostream>

const sf::Text& Button::text() const { return text_; }

Button::Button(const std::string& str, Manager& manager) : manager_(manager) {
  font_.loadFromFile("data/fonts/arial.ttf");
  text_ = sf::Text(str, font_);
}

void Button::setPosition(float x, float y) { text_.setPosition(x, y); }

void Button::setSelected(bool selected) { selected_ = selected; }
