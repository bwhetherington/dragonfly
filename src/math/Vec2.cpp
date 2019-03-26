#include "Vec2.hpp"
#include <cmath>

using namespace df;

Vec2::Vec2(float x, float y) {
  setX(x);
  setY(y);
}

Vec2::Vec2(const Vec2& copy) { *this = copy; }

void Vec2::operator=(const Vec2& copy) {
  setX(copy.getX());
  setY(copy.getY());
}

Vec2 Vec2::operator+(const Vec2& addend) const {
  return Vec2(getX() + addend.getX(), getY() + addend.getY());
}

Vec2 Vec2::operator-(const Vec2& addend) const {
  return Vec2(getX() - addend.getX(), getY() - addend.getY());
}

float Vec2::getX() const { return m_x; }

float Vec2::getY() const { return m_y; }

void Vec2::setX(float new_x) { m_x = new_x; }

void Vec2::setY(float new_y) { m_y = new_y; }

void Vec2::scale(float scalar) {
  setX(getX() * scalar);
  setY(getY() * scalar);
}

float Vec2::getMagnitude() const {
  float x = getX();
  float y = getY();
  return sqrt(x * x + y * y);
}

void Vec2::normalize() {
  float magnitude = 1 / getMagnitude();
  scale(1 / magnitude);
}