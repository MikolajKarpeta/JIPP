#include <iostream>
#include <algorithm> //swap

using std::cout;
using std::endl;

void swap(int &v1, int *v2){

        int temp = v1;
        v1 = *v2;
        *v2 = temp;

}

int main(int argc, char *argv[]){

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("Para: '%d'   '%d' ", a, b);

    swap(a,&b);

    printf("Wynik:  '%d'   '%d' ", a, b);
}