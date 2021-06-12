#ifndef LAB3_FUNCTOR_H
#define LAB3_FUNCTOR_H
#include "Teacher.h"
#include "Complex.h"
#include "Student.h"
#include <cmath>
template<typename T>
class Functor{
public:
    virtual bool operator()(T value) const = 0;

    virtual T operator()(const T& old, const T& value) const = 0;
};

class IntFunctor : public Functor<int>{
public:
    bool operator()(int value) const override {
        return value > 0;
    }

    int operator()(const int& old, const int& value) const override {
        return old * value;
    }
};

class TeacherFunctor : public Functor<Teacher>{
public:
    bool operator()(Teacher value) const override {
        Teacher klm("Kkkkkkkk", "Lllllllll", "Mmmmmmmm", 1900, 0, 12000);
        return value > klm;
    }

    Teacher operator()(const Teacher& old, const Teacher& value)  const override{
        return value;
    }
};

class StudentFunctor : public Functor<Student>{
public:
    bool operator()(Student value) const override {
        Student nop("Nnnnnnn", "Oooooo", "Ppppp", 1000, 0, 0);
        return value > nop;
    }

    Student operator()(const Student& value, const Student& value1)  const override{
        return value1;
    }
};
class ComplexFunctor : public Functor<Complex>{
public:
    bool operator()(Complex value) const override{
        return value.abs() > 10 && value.GetIm() < 0;
    }
    Complex operator()(const Complex& value, const Complex& value2) const override{
        Complex res(value.GetIm(), value2.GetRe());
        return res;
    }
};
class FloatFunctor : public Functor<float>{
public:
    bool operator()(float value) const override{
        return abs(value) < 101;
    }
    float operator()(const float& value1, const float& value2) const override{
        return sqrt(value1*3);
    }
};
#endif
