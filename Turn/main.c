#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m, g = 0;
    scanf("%d%d", &n, &m);
    scanf("%d", &g);
    int** ms = (int**)malloc(n * sizeof(int*));
    ms[0] = (int*)malloc(m * sizeof(int));
    int c = 0, j2 = 0, i2 = 0;
    getchar();
    int sumSim = 0;
    while (c < n * m) {
        char sim = getchar();
        if (sim >= 48 && sim <= 57) {
            sumSim *= 10;
            sumSim += (int)sim - 48;
        }
        else {
            ms[i2][j2] = sumSim;
            ++c;
            //printf("%d %d %d %d\n", sumSim, c, ms[i2][j2]);
            ++j2;
            if (j2 % m == 0) {
                ++i2;
                ms[i2] = (int*)malloc(m * sizeof(int));
                j2 = 0;
            }
             sumSim = 0;
        }
        //printf("%d %d %d %c\n", sumSim, c, sim);
    }
    
    if (g == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", ms[i][j]);
            }
            printf("\n");
        }
    }
    else if (g == 180) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", ms[n-i-1][m - j - 1]);
            }
            printf("\n");
        }
    }
    else if (g == 270) {
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                printf("%d ", ms[i][m - j - 1]);
            }
            printf("\n");
        }
    }
    else {
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                printf("%d ", ms[n - i - 1][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
