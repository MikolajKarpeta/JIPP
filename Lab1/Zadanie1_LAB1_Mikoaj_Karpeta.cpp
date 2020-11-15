#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc , char *argv[])
{
    int TAB[argc-1];
    for(int i = 1; i < argc; ++i){
        TAB[i-1] = atoi(argv[i]);
    }

    int a;
    for (int j = 0; j < argc; ++j) {
        for (int i = 0; i < (argc-1); ++i) {
            if(TAB[i]>TAB[j]){
                a = TAB[j];
                TAB[j] = TAB[i];
                TAB[i] = a;

            }
        }
    }

    for (int k = 0; k < (argc-1); ++k){
        printf("[%d] ", TAB[k]);
    }
    return 0;
}