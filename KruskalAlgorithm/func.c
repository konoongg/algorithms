#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"

int cmp(const void* a, const void* b) {
    return ((struct TEdges*)a)->Weight - ((struct TEdges*)b)->Weight;
}

int Find(int* parent, int index) {
    if (parent[index] == index) {
        return index;
    }
    else {
        return parent[index] = Find(parent, parent[index]);
    }
}

void Union(int* parent, int* rank, int start, int end) {
    int startParent = Find(parent, start);
    int endParent = Find(parent, end);
    if (startParent == endParent) {
        return;
    }
    if (rank[startParent] < rank[endParent]) {
        parent[startParent] = endParent;
    }
    else if (rank[startParent] > rank[endParent]) {
        parent[endParent] = startParent;
    }
    else {
        parent[endParent] = startParent;
        ++rank[startParent];
    }
}
