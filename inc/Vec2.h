#pragma once

class Rect;

class Vec2{
public:
    float x, y; 
    Vec2();
    Vec2(float x, float y);
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(const float scalar) const;
    Rect operator+(const Rect& rectangle) const;
    float Length() const;
    Vec2 Normalized() const;
    float Angle() const;
    // TODO
    Vec2 Rotated() const;
    Vec2& Rotate();

};

float Distance(const Vec2& vec1, const Vec2& vec2);
float Angle(const Vec2& vec1, const Vec2& vec2);
Vec2 operator*(float scalar, const Vec2& vec);