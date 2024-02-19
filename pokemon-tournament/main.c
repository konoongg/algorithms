#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int Fight(int* pok, int countPok, int* pow) {
    //printf(" start %d %d\n", countPok, *pow);
    size_t newIndex = 0;
    int f = 0;
    while (newIndex + *pow < countPok) {
        f = 1;
        pok[newIndex] = (int)sqrt(pok[newIndex] * pok[newIndex + *pow]);
        newIndex += 2 * ( * pow);
    }
    if (f == 0) {

        return pok[0];
    }
    *pow *= 2;
    return Fight(pok, countPok, pow);
}

int main() {
    int countPok;
    if (scanf_s("%d", &countPok) == -1) {
        return 0;
    }
    if (getchar() == -1) {
        return 0;
    }
    int* pok = (int*)malloc(sizeof(int) * countPok);
    char c = 0;
    int hp = 0;
    int pow = 1;
    for (size_t i = 0; i < countPok; ++i) {
        scanf_s("%d", &pok[i]);
    }
    int totalHp = Fight(pok, countPok, &pow);
    printf("%d", totalHp);
    free(pok);
    return 0;
}

