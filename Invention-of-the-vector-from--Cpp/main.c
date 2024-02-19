#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int** ms = (int**)malloc(n * sizeof(int*));
    int* len = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        ms[i] = NULL;
        len[i] = 0;
    }
    getchar();
    for (int i = 0; i < m; ++i) {
        getchar();
        char c = getchar();
        if (c == 'u') {
            getchar();
            getchar();
            getchar();
            int v, u;
            scanf("%d%d",&v,&u);
            //printf("%d %d \n", v, u);
            getchar();
            ++len[v];
            ms[v] = (int*)realloc(ms[v], sizeof(int) * len[v]);
            ms[v][len[v] - 1] = u;
        }
        else if (c == 'o') {
            getchar();
            getchar();
            int v;
            scanf("%d", &v);
            //printf("%d \n",v);
            getchar();
            --len[v];
            ms[v] = (int*)realloc(ms[v], len[v] * sizeof(int));
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len[i]; ++j) {
            printf("%d ", ms[i][j]);
        }
        printf("\n");

    }
    return 0;
}