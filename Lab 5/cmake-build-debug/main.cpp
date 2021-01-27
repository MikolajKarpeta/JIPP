#include <iomanip>
#include <iostream>
#include "Macierz.h"



int main() {
    int wiersze=5, kolumny=5, wymiar=5;

    Macierz macierz_kwadratowa(wymiar);
    macierz_kwadratowa.print();
    std::cout<<"\n\n";

    Macierz macierz_prostokatna(wiersze, kolumny);
    macierz_prostokatna.print();
    std::cout<<"\n\n";

    macierz_kwadratowa.set(4,2,2.23);
    macierz_prostokatna.set(1,3,2.43);

    printf("%lf",macierz_kwadratowa.get(4,2));
    printf("\n%lf\n", macierz_prostokatna.get(1,3));

    Macierz macierz_liczenie(wiersze,kolumny);
    macierz_liczenie=macierz_prostokatna.add(macierz_kwadratowa);
    macierz_liczenie.print();
    std::cout<<"\n\n";

    macierz_liczenie=macierz_prostokatna.subtrack(macierz_kwadratowa);
    macierz_liczenie.print();
    std::cout<<"\n\n";

    macierz_liczenie=macierz_prostokatna.multyply(macierz_kwadratowa);
    macierz_liczenie.print();
    std::cout<<"\n\n";

    printf("\nLiczba wierszy to - %d",macierz_liczenie.wiersze_tab());
    printf("\nLiczba kolumnt to - %\n\n",macierz_liczenie.kolumny_tab());

    macierz_kwadratowa.store();

    macierz_liczenie=macierz_prostokatna.multyply(macierz_kwadratowa);
    macierz_liczenie.print();
    std::cout<<"\n\n";


    //OPERATORY

    std::cout <<"\nOPERATORY\n";

    Macierz piersza(wymiar);
    Macierz druga(wiersze, kolumny);

    --piersza;
    piersza.print();
    std::cout<<"\n\n";
    ++druga;
    druga.print();

    if(piersza!=druga){
        std::cout << "Te macierze nie sa rowne\n" ;
    }
    if(piersza==druga){
        std::cout <<"Te macierze sa równe\n\n";
    }

    druga = piersza-druga;
    druga.print();
    std::cout<<"\n\n";
    piersza = druga+piersza;
    piersza.print();
    std::cout<<"\n\n";

    piersza = piersza*druga;
    piersza.print();

    return 0;
}
