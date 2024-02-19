#include <stdlib.h>
#include <stdio.h>

int F(int value, int position, int seed) {
    int result = 0;
    for (size_t i = 1; i <= seed * seed; ++i) {
        result = (result + (i % 2 ? value + 1 : position + 1) * i * seed) % 10;
    }
    return result;
}

int ChangeMax(int* curCount, int* max, int** ms, int* count, int* maxCur, int size) {
    for (int i = size - 1; i >= 0; --i) {
        if (curCount[i] > 1) {
            //printf("cur c %d \n", curCount[i]);
            --curCount[i];
            for (int j = 9; j >= 0; --j) {
                if (ms[i][j] == 1 && j < maxCur[i]) {
                    //printf("%d jj \n",j);
                    maxCur[i] = j;
                    break;
                }
            }
            for (int j = i + 1; j < size; ++j) {
                curCount[j] = count[j];
                maxCur[j] = max[j];
            }
            return 0;
        }
    }
    return 1;
}


int main() {
    int size, seed;
    scanf_s("%d %d", &size, &seed);
    int** ms = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        ms[i] = (int*) calloc(size, sizeof(int));
    }
    int* msMax = (int*)calloc(size, sizeof(int));
    int* msCount = (int*)calloc(size, sizeof(int));
    int* number = (int*)malloc(size * sizeof(int));
    getchar();
    int c;
    for (int i = 0; i < size; ++i) {
        c = getchar() - '0';
        number[i] = c;
    }
    for (int i = 0; i < size; ++i) {
        int countNum = 0;
        for (int j = 0; j < 10; ++j) {
            int nuwNum = F(j, i, seed);
            if (nuwNum == number[i]) {
                printf("input %d %d\n", j,i);
                countNum = 1;
                ms[i][j] = 1;
                msCount[i] += 1;
                msMax[i] = j;
            }
        }
        if (countNum == 0) {
            printf("No solutions");
            return 0;
        }
    }
    int counter = 0;

    int* msCountCur = (int*)calloc(size, sizeof(int)); 
    int* msMaxCur = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        msMaxCur[i] = msMax[i];
        //printf("mk %d %d %d \n", i, msMaxCur[i], msMax[i]);
        msCountCur[i] = msCount[i];
    }
        while (counter < 5 ){
        for (int i = 0; i < size; ++i) {
            printf("%d", msMaxCur[i]);
        }
        if (ChangeMax(msCountCur, msMax, ms, msCount, msMaxCur,size) == 1 ) {
           break;
        }
        ++counter;
        printf("\n");
    }
    return 0;
}