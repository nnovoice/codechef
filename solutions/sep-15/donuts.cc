// Chain of Donuts
// https://www.codechef.com/SEPT15/problems/DONUTS

#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX = 20000 + 7;
int A[MAX];

int main()
{
    int T = 0;
    int cuts = 0;
    int N = 0, M = 0;

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &M);
        
        for (int i = 0; i < M; ++i) 
            scanf("%d", &A[i]);

        sort(A, A + M);
        
        int i = 0;
        int j = M - 1;
        cuts = 0;
        
        while (i < j) {
            if (A[i] != 0) {
                --A[i];
                ++cuts;
                
                A[j-1] += A[j];
                A[j-1] += 1;
                --j;

            }
            else
                ++i;

        }

        printf("%d\n", cuts);

    }
    return 0;
}
