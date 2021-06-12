#include "Teacher.h"

Teacher::Teacher() {
    this->firstName = "Ilia";
    this->middleName = "Iliych";
    this->lastName = "Iliev";
    this->yearofbirth = 0;
    this->personID = 0;
    this->pay = 12000;
}

Teacher::Teacher(const std::string& i, const std::string& o, const std::string& f, int year, long id, int pay) {
    this->firstName = i;
    this->middleName = o;
    this->lastName = f;
    this->yearofbirth = year;
    this->personID = id;
    this->pay = pay;
}

ostream& operator<<(ostream& o, const Teacher& teacher) {
    o<<teacher.firstName<<" "<<teacher.middleName<<" "<<teacher.lastName<<std::endl;
    return o;
}

istream& operator>>(istream& i, Teacher& teacher) {
    i>>teacher.firstName>>teacher.middleName>>teacher.lastName>>teacher.yearofbirth>>teacher.personID>>teacher.pay;
    return i;
}
bool Teacher::operator>(const Teacher& other) const{
    if (this->firstName == other.firstName){
        if (this->lastName == other.lastName){
            return this->middleName > other.middleName;
        } else return this->lastName > other.lastName;
    } else return this->firstName > other.firstName;
}
bool Teacher::operator<(const Teacher& other) const {
    if (this->firstName == other.firstName){
        if (this->lastName == other.lastName){
            return this->middleName < other.middleName;
        } else return this->lastName < other.lastName;
    } else return this->firstName < other.firstName;
}
bool Teacher::operator==(const Teacher& other) const{
    return this->firstName == other.firstName && this->lastName == other.lastName && this->middleName == other.middleName;
}

string to_string(const Teacher& teacher) {
    return teacher.firstName + " " + teacher.middleName + " " + teacher.lastName;
    //to_string(obj.personID)
}
