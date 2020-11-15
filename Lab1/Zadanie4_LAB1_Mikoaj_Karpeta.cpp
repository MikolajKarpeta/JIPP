#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a, b;
    int sumaa = 0, sumab = 0;
    printf("Podaj 2 liczby całkowite");
    scanf("%d%d", &a, &b);

    for (int i = 1; i < a; ++i) {
        if(a%i == 0) sumaa = sumaa+i;
    }

    for (int i = 1; i < b; ++i) {
        if (b%i == 0)sumab = sumab + i;

   }

    if(sumaa==b+1 && sumab ==a+1)printf("Te liczby są ze sobą skojarzone");
    else printf("Te liczby nie są ze soba skojarzone");
}