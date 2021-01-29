#include <iostream>

#ifndef LAB6_EMPLOYEE_H
#define LAB6_EMPLOYEE_H


class Employee {
private:
    std::string ID;
    std::string Name;
    std::string Surname;
    std::string DepartmentID;
    std::string Position;
public:
    Employee(std::string NewID, std::string NewName, std::string NewSurname, std::string NewDepartmentID, std::string NewPosition);
    Employee();
    std::string getID();
    std::string getName();
    std::string getSurname();
    std::string getDepartmentID();
    std::string getPosition();
};

#endif //LAB6_EMPLOYEE_H
