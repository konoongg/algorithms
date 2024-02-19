#include <stdlib.h>
#include <stdio.h>
#include "func.h"

void* MyMalloc(struct TMemory* memory, int size) {
    void* mem = memory->Memory + memory->start;
    memory->start += size;
    return mem;
}

struct TAVLTree* AddValue(struct TAVLTree* tree, struct TMemory* memory, long long value) {
    if (!tree) {
        return MakeNode(memory, value);
    }
    if (value <= tree->Value) {
        tree->Left = AddValue(tree->Left, memory, value);
    }
    else {
        tree->Right = AddValue(tree->Right, memory, value);
    }
    return Balance(tree);
}

struct TAVLTree* Balance(struct TAVLTree* tree) {
    if (!tree) {
        return NULL;
    }
    int difference = Difference(tree);
    if (difference <= -2) {
        if (Difference(tree->Right) > 0) {
            tree = LeftBigRotate(tree);
        }
        else {
            tree = LeftSmallRotate(tree);
        }
    }
    else if (difference >= 2) {
        if (Difference(tree->Left) < 0) {
            tree = RightBigRotate(tree);
        }
        else {
            tree = RightSmallRotate(tree);
        }
    }
    tree->Height = tree ? Max(GetHeight(tree->Left), GetHeight(tree->Right)) + 1 : 0;
    return tree;
}

int Difference(struct TAVLTree* tree) {
    if (!tree) {
        return 0;
    }
    return GetHeight(tree->Left) - GetHeight(tree->Right);
}

int GetHeight(struct TAVLTree* tree) {
    return tree ? tree->Height : 0;
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}

struct TAVLTree* LeftSmallRotate(struct TAVLTree* tree) {
    if (tree) {
        struct TAVLTree* a = tree;
        struct TAVLTree* b = tree->Right;
        if (b == NULL) {
            return tree;
        }
        a->Right = b->Left;
        b->Left = a;
        a->Height = Max(GetHeight(a->Left), GetHeight(a->Right)) + 1;
        b->Height = Max(GetHeight(b->Left), GetHeight(b->Right)) + 1;
        tree = b;
    }
    return tree;
}

struct TAVLTree* RightSmallRotate(struct TAVLTree* tree) {
    if (tree) {
        struct TAVLTree* b = tree;
        struct TAVLTree* a = b->Left;
        if (a == NULL) {
            return tree;
        }
        b->Left = a->Right;
        a->Right = b;
        b->Height = Max(GetHeight(b->Right), GetHeight(b->Left)) + 1;
        a->Height = Max(GetHeight(a->Right), GetHeight(a->Left)) + 1;
        tree = a;
    }
    return tree;
}

struct TAVLTree* RightBigRotate(struct TAVLTree* tree) {
    if (!tree) {
        return NULL;
    }
    struct TAVLTree* a = tree;
    struct TAVLTree* b = a->Left;
    if (!b) {
        return NULL;
    }
    struct TAVLTree* c = b->Right;
    a->Left = c->Right;
    c->Right = a;
    b->Right = c->Left;
    c->Left = b;
    b->Height = Max(GetHeight(b->Right), GetHeight(b->Left)) + 1;
    a->Height = Max(GetHeight(a->Right), GetHeight(a->Left)) + 1;
    c->Height = Max(GetHeight(c->Right), GetHeight(c->Left)) + 1;
    return c;

}


struct TAVLTree* LeftBigRotate(struct TAVLTree* tree) {
    if (tree) {
        tree->Right = RightSmallRotate(tree->Right);
        return LeftSmallRotate(tree);
    }
    else {
        return NULL;
    }
}

struct TAVLTree* MakeNode(struct TMemory* memory, long long value) {
    struct TAVLTree* tree = MyMalloc(memory, 1);
    tree->Value = value;
    tree->Left = NULL;
    tree->Right = NULL;
    tree->Height = 1;
    return tree;
}

