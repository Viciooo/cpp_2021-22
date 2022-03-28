#include <iostream>
#include <utility>

using namespace std;

#include "fraction.h"

#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
#warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
#pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists

int Fraction::removedFractions_ = 0;


int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numerator) {
    Fraction::numerator = numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    Fraction::denominator = denominator;
}

void Fraction::print() const {
    cout << numerator << "/" << denominator << endl;
}

int Fraction::removedFractions() {
    return removedFractions_;
}

Fraction::~Fraction() {
    removedFractions_++;
}

void Fraction::load(istream &is) {
    string s;
    is >> s;
    numerator = stoi(s.substr(0, s.find('/')));
    denominator = stoi(s.substr(s.find('/') + 1, s.length()));
}

void Fraction::save(ostream &os) const {
    string s = to_string(Fraction::numerator) + '/' + to_string(Fraction::denominator);
    os << s;
}

Fraction::Fraction(int numerator, int denominator, std::string fractionName) : numerator(numerator),
                                                                               denominator(denominator),
                                                                               fractionName(std::move(fractionName)) {}

const string &Fraction::getFractionName() const {
    return fractionName;
}

