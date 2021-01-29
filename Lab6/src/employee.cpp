#include "employee.h"

Employee::Employee(std::string NewID, std::string NewName, std::string NewSurname, std::string NewDepartmentID, std::string NewPosition) {
    this -> ID = NewID;
    this -> Name = NewName;
    this -> Surname = NewSurname;
    this -> DepartmentID = NewDepartmentID;
    this -> Position = NewPosition;
}

Employee::Employee() {};

std::string Employee::getID()
{
    return this -> ID;
}

std::string Employee::getName()
{
    return this -> Name;
}

std::string Employee::getSurname()
{
    return this -> Surname;
}
std::string Employee::getDepartmentID()
{
    return this -> DepartmentID;
}

std::string Employee::getPosition()
{
    return this -> Position;
}