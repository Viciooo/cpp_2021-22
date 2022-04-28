//
// Created by Piotr on 28.04.2022.
//

#ifndef ZAD4SHAPEDRAWING_RECTANGLE_H
#define ZAD4SHAPEDRAWING_RECTANGLE_H

#include "shape.h"

namespace Shapes {
    class Rectangle : public Shape {
    public:
        [[nodiscard]] int x() const { return x1; }

        [[nodiscard]] int y() const { return y1; }

        [[nodiscard]] int xTo() const { return x2; }

        [[nodiscard]] int yTo() const { return y2; }

        Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

        [[nodiscard]] bool isIn(int x, int y) const override{
            return x1 <= x && x <= x2 && y1 <= y && y <= y2;
        }
    private:
        int x1;
        int y1;
        int x2;
        int y2;
    };
}

#endif //ZAD4SHAPEDRAWING_RECTANGLE_H
