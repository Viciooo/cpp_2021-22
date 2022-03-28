#ifndef MATRIX_H
#define MATRIX_H

/** @file matrix.h
@brief Przeciążanie operatorów na przykładzie Macierzy:
1. Zaimplementuj klasę TwoDimensionMatrix odzwierciedlajaca macierz 2*2, zawierającą:
    - tablice typu MatrixElement (tzn. int), oraz size (=2)
    - konstruktory:
        - bezargumentowy - zerujący wszystkie elementy
        - kopiujący
        - przyjmujący jako argument tablicę (const MatrixElement matrix[size][size]) i kopiujący z niej wartości
    - funkcja składowa do dostępu do elementów (get() zwracająca odpowiedni element
    - funkcja zwracająca size o nazwie (getSize()), proponuję aby była static constexpr
2. Uzupełnij klasy o następujące operacje zdefiniowane poprzez przeciążenie operatorów:
    - operator przypisania kopiujący (głęboko): operator=()
    - operatory wypisywania do strumienia (funkcja zewn.) - forma dowolna, byleby wszystkie elementy były w strumieniu
    - operatory wczytywania z strumienia (funkcja zewn.) - format dla macierzy:
      { a, b }
      { c, d }
      powinno się odbyć:
      ```
        a b
        c d
      ```
    - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
        - TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako funkcja globalna
        - TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klasy
        - Zadany operator logiczny (metoda klasy):
          `TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;`
        - operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), **proszę pamiętać o wersji const**
          `MatrixElement* operator[](size_t i);`
        - operator konwersji do size_t, zwracający to co `getSize()` (metoda klasy),
    Deklaracja klasy i funkcji globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w pliku źródłowym "matrix.cpp"
____________________________________________________________________________________
## Uwaga:
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne,
metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane
poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.

Mozna tworzyc dowolna ilosc metod pomocniczych, jednakze aby byly one prywatne.
____________________________________________________________________________________
## Punktacja:
Na maksa przejście wszystkich testów
____________________________________________________________________________________
## Najczestrze pytania:
1. Jak ma działać && dla macierzy?
    Wykonująca na każdym z elementów &&, czyli:
    ```
    { 0, 0 }      { 0, 6 }      { 0, 0 }
    {-3, 9 }  &&  { 0, -9 }  =  { 0, 1 }
    ```
2. Jak ma działać operator tablicowy []?
    Operator ten przyjmuje tylko jeden argument (poza this), a chcemy odnieść się w następujący sposób:
    `matrix[row][column]`, dlatego ten operator musi zwrócić matrix[row] typu `MatrixElement*`.
3. Mam operator indeksowania [], a kompilator jakby go nie widzi.
    To najczęstrzy błąd w tym zadaniu - muszą być dwie wersje - jedna zwykła, a druga stała (przydomek `const`)
____________________________________________________________________________________
# Pytania po implementacji ćwiczenia:
@note A. Jaka jest różnica między przeciążaniem operatorów jako metoda klasy vs jako funkcja?
@note B. Których operatorów nie da się przeciążać?
@note C. Wymień operatory mające różną ilość argumentów?
@note D. Jakie konsekwencje będzie miało przeciążanie operatorów logicznych? (chodzi o lazy-evaluation)
**/

#include <iosfwd>

#include "matrixElement.h"



class TwoDimensionMatrix {
    constexpr static size_t size = 2;

public:

    TwoDimensionMatrix();

    explicit TwoDimensionMatrix(const MatrixElement matrix[size][size]);
    TwoDimensionMatrix(const TwoDimensionMatrix &other);

    constexpr static size_t getSize() {
        return size;
    };

    [[nodiscard]] MatrixElement get(int row, int column) const{
        return matrix[row][column];
    }
    const MatrixElement *  operator[](size_t i) const{
        return this->matrix[i];
    };
    MatrixElement *  operator[](size_t i){
        return this->matrix[i];
    };

    friend std::ostream& operator<<(std::ostream& os, const TwoDimensionMatrix& dt){
        os << dt.get(0,0)<< dt.get(1,0)<< dt.get(0,1)<< dt.get(1,1);
        return os;
    }

    friend std::istream &operator>>(std::istream  &input,TwoDimensionMatrix &dt ) {
        input >> dt.matrix[0][0]>> dt.matrix[0][1]>> dt.matrix[1][0]>> dt.matrix[1][1];
        return input;
    }

    constexpr TwoDimensionMatrix& operator*=(const int item)
    {
        for (int i = 0; i < TwoDimensionMatrix::getSize(); ++i) {
            for (int j = 0; j < TwoDimensionMatrix::getSize(); ++j) {
                this->matrix[i][j] *= item;
            }
        }
        return *this;
    }

    friend TwoDimensionMatrix operator+(TwoDimensionMatrix lhs,const TwoDimensionMatrix& rhs)
    {
        for (int i = 0; i < TwoDimensionMatrix::getSize(); ++i) {
            for (int j = 0; j < TwoDimensionMatrix::getSize(); ++j) {
                lhs.matrix[i][j] += rhs.matrix[i][j];
            }
        }
        return lhs;
    }

    friend TwoDimensionMatrix operator&&(TwoDimensionMatrix lhs,const TwoDimensionMatrix& rhs)
    {
        for (int i = 0; i < TwoDimensionMatrix::getSize(); ++i) {
            for (int j = 0; j < TwoDimensionMatrix::getSize(); ++j) {
                lhs.matrix[i][j] = lhs.matrix[i][j] && rhs.matrix[i][j];
            }
        }
        return lhs;
    }

    explicit operator size_t() const{
        return getSize();
    }


private: // fields:
    MatrixElement matrix[size][size]{};
};



#endif // MATRIX_H
