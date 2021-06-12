#include "Student.h"

Student::Student() {
    this->firstName = "Nikita";
    this->middleName = "Nikitich";
    this->lastName = "Nikitov";
    this->yearofbirth = 0;
    this->personID = 0;
    this->grade = 0;
}

Student::Student(const std::string& i, const std::string& o, const std::string& f, int year, long id, double grade) {
    this->firstName = i;
    this->middleName = o;
    this->lastName = f;
    this->yearofbirth = year;
    this->personID = id;
    this->grade = grade;
}

ostream& operator<<(ostream& o, const Student& student) {
    o << student.firstName << " " << student.middleName << " " << student.lastName << std::endl;
    return o;
}

istream& operator>>(istream& i, Student& student) {
    i >> student.firstName >> student.middleName >> student.lastName >> student.yearofbirth >> student.personID >> student.grade;
    return i;
}

long int Student::GetID() {
    return this->personID;
}

std::string Student::GetName() {
    return this->firstName;
}

std::string Student::GetFullName() {
    return this->firstName+" "+this->middleName+" "+this->lastName;
}
bool Student::operator>(const Student& other) const{
    if (this->firstName == other.firstName){
        if (this->lastName == other.lastName){
            return this->middleName > other.middleName;
        } else return this->lastName > other.lastName;
    } else return this->firstName > other.firstName;
}
bool Student::operator<(const Student& other) const{
    if (this->firstName == other.firstName){
        if (this->lastName == other.lastName){
            return this->middleName < other.middleName;
        } else return this->lastName < other.lastName;
    } else return this->firstName < other.firstName;
}
bool Student::operator==(const Student& other) const{
    return this->firstName == other.firstName && this->lastName == other.lastName && this->middleName == other.middleName;
}

string to_string(const Student& student) {
    return student.firstName + " " + student.middleName + " " + student.lastName;
}





