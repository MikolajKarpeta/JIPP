#include <iostream>


int main(){
    float waga;
    float wzrost;
    float BMI;

    printf("Podaj mase ciała w kg - ");
    scanf("%f", &waga);
    printf("\nPodaj wzrost w m - ");
    scanf("%f", &wzrost);

    BMI = waga / (wzrost*wzrost);
    printf("Twoje BMI to - %f", BMI);

    printf("Zakresy wartości BMI:\n"
           "mniej niż 16 - wygłodzenie\n"
           "16 - 16.99 - wychudzenie\n"
           "17 - 18.49 - niedowaga\n"
           "18.5 - 24.99 - wartość prawidłowa\n"
           "25 - 29.99 - nadwaga\n"
           "30 - 34.99 - I stopień otyłości\n"
           "35 - 39.99 - II stopień otyłości\n"
           "powyżej 40 - otyłość skrajna");
}