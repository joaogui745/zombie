#pragma once
#include <Vec2.h>

class Rect{
public:
    float x, y, width, height;
    Rect();
    Rect(float x, float y, float width, float height);
    Vec2 GetCenter() const;
    bool IsInside(const Vec2& vector) const;
    
    Rect operator+(const Vec2& vector) const;
};

float Distance(const Rect& rect1, const Rect& rect2){
    Vec2 rect2Center = rect2.GetCenter();
    Vec2 rect1Center = rect1.GetCenter();
    return Distance(rect1Center, rect2Center);
}
