#ifndef LAB3_COMPLEX_H
#define LAB3_COMPLEX_H
#include "iostream"
using namespace std;

class Complex {
    double Re;
    double Im;

public:
    Complex();
    Complex(double Re, double Im);
    friend ostream& operator<< (ostream& o, const Complex& c);
    friend istream& operator>>(istream& i, Complex& c);
    double abs() const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator==(const Complex& other) const;
    double GetRe() const;
    double GetIm() const;
    friend string to_string(const Complex& ri);
};


#endif
