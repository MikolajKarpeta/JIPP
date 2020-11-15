#include <iostream>
#include <algorithm> //swap

using std::cout;
using std::endl;

int swap(int *v1, int *v2){

        int ilocz = *v1 * *v2;
        int suma = *v1 + *v2;
        *v1 = suma;
    return (ilocz);
}

int main(int argc, char *argv[]){

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("Para: '%d'   '%d' ", a, b);

    int ilocz = swap(&a, &b);

    printf("Iloczyn: %d Suma: %d ", ilocz, a);
}