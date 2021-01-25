#include <iomanip>
#include <iostream>
#include "Macierz.h"



int main() {
    int wiersze=5, kolumny=5, wymiar=5;

    Macierz macierz_kwadratowa(wymiar);
    macierz_kwadratowa.print();
    Macierz macierz_prostokatna(wiersze, kolumny);
    macierz_prostokatna.print();

    macierz_kwadratowa.set(4,2,2.23);
    macierz_prostokatna.set(1,3,2.43);

    printf("%lf",macierz_kwadratowa.get(4,2));
    printf("\n%lf\n", macierz_prostokatna.get(1,3));

    Macierz macierz_liczenie(wiersze,kolumny);
    macierz_liczenie=macierz_prostokatna.add(macierz_kwadratowa);
    macierz_liczenie.print();

    macierz_liczenie=macierz_prostokatna.subtrack(macierz_kwadratowa);
    macierz_liczenie.print();

    macierz_liczenie=macierz_prostokatna.multyply(macierz_kwadratowa);
    macierz_liczenie.print();

    printf("\nLiczba wierszy to - %d",macierz_liczenie.wiersze_tab());
    printf("\nLiczba kolumnt to - %d",macierz_liczenie.kolumny_tab());

    macierz_kwadratowa.store();

    macierz_liczenie=macierz_prostokatna.multyply(macierz_kwadratowa);
    macierz_liczenie.print();
    return 0;
}
