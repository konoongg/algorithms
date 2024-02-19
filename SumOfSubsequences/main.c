#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define SIZE_HASHTABLE 700000

struct THash {
    int value;
    int countSum;
};

void AddIndexInHashTable(struct THash* hashTable, long long prefSum) {
    int id = prefSum % SIZE_HASHTABLE;
    if (id < 0) {
        id *= -1;
        id = SIZE_HASHTABLE - id - 1;
    }
    hashTable[id].countSum += 1;
    hashTable[id].value = prefSum;
}

int main(void) {
    int salaryNeed, days;
    scanf_s("%d %d", &salaryNeed, &days);
    struct THash* hashTable = (struct THash*)malloc(sizeof(struct THash) * SIZE_HASHTABLE);
    for (int i = 0; i < SIZE_HASHTABLE; ++i) {
        hashTable[i].countSum = 0;
    }
    int salary;
    long long prefSum = 0;
    int countChocolate = 0;
    for (int i = 0; i < days; ++i) {
        scanf("%d", &salary);
        prefSum += salary;
        if (prefSum == salaryNeed) {
            ++countChocolate;
        }
        long long findSum = (prefSum - salaryNeed);
        findSum %= SIZE_HASHTABLE;
        if (findSum < 0) {
            findSum *= -1;
            findSum = SIZE_HASHTABLE - findSum - 1;
        }
        if (hashTable[findSum].countSum != 0) {
            countChocolate += hashTable[findSum].countSum;
        }
        AddIndexInHashTable(hashTable, prefSum);
    }
    printf("%d", countChocolate);
	return 0;
}

