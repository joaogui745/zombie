#include <Rect.h>

Rect::Rect(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}
Rect::Rect() : Rect(0.0f, 0.0f, 0.0f, 0.0f) {}

Vec2 Rect::GetCenter() const {
    return Vec2(x + width / 2, y + height / 2); 
}

Rect Rect::operator+(const Vec2& vector) const{
    return Rect(x + vector.x, y + vector.y, width, height);
}

bool Rect::IsInside(const Vec2& vector) const {
    bool xComponent = vector.x >= x && vector.x <= (x + width); 
    bool yComponent = vector.y >= y && vector.y <= (y + height);
    return xComponent && yComponent;
}

float Distance(const Rect& rect1, const Rect& rect2){
    Vec2 rect2Center = rect2.GetCenter();
    Vec2 rect1Center = rect1.GetCenter();
    return Distance(rect1Center, rect2Center);
}
