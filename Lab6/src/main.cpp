#include <iostream>
#include <string.h>

#include "employee.cpp"
#include "hrms.cpp"


    int main() {

        Employee pracownik1("001", "Leszek","Grucel","Z","Dyrektor");
        Employee pracownik2("002", "Maciej", "Narta", "Z", "Kierownik");
        Employee pracownik3("003", "Radek", "Garb", "O", "Ochroniarz");
        Employee pracownik4("004", "Piotr", "Nadolski", "O","Ochroniarz");
        Employee pracownik5("005", "Jakub", "Telefon", "P", "Programista");
        Employee pracownik6("006", "Mikolaj", "Nalesnik", "P","Programista");
        Employee pracownik7("007", "Szymon", "Kojder", "P", "Programista");
        Employee pracownik8("008", "Kamil", "Durlik", "P", "Programista");

        hrms var;

        var.add(pracownik1,"Z",62300.0);
        var.add(pracownik2,"Z",34600.0);
        var.add(pracownik3,"O",2800.0);
        var.add(pracownik4,"O",3000.0);
        var.add(pracownik5,"P",2400.0);
        var.add(pracownik6,"P",15000.0);
        var.add(pracownik7,"P",9100.0);
        var.add(pracownik8,"P",8800.0);

        var.printSalaries();
        var.printSalariesSorted();


        var.printDepartment("P");

        var.changeSalary(pracownik2.getID(), 156400.0);
        var.changeSalary("005", 1500.0);

        var.printSalariesSorted();

        return 0;
    }