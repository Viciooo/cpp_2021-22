//
// Created by Piotr on 28.04.2022.
//

#ifndef ZAD4SHAPEDRAWING_CIRCLE_H
#define ZAD4SHAPEDRAWING_CIRCLE_H

#include  "shape.h"
namespace Shapes{
class Circle :public Shape{
public:
    [[nodiscard]] int x() const{
        return x_;
    }
    [[nodiscard]] int y() const{
        return y_;
    }
    [[nodiscard]] int getRadius() const{
        return radius;
    }

    Circle(int x, int y, int radius) : x_(x), y_(y), radius(radius) {}

    [[nodiscard]] bool isIn(int x, int y) const override{
        return (x_ - x)*(x_ - x)+ (y_ - y)*(y_ - y) <= radius*radius;
    }
private:
    int x_;
    int y_;
    int radius;
};
}

#endif //ZAD4SHAPEDRAWING_CIRCLE_H
