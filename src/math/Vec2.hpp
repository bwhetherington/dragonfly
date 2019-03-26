namespace df {

class Vec2 {
 private:
  // The x-coordinate of the vector.
  float m_x;

  // The y-coordinate of the vector.
  float m_y;

 public:
  // Constructs a vector with the specified x-coordinate and y-coordinate.
  Vec2(float x, float y);

  // Constructs a vector as a copy of the specified vector.
  Vec2(const Vec2& copy);

  // Sets the vector to the other specified vector.
  void operator=(const Vec2& copy);

  // Produces the sum of this vector and the specified addend.
  Vec2 operator+(const Vec2& addend) const;

  // Produces the difference between this vector and the specified subtrahend.
  Vec2 operator-(const Vec2& subtrahend) const;

  // Sets the x-coordinate of the vector to the specified value.
  void setX(float new_x);

  // Sets the y-coordinate of the vector to the specified value.
  void setY(float new_y);

  // Produces the x-coordinate of the vector.
  float getX() const;

  // Produces the y-coordinate of the vector.
  float getY() const;

  // Produces the magnitude of the vector.
  float getMagnitude() const;

  // Normalizes the vector.
  void normalize();

  // Scales the vector by the specified scalar quantity.
  void scale(float scalar);
};

}  // namespace df