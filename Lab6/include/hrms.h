#include "employee.h"
#include <map>
#include <vector>
#include <algorithm>

#ifndef LAB6_HRMS_H
#define LAB6_HRMS_H


class hrms {
private:
    std::map <std::string, class Employee> AllEmployees;
    std::map <std::string, std::vector<std::string>> Departments;
    std::map <std::string, double> Salaries;
public:
    hrms();
    void add(Employee employee, std::string departmentID, double salary);
    void printDepartment(std::string DepartmentID);
    void changeSalary(std::string employeeId, double salary);
    void printSalaries();
    void printSalariesSorted();
};


#endif //LAB6_HRMS_H
