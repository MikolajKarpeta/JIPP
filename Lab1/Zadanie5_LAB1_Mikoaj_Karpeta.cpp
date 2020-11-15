

#include <cstdio>

int main(){

    double TAB1[2][3];
    double TAB2[2][3];
    double TAB3[2][3];

    printf("Podaj argumenty pierwszej tablicy");
    for (int i = 0; i < 2; ++i) {
        printf("\n");
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &TAB1[i][j]);
            printf("[%lf] ", TAB1[i][j]);

        }
    }

    printf("Podaj argumenty drugiej tablicy");
    for (int i = 0; i < 2; ++i) {
        printf("\n");
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &TAB2[i][j]);
            printf("[%lf] ", TAB2[i][j]);

        }
    }

    printf("Tablica po dodaniu to\n");
    for (int k = 0; k < 2; ++k) {
        printf("\n");
        for (int i = 0; i < 3; ++i) {
            TAB3[k][i] = TAB1[k][i] +  TAB2[k][i];
            printf("[%lf] ", TAB3[k][i]);
        }
    }

}