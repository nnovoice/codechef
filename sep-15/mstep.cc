// count steps in a matrix
// https://www.codechef.com/SEPT15/problems/MSTEP

#include <stdio.h>
int main()
{
    int T = 0;
    int N= 0, NSquare = 0;
    int r[501], c[501], v = 0;
    long long int steps = 0;
    int rdiff = 0, cdiff = 0;

    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                scanf("%d", &v);
                r[v] = i;
                c[v] = j;
            }
        }

        NSquare = N * N;
        steps = 0;
        
        for (int i = 2; i <= NSquare; ++i) {
            rdiff = r[i-1] - r[i];
            cdiff = c[i-1] - c[i];
            if (rdiff < 0) 
                rdiff = 0 - rdiff;
            if (cdiff < 0)
                cdiff = 0 - cdiff;
            steps += rdiff;
            steps += cdiff;
        }
        
        printf("%lld\n", steps);

    }
    return 0;
}
