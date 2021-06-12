#ifndef LAB3_TEACHER_H
#define LAB3_TEACHER_H
#include <iostream>
#include <string>
using namespace std;
class Teacher {
    std::string firstName;
    std::string middleName;
    std::string lastName;
    int yearofbirth;
    long int personID;
    int pay;

public:
    Teacher();
    Teacher(const std::string& i, const std::string& o, const std::string& f, int year, long int id, int pay);
    friend ostream& operator<< (ostream& o, const Teacher& teacher);
    friend istream& operator>>(istream& i, Teacher& teacher);
    bool operator>(const Teacher& other) const;
    bool operator<(const Teacher& other) const ;
    bool operator==(const Teacher& other) const;
    friend string to_string(const Teacher& teacher);
};


#endif
