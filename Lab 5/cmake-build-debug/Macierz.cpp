#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Macierz.h"


Macierz::Macierz(int wiersze, int kolumny) {
    try {
        if (wiersze < 1)
            throw 1;
        if (kolumny < 1)
            throw 2;
        this->macierz1 = new double *[wiersze];
        for (int i = 0; i < wiersze; ++i) {
            this->macierz1[i] = new double[kolumny];
            std::fill(this->macierz1[i], this->macierz1[i] + kolumny, 0);

        }
        this->wiersze = wiersze;
        this->kolumny = kolumny;
    }
        catch(int e){
            if (e == 1)
                printf("Ilosc wierszy musi byc wieksza od 0\n");
            if (e == 2)
                printf("Ilosc kolumn musi byc wieksza od 0\n");
        }
    }
    Macierz::Macierz(int wymiar) {
        try {
            if (wymiar < 1)
                throw 1;
            this->macierz1 = new double *[wymiar];
            for (int i = 0; i < wymiar; ++i) {
                this->macierz1[i] = new double[wymiar];
                std::fill(this->macierz1[i], this->macierz1[i] + wymiar, 0);
            }
            this->wiersze = wymiar;
            this->kolumny = wymiar;
        }
            catch(int x){
                if (x == 1)
                    printf("Bok macierzy musi byc wiekszy od 0\n");
            }

}

    void Macierz::set(int n, int m, double val){
        try{
            if(n>wiersze-1 or n<0)
                throw 1;
            if(m>kolumny-1 or m<0)
                throw 2;
        macierz1[n][m]=val;
    }
        catch(int x){
            if(x==1)
                printf("Niepoprawna wartosc kolumny\n");
            if(x==2)
                printf("Niepoprawna wartosc wiersza\n");
        }
}

double Macierz::get(int n, int m){

    try{
        if(n>wiersze-1 or n<0)
            throw 1;
        if(m>kolumny-1 or m<0)
            throw 2;
        return macierz1[n][m];
    }
    catch(int x){
        if(x==1)
            printf("Niepoprawna wartosc kolumny\n");
        if(x==2)
            printf("Niepoprawna wartosc wiersza\n");
        exit (1);
    }
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
    try {
        if (macierz2.kolumny_tab() != wiersze)
            throw 1;
        if (macierz2.wiersze_tab() != kolumny)
            throw 2;
        int kolumny2 = macierz2.kolumny;
        int wiersze2 = macierz2.wiersze;

            Macierz nowa(wiersze, kolumny);
            for (int i = 0; i < wiersze; i++)
                for (int j = 0; j < kolumny; j++)
                    nowa.macierz1[i][j] = macierz1[i][j] + macierz2.macierz1[i][j];
                return nowa;
        }
        catch(int x){
            if(x==1)
                std::cout << "Nierowna ilosc wierszy\n";
            if(x==2)
                std::cout << "Nierowna wartosc kolumn\n";
            exit (1);
        }
}

Macierz Macierz::subtrack(Macierz macierz2) {
    try{
        if(macierz2.wiersze_tab() != wiersze)
            throw 1;
        if(macierz2.kolumny_tab() != kolumny)
            throw 2;
    int kolumny2 = macierz2.kolumny;
    int wiersze2 = macierz2.wiersze;
        Macierz nowa(wiersze, kolumny);
        for (int i = 0; i < wiersze; i++)
            for (int j = 0; j < kolumny; j++)
                nowa.macierz1[i][j] = macierz1[i][j] - macierz2.macierz1[i][j];
        return nowa;
    }
        catch(int x){
            if(x==1)
                std::cout << "Nierowna ilosc wierszy\n";
            if(x==2)
                std::cout << "Nierowna wartosc kolumn\n";
            exit (1);
        }
}

Macierz Macierz::multyply(Macierz macierz2) {
   int kolumny2 = macierz2.kolumny;
   int wiersze2 = macierz2.wiersze;
    try {
        if (macierz2.wiersze_tab() != kolumny)
            throw 1;
            Macierz nowa(wiersze, kolumny2);
            double temp = 0.0;
            for (int i = 0; i < wiersze; i++) {
                for (int j = 0; j < kolumny2; j++) {
                    temp = 0.0;
                    for (int k = 0; k < kolumny; k++) {
                        temp += macierz1[i][k] * macierz2.macierz1[k][j];
                    }
                    nowa.macierz1[i][j] = temp;
                }
            }
            return nowa;

        }
        catch(int
        x){
            if (x == 1)
                std::cout << "Wiersze drugiej nierowne kolumnom pierwszej\n";
            exit(1);

        }
    }
void Macierz::store() {
    try {
        std::fstream plik;
        plik.open("macierz.txt", std::ios::out);
        plik << wiersze << "   ";
        plik << kolumny << std::endl;
        for (int i = 0; i < wiersze; ++i) {
            for (int j = 0; j < kolumny; ++j) {
                plik << macierz1[i][j] << " ";
                if (j == kolumny - 1)plik << std::endl;
            }
        }
        plik.close();
    }

        catch(int x){
            if(x==1)
                std::cout << "Nie udalo sie otworzyc pliku\n";
        }
}
Macierz Macierz::operator+(Macierz macierz2){
    try{
        if(macierz2.wiersze_tab() != wiersze)
            throw 1;
        if(macierz2.kolumny_tab() != kolumny)
            throw 2;
        Macierz nowa(wiersze, kolumny);
        for(int i=0; i<wiersze; i++)
            for(int j=0; j<kolumny; j++)
                nowa.macierz1[i][j]=macierz1[i][j]+macierz2.macierz1[i][j];
        return nowa;
    }
    catch(int x){
        if(x==1)
            std::cout << "Nierowna ilosc wierszy\n";
        if(x==2)
            std::cout << "Nierowna wartosc kolumn\n";
        exit (1);
    }
}

Macierz Macierz::operator-(Macierz macierz2){
    Macierz nowa(wiersze, kolumny);
    try{
        if(macierz2.wiersze_tab() != wiersze)
            throw 1;
        if(macierz2.kolumny_tab() != kolumny)
            throw 2;
        for(int i=0; i<wiersze; i++)
            for(int j=0; j<kolumny; j++)
                nowa.macierz1[i][j]=macierz1[i][j]-macierz2.macierz1[i][j];
        return nowa;
    }
    catch(int x){
        if(x==1)
            std::cout << "Nierowna ilosc wierszy\n";
        if(x==2)
            std::cout << "Nierowna wartosc kolumn\n";
        exit (1);
    }
}
Macierz Macierz::operator*(Macierz macierz2){
    try{
        if(macierz2.wiersze_tab() != kolumny)
            throw 1;
        Macierz mnozenie(wiersze, macierz2.kolumny_tab());
        double temp=0.0;
        for(int i=0; i<wiersze; i++){
            for(int j=0; j < macierz2.kolumny_tab(); j++){
                temp=0.0;
                for (int k=0; k<kolumny; k++){
                    temp += macierz1[i][k] * macierz2.macierz1[k][j];
                }
                mnozenie.macierz1[i][j] = temp;
            }
        }
        return mnozenie;
    }
    catch(int x){
        if(x==1)
            std::cout << "Wiersze drugiej nierowne kolumnom pierwszej\n";
        exit (1);
    }
}

bool Macierz::operator==(Macierz macierz2){
    if(kolumny!=macierz2.kolumny_tab())
        return 0;
    if(wiersze!=macierz2.wiersze_tab())
        return 0;
    for(int i=0; i<wiersze; i++)
        for(int j=0; j<kolumny; j++)
            if(macierz2.get(i,j) != macierz1[i][j])
                return 0;
    return 1;
}

bool Macierz::operator!=(Macierz macierz2){
    if(kolumny!=macierz2.kolumny_tab())
        return 1;
    if(wiersze!=macierz2.wiersze_tab())
        return 1;
    for(int i=0; i<wiersze; i++)
        for(int j=0; j<kolumny; j++)
            if(macierz2.get(i,j) != macierz1[i][j])
                return 1;
    return 0;
}



void Macierz::operator++(){
    for(int i=0; i<wiersze; i++)
        for(int j=0; j<kolumny; j++)
            macierz1[i][j]++;
}

void Macierz::operator--(){
    for(int i=0; i<wiersze; i++)
        for(int j=0; j<kolumny; j++)
            macierz1[i][j]--;
}




