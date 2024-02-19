#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

struct Ttree {
    int Value;
    struct Ttree* Left;
    struct Ttree* Right;
};

struct Ttree* BildTree(struct Ttree* tree, int value) {
    if (!tree) {
        tree = calloc(1, sizeof(struct Ttree));
        tree->Value = value;
    }
    else {
        if (value < tree->Value) {
            tree->Left = BildTree(tree->Left, value);
        }
        else if (value >= tree->Value) {
            tree->Right = BildTree(tree->Right, value);
        }
    }
    return tree;
}

void PostOrder(struct Ttree* tree) {
    if (!tree) {
        return;
    }
    if (tree->Left) {
        PostOrder(tree->Left);
    }
    if (tree->Right) {
        PostOrder(tree->Right);
    }
    printf("%d ", tree->Value);
}

void InOrder(struct Ttree* tree) {
    if (!tree) {
        return;
    }
    if (tree->Left) {
        InOrder(tree->Left);
    }
    printf("%d ", tree->Value);
    if (tree->Right) {
        InOrder(tree->Right);
    }
}

int main() {
    int countNum = 0;
    scanf("%d", &countNum);
    struct Ttree* tree = NULL;
    long long num;
    for (unsigned long i = 0; i < countNum; ++i) {
        scanf("%d", &num);
        tree = BildTree(tree, num);
    }
    PostOrder(tree);
    printf("\n");
    InOrder(tree);
    return 0;
}