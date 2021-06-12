#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student {
    std::string firstName;
    std::string middleName;
    std::string lastName;
    int yearofbirth;
    long int personID;
    double grade;

public:
    Student();
    Student(const std::string& i, const std::string& o, const std::string& f, int year, long int id, double grade);
    friend ostream& operator<< (ostream& o, const Student& student);
    friend istream& operator>>(istream& i, Student& student);
    long int GetID();
    std::string GetName();
    std::string GetFullName();
    bool operator>(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator==(const Student& other) const;
    friend string to_string(const Student& student);
};

#endif
