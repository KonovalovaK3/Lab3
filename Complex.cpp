#include "Complex.h"
#include <cmath>
#include <string>
Complex::Complex() {
    this->Re = 0;
    this->Im = 0;
}

Complex::Complex(double Re, double Im) {
    this->Re = Re;
    this->Im = Im;
}

ostream& operator<<(ostream& o, const Complex& c) {
    o<<"("<<c.Re<<"; "<<c.Im<<")";
    return o;
}

istream& operator>>(istream& i, Complex& c) {
    i>>c.Re>>c.Im;
    return i;
}


bool Complex::operator<(const Complex& other) const{
    return this->abs() < other.abs();
}

double Complex::abs() const{
    double a = this->Re*this->Re + this->Im*this->Im;
    a = sqrt(a);
    return a;
}

bool Complex::operator>(const Complex& other) const{
    return this->abs() > other.abs();
}
bool Complex::operator==(const Complex& other) const{
    return this->abs() == other.abs();
}
double Complex::GetRe() const{
    return this->Re;
}
double Complex::GetIm() const{
    return this->Im;
}


string to_string(const Complex& ri) {
    return to_string(ri.Re) + "+" + to_string(ri.Im) + "*i";
}
