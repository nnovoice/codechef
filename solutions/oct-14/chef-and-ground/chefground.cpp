#include <stdio.h>
#include <string.h>

const unsigned int MAX_N = 1001;

int main()
{
    unsigned int heights[MAX_N] = {0};
    unsigned int nCases = 0, N = 0, M = 0, total_diff = 0, max_height = 0;
    scanf("%u", &nCases);
    while(nCases--) {
        memset(heights, 0, sizeof(heights[0]) * MAX_N);
        total_diff = 0;
        max_height = 0;
        scanf("%u %u", &N, &M);
        //printf("Debug N=%d M=%d\n", N, M);
        for (int i = 0; i < N; ++i) {
            scanf("%u", &heights[i]);
            //printf("Debug: %d,%d\n", i, heights[i]);
            if (heights[i] > max_height)
                max_height = heights[i];
        }
        //printf("Debug: \n");
        for (int i = 0; i < N; ++i)
            total_diff += (max_height - heights[i]);
        //printf("Debug: max=%d M=%d tot_diff=%d\n", max_height, M, total_diff);
        
        if (total_diff == M)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
