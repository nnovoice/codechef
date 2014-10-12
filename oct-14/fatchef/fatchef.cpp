#include <stdio.h>
#include <string.h>
#include <time.h>

typedef unsigned long long int ulli;

const int MAX_N = 100001;
const ulli MOD_NUM = 1000000009;

int main()
{
    char buckets[MAX_N] = {0};
    int nCases = 0, N = 0, M = 0, location = 0;
    ulli combinations = 0;
    char colour = ' ', temp = ' ';
    int prev_i = 0, cur_i = 0;
    char prev_c = ' ', cur_c = ' ';
    scanf("%d", &nCases);
    clock_t t = clock();
    while(nCases--) {
        combinations = 1;
        memset(buckets, '\0', sizeof(buckets[0]) * MAX_N);
        scanf("%d %d", &N, &M);
        
        scanf("%c", &temp); // have to read this char
        //printf("Debug: N=%d M=%d\n", N, M);
                
        for (int i = 1; i <= M; ++i) {
            scanf("%c %d", &colour, &location);
            //printf("Debug: %c,%d\n", colour, location);
            buckets[location] = colour;
            scanf("%c", &temp); // have to read this char
        }

        if (M == 1) {
            printf("%llu\n", combinations);
            continue;
        }
        
        prev_i = 1;
        prev_c = ' ';

        for (int i = 1; i <= N; ++i) {
            //prullif("%c %d", buckets[i], i);
            if (buckets[i] >= 'A' && buckets[i] <= 'Z') {
                //printf("Debug: %c %d\n", buckets[i], i);
                cur_i = i;
                cur_c = buckets[i];

                if (cur_c != prev_c && cur_i != prev_i) {
                    combinations *= (cur_i - prev_i);
                    combinations %= MOD_NUM;
                }
                prev_i = cur_i;
                prev_c = cur_c;
            }
        }
        printf("%d\n", combinations);
    }
    t = clock() - t;

    //printf("Debug: It took %d clicks and %fs\n", t, ((float)t)/CLOCKS_PER_SEC);
    return 0;
}
