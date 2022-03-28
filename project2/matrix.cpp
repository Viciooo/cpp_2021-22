#include <iostream>
#include <string>

using namespace std;

#include "matrix.h"
#include "matrixElement.h"
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement (*matrix_)[2]) {
    for (int i = 0; i < TwoDimensionMatrix::getSize(); ++i) {
        for (int j = 0; j < TwoDimensionMatrix::getSize(); ++j) {
            this->matrix[i][j] = matrix_[i][j];
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &other) {
    for (int i = 0; i < TwoDimensionMatrix::getSize(); ++i) {
        for (int j = 0; j < TwoDimensionMatrix::getSize(); ++j) {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix() {
    for (int i = 0; i < TwoDimensionMatrix::getSize(); ++i) {
        for (int j = 0; j < TwoDimensionMatrix::getSize(); ++j) {
            this->matrix[i][j] = MatrixElement(0);
        }
    }
}








