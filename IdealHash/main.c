#define _CRT_SECURE_NO_WARNINGS
#define SIZE_HASHTABLE 70000
#define SIZE_STRING 501
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <limits.h>

struct THashNode {
    struct THashNode* Next;
    char* Value;
    int SizeString;
};

struct THash {
    struct THashNode** IdealHashTable;
    int Size;
    unsigned int a;
    unsigned int b;
    struct THashNode* Head;
    struct THashNode* Tail;
};

long long Hash(char* string, int a, int b) {
    long long hash = 0;
    for (int i = 0; i < SIZE_STRING; ++i) {
        if (string[i] == '\0') {
            break;
        }
        hash = ((a * (long long)string[i] + hash + b) % 103889) % SIZE_HASHTABLE;
    }
    return hash;
}

void AddIndexInHashTable(struct THash* hashTable, char* string) {
    int realSizeString = strlen(string) + 1;
    long long hash = Hash(string, 437, 234);
    if (hashTable[hash].Size == 0) {
        hashTable[hash].Head = hashTable[hash].Tail = (struct THashNode*)malloc(sizeof(struct THashNode));
        hashTable[hash].Head->Next = NULL;
        hashTable[hash].Head->Value = (char*)malloc(sizeof(char) * realSizeString);
        hashTable[hash].Head->SizeString = realSizeString;
        strcpy(hashTable[hash].Head->Value, string);
    }
    else {
        hashTable[hash].Tail->Next = (struct THashNode*)malloc(sizeof(struct THashNode));
        hashTable[hash].Tail = hashTable[hash].Tail->Next;
        hashTable[hash].Tail->Next = NULL;
        hashTable[hash].Tail->Value = (char*)malloc(sizeof(char) * realSizeString);
        hashTable[hash].Tail->SizeString = realSizeString;
        strcpy(hashTable[hash].Tail->Value, string);
    }
    ++hashTable[hash].Size;
}

int TryToIdealHash(struct THash* idealHash) {
    struct THashNode* cur = idealHash->Head;
    int size = idealHash->Size * idealHash->Size;
    memset(idealHash->IdealHashTable, 0, size * sizeof(struct THashNode*));
    for (int i = 0; i < idealHash->Size; ++i) {
        long long hash = Hash(cur->Value, idealHash->a, idealHash->b) % (size);
        if (idealHash->IdealHashTable[hash] != NULL) {
            return 1;
        }
        idealHash->IdealHashTable[hash] = cur;
        cur = cur->Next;
    }
    return 0;
}

void IdealHashTable(struct THash* hashTable) {
    for (int i = 0; i < SIZE_HASHTABLE; ++i) {
        if (hashTable[i].Head == NULL) {
            continue;
        }
        int idealHash = 1;
        srand(time(NULL));

        int size = hashTable[i].Size * hashTable[i].Size;
        hashTable[i].IdealHashTable = (struct THashNode**)malloc(size * sizeof(struct THashNode*));
        while (idealHash == 1) {
            if (size == 1){
                hashTable[i].IdealHashTable[0] = hashTable[i].Head;
                idealHash = 0;
            }
            else {
                hashTable[i].a = rand() % INT_MAX;
                hashTable[i].b = rand() % INT_MAX;
                idealHash = TryToIdealHash(&hashTable[i]);
            }
        }
    }
}

void CheckIsInHashTable(struct THash* hashTable, char* string) {
    int realSizeString = strlen(string) + 1;
    long long hash = Hash(string, 437, 234);
    if (hashTable[hash].Head == NULL) {
        printf("0");
    }
    else {
        if (hashTable[hash].Size == 1) {
            if (hashTable[hash].IdealHashTable[0] == NULL) {
                printf("0");
                return;
            }
            char result = strcmp(hashTable[hash].IdealHashTable[0]->Value, string);
            if (result == 0) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        else {
            long long idealHash = Hash(string, hashTable[hash].a, hashTable[hash].b) % (hashTable[hash].Size * hashTable[hash].Size);
            if (hashTable[hash].IdealHashTable[idealHash] == NULL) {
                printf("0");
                return;
            }
            if (hashTable[hash].IdealHashTable[idealHash]->SizeString != realSizeString) {
                printf("0");
            }
            else {
                char result = strcmp(hashTable[hash].IdealHashTable[idealHash]->Value, string);
                if (result == 0) {
                    printf("1");
                }
                else {
                    printf("0");
                }
            }
        }
        
    }
}

int main(void) {
    int countInBd, countCheckInBd;
    scanf("%d %d", &countInBd, &countCheckInBd);
    struct THash* hashTable = (struct THash*)malloc(sizeof(struct THash) * SIZE_HASHTABLE);
    for (int i = 0; i < SIZE_HASHTABLE; ++i) {
        hashTable[i].Size = 0;
        hashTable[i].IdealHashTable = NULL;
        hashTable[i].Head = NULL;
        hashTable[i].Tail = NULL;
    }
    char string[SIZE_STRING] = { 0 };
    for (int i = 0; i < countInBd; ++i) {
        scanf("%s", &string);
        AddIndexInHashTable(hashTable, string);
    }
    IdealHashTable(hashTable);
    for (int i = 0; i < countCheckInBd; ++i) {
        scanf("%s", &string);
        CheckIsInHashTable(hashTable, string);
    }
    return 0;
}

