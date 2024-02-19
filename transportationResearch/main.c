#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>


int Find(int* parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = Find(parent, parent[x]);
    }
}

void Union(int* parent, int x, int y) {
    int parentX = Find(parent, x);
    int parentY = Find(parent, y);
    parent[parentY] = parentX;
}

int main() {
    int sizeMap, countPath;
    scanf("%d %d\n", &sizeMap, &countPath);
    int* parent = (int*)malloc(sizeMap * sizeMap * sizeof(int));
    char* map = (char*)malloc(sizeMap * sizeMap * sizeof(char));
    for (int i = 0; i < sizeMap * sizeMap; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < sizeMap; ++i) {
        for (int j = 0; j < sizeMap; ++j) {
            char c = getchar();
            map[sizeMap * i + j] = c;
            if (i > 0 && map[sizeMap * i + j] == map[sizeMap * (i - 1) + j]) {
                Union(parent, sizeMap * i + j, sizeMap * (i - 1) + j);
            }
            if (j != 0 && map[sizeMap * i + j] == map[sizeMap * i + (j - 1)]) {
                Union( parent, sizeMap * i + j, sizeMap * i + (j - 1));
            }
            
        }
        getchar();
    }
    int startY, startX, finishY, finishX;
    for (int i = 0; i < countPath; ++i) {
        scanf("%d %d %d %d", &startY, &startX, &finishY, &finishX);
        if (Find(parent, parent[startY * sizeMap + startX]) == Find(parent, parent[finishY * sizeMap + finishX])) {
            printf("yep\n");
        }
        else {
            printf("nope\n");
        }
    }
    return 0;
}