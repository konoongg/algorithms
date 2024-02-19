#include <stdio.h>
#include <stdlib.h>
int main() {
    size_t n = 0, m = 0, s = 0;
    int n2[64], m2[64];
    scanf("%llu%llu", &n, &m);
    size_t countN = 0, countM = 0;

    while ((size_t)n / 2 > 0) {
        n2[countN] = n % 2;
        ++countN;
        n = (size_t)n / 2;
    }

    n2[countN] = n % 2;
    ++countN;

    while ((size_t)m / 2 > 0) {
        m2[countM] = m % 2;
        ++countM;
        m = (size_t)m / 2;
    }
    m2[countM] = m % 2;
    ++countM;
    if (countM != countN) {
        printf("0");
    
        return 0;
    
    }
    else {
        int k = 0, f = 1;
        //printf("%d \n",countN);
        for (int i = 0; i < countN; ++i) {
            if (m2[countN - 1 - i] == n2[countN - 1 - i] && f == 1) {
                //printf("%d");
                s |= (m2[countN - 1 - i] & n2[countN - 1 - i]);
                if (i != countN - 1) {
                	k++;
                    s <<= 1;
                }
            }
            else {
                break;

            }
        
        }
        s <<= (countN - 1-k);
                
        printf("%llu", s);
        return 0;
    }
}

