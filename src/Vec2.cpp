#include <Vec2.h>
#include <Rect.h>
#include <cmath>

// Initializers
Vec2::Vec2(float x, float y) : x(x), y(y){}
Vec2::Vec2() : Vec2(0.0f, 0.0f) {}

// Unary Operators
float Vec2::Length() const{
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::Normalized() const {
    float len = Length();
    if (!len) return Vec2();
    return Vec2(x / len, y / len);
}

float Vec2::Angle() const{
    return std::atan2(y, x);
}

// Binary Operators overload
Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Rect Vec2::operator+(const Rect& rectangle) const {
    return Rect(x + rectangle.x, y + rectangle.y, rectangle.width, rectangle.height);
}

// Non member Operators

float Distance(const Vec2& vec1, const Vec2& vec2){
    Vec2 diff = vec2 - vec1;
    return diff.Length();
}

float Angle(const Vec2& vec1, const Vec2& vec2){
    Vec2 diff = vec2 - vec1;
    return diff.Angle();
}

Vec2 operator*(float scalar, const Vec2& vec) {
    return Vec2(scalar * vec.x, scalar * vec.y);
}