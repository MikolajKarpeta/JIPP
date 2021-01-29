#include "hrms.h"

hrms::hrms() {};

void hrms::add(Employee pracownik, std::string departmentID, double salary) {
    this -> AllEmployees[pracownik.getID()] = pracownik;
    this -> Departments[pracownik.getDepartmentID()].push_back(pracownik.getID());
    this -> Salaries[pracownik.getID()] = salary;
}

void hrms::printDepartment(std::string DepartmentID) {

    std::cout << "|| Pracownicy departamentu  " << DepartmentID << " ||" << std::endl;

    for(auto &IDpracownika : Departments[DepartmentID]) {
        std::cout << IDpracownika << std::endl;
    }
}

void hrms::changeSalary(std::string employeeID, double Salary) {
     Salaries[employeeID] = Salary;
}

void hrms::printSalaries() {

    std::cout << "|| Lista Pracownikow ||" << std::endl;

    for(auto &pracownik :  Salaries) {
        std::cout << "ID: " << pracownik.first << std::endl;
        std::cout << "Name: " << AllEmployees.at(pracownik.first).getName() << std::endl;
        std::cout << "Surname: " << AllEmployees.at(pracownik.first).getSurname() << std::endl;
        std::cout << "Department: " << AllEmployees.at(pracownik.first).getDepartmentID() << std::endl;
        std::cout << "Position: " << AllEmployees.at(pracownik.first).getPosition() << std::endl;
        std::cout << "Salary: " << pracownik.second << std::endl << std::endl;
    }
}

void hrms::printSalariesSorted() {
    std::vector <std::pair <Employee, double>> sorted;
    for(auto &element :  AllEmployees) {
        sorted.push_back(std::make_pair(element.second, Salaries[element.second.getID()]));
    }

    std::sort(sorted.begin(), sorted.end(), [](std::pair <Employee, double>& a, std::pair <Employee, double>& b) {
        return (a.second < b.second);
    });

    std::cout << "|| Pracownicy posortowani wysokoscia wynagrodzenia ||" << std::endl;

    for(auto &pracownik : sorted) {
        std::cout << "ID: " << pracownik.first.getID() << std::endl;
        std::cout << "Name: " << pracownik.first.getName() << std::endl;
        std::cout << "Surname: " << pracownik.first.getSurname() << std::endl;
        std::cout << "Department: " << pracownik.first.getDepartmentID() << std::endl;
        std::cout << "Position: " << pracownik.first.getPosition() << std::endl;
        std::cout << "Salary: " << pracownik.second << std::endl << std::endl;
    }
}