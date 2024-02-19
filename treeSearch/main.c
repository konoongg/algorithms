#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

struct Ttree {
    long long Value;
    struct Ttree* Left;
    struct Ttree* Right;
    char IsCheck;
};

void AddTree(struct Ttree* tree, long long value) {
    if (tree->Value == 1000001) {
        tree->Value = value;
        tree->IsCheck = 0;
    }
    else if (tree->Value == value) {
        return;
    }
    else if(tree->Value > value) {
        if (tree->Left == NULL) {
            tree->Left = (struct Ttree*)malloc(sizeof(struct Ttree));
            tree->Left->Left = NULL;
            tree->Left ->Right = NULL;
            tree->Left->Value = 1000001;
        }
        AddTree(tree->Left, value);
    }
    else {
        if (tree->Right == NULL) {
            tree->Right = (struct Ttree*)malloc(sizeof(struct Ttree));
            tree->Right->Left = NULL;
            tree->Right->Right = NULL;
            tree->Right->Value = 1000001;
        }
        AddTree(tree->Right, value);
    }
}

void ChekcTree(struct Ttree* tree, long long value, long long* count) {
    if (tree->Value == value) {
        if (tree->IsCheck == 0) {
            tree->IsCheck = 1;
            (* count)++;
        }
    }
    else if (tree->Value < value) {
        if (tree->Right) {
            ChekcTree(tree->Right, value, count);
        }
    }
    else {
        if (tree->Left) {
            ChekcTree(tree->Left, value, count);
        }
    }
}

int main() {
    long long mashCoun, anotherCoun;
    scanf("%lld %lld", &mashCoun, &anotherCoun);
    struct Ttree tree;
    tree.Left = NULL;
    tree.Right = NULL;
    tree.Value = 1000001;
    tree.IsCheck = 0;
    for (int i = 0; i < mashCoun; ++i) {
        long long value;
        scanf("%lld", &value);
        AddTree(&tree, value);
    }
    long long count = 0;
    for (int i = 0; i < anotherCoun; ++i) {
        long long value;
        scanf("%lld", &value);
        ChekcTree(&tree, value, &count);
    }
    printf("%lld", count);
    return 0;
}