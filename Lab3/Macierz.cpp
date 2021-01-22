#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Macierz.h"


Macierz::Macierz(int wiersze, int kolumny) {
    this->macierz1 = new double*[wiersze];
    for (int i = 0; i < wiersze; ++i) {
        this->macierz1[i] = new double[kolumny];
        std::fill(this->macierz1[i], this->macierz1[i] + kolumny, 0);

    }
    this->wiersze = wiersze;
    this->kolumny = kolumny;
    }

    Macierz::Macierz(int wymiar) {
    this->macierz1 = new double*[wymiar];
    for (int i = 0; i < wymiar; ++i) {
        this->macierz1[i] = new double[wymiar];
        std::fill(this->macierz1[i], this->macierz1[i] + wymiar, 0);
    }
    this->wiersze = wymiar;
    this->kolumny = wymiar;
}

    void Macierz::set(int n, int m, double val){
    if(n<wiersze&& m < kolumny && m >= 0 && n >= 0)macierz1[n][m]=val;
}

double Macierz::get(int n, int m){
   // if(n<wiersze&& m < kolumny && m >= 0 && n >= 0){
        return macierz1[n][m];
    //}
}

int  Macierz::wiersze_tab(){
    return wiersze;
}

int  Macierz::kolumny_tab(){
    return kolumny;
}
void Macierz::print() {
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            printf("[%lf] ", macierz1[i][j]);
            if (j==kolumny-1)printf("\n");
        }
    }
}

Macierz Macierz::add(Macierz macierz2) {
    int kolumny2 = macierz2.kolumny;
    int wiersze2 = macierz2.wiersze;
    if(kolumny == kolumny2 && wiersze == wiersze2) {
        Macierz nowa(wiersze, kolumny);
        for (int i = 0; i < wiersze; i++)
            for (int j = 0; j < kolumny; j++)
                nowa.macierz1[i][j] = macierz1[i][j] + macierz2.macierz1[i][j];
        return nowa;
    }else exit(1);
}

Macierz Macierz::subtrack(Macierz macierz2) {
    int kolumny2 = macierz2.kolumny;
    int wiersze2 = macierz2.wiersze;
    if (kolumny == kolumny2 && wiersze == wiersze2) {
        Macierz nowa(wiersze, kolumny);
        for (int i = 0; i < wiersze; i++)
            for (int j = 0; j < kolumny; j++)
                nowa.macierz1[i][j] = macierz1[i][j] - macierz2.macierz1[i][j];
        return nowa;
    }else exit(1);
}

Macierz Macierz::multyply(Macierz macierz2) {
   int kolumny2 = macierz2.kolumny;
   int wiersze2 = macierz2.wiersze;

   if(wiersze == kolumny2){
       Macierz nowa(wiersze,kolumny2);
       double temp=0.0;
       for(int i=0; i<wiersze; i++){
           for(int j=0; j<kolumny2; j++){
               temp=0.0;
               for (int k=0; k<kolumny; k++){
                   temp += macierz1[i][k] * macierz2.macierz1[k][j];
               }
               nowa.macierz1[i][j] = temp;
           }
       }
       return nowa;

   }else exit(1);

}
void Macierz::store() {
        std::fstream plik;
        plik.open("macierz.txt",std::ios::out);
        plik<<wiersze<<"   ";
        plik<<kolumny<<std::endl;
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            plik<<macierz1[i][j]<<" ";
            if (j==kolumny-1)plik<<std::endl;
        }
    }

        plik.close();
}

