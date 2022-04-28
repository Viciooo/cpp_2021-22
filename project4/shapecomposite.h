//
// Created by Piotr on 28.04.2022.
//

#ifndef ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H

#include <memory>
#include <utility>
#include "shape.h"

namespace Shapes {
    enum ShapeOperation {INTERSECTION,SUM,DIFFERENCE};

    class ShapeComposite : public Shape{
    public:
        ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                       ShapeOperation operation): shape_1(std::move(shape1)), shape_2(std::move(shape2)), operation(operation){};

        [[nodiscard]] bool isIn(int x, int y) const override{
            switch (operation) {
                case ShapeOperation::INTERSECTION:
                    return shape_1->isIn(x,y) && shape_2->isIn(x,y);
                case ShapeOperation::SUM:
                    return shape_1->isIn(x,y) || shape_2->isIn(x,y);
                case ShapeOperation::DIFFERENCE:
                    return shape_1->isIn(x,y) ^ shape_2->isIn(x,y);
            }
        }

    private:
        std::shared_ptr<Shape> shape_1;
        std::shared_ptr<Shape> shape_2;
        ShapeOperation operation;
    };
}

#endif //ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
