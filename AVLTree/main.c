#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "func.h"

int main() {
    long long countNum = 0;
    if (scanf("%lld", &countNum) == -1) {
        return 0;
    }
    if (countNum == 0) {
        printf("0");
        return 0;
    }
    struct TMemory memory;
    memory.start = 0;
    memory.Size = (countNum + 3 ) * sizeof(struct TAVLTree);
    memory.Memory = calloc(countNum + 3, sizeof(struct TAVLTree));
    struct TAVLTree* tree = NULL;
    long long num = 0;
    for (long long i = 0; i < countNum; ++i) {
        if (scanf("%lld", &num) == 0) {
            free(memory.Memory);
            return 0;
        }
        tree = AddValue(tree, &memory, num);
    }
    printf("%d", tree->Height);
    free(memory.Memory);
    return 0;
}

