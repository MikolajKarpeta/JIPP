
#include <string>
#include <vector>
#include <fstream>

#ifndef JIPP3V2_MACIERZ_H
#define JIPP3V2_MACIERZ_H


class Macierz {
protected:
    int wiersze;
    int kolumny;
    double **macierz1 = nullptr;
public:
    Macierz(int i, int j);
    Macierz(int c);

    int wiersze_tab();
    int  kolumny_tab();

    void set(int n, int m, double val);
    double get(int n, int m);

    Macierz add(Macierz macierz2);
    Macierz subtrack(Macierz macierz2);
    Macierz multyply(Macierz macierz2);

    void print();

    void store();

};


#endif //JIPP3V2_MACIERZ_H
