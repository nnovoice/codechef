#include <stdio.h>
#include <string.h>
//#include <time.h>

typedef unsigned long long int ulli;

const int MAX_N = 100001;
const ulli MOD_NUM = 1000000009;

void ReadPotion(int colour, int num, int* loc)
{
    int val = 0;
    for (int i = 0; i < num; ++i) {
        scanf("%d", &val);
        *loc += val;
    }
}

int main()
{
    char buckets[MAX_N] = {0};
    int nCases = 0, R = 0, G = 0, B = 0, M = 0;
    int r = 0, g = 0, b = 0;
    int max = 0, max_idx = 0;
    int potions[3] = {0};
    int colours[3] = {0};

    scanf("%d", &nCases);
    while(nCases--) {
        scanf("%d %d %d %d", &R, &G, &B, &M);
        printf("Debug: %d %d %d %d\n", R, G, B, M);
        colours[0] = R;
        colours[1] = G;
        colours[2] = B;

        for (int i = 0; i < 3; ++i) {
            potions[i] = 0;
        }
                
        ReadPotion(0, R, &potions[0]);
        printf("Debug: total R=%d\n", potions[0]);
        ReadPotion(0, G, &potions[1]);
        printf("Debug: total G=%d\n", potions[1]);
        ReadPotion(0, B, &potions[2]);
        printf("Debug: total B=%d\n", potions[2]);

        for (int i = 0; i < M; ++i) {
            max = 0, max_idx = 0;
            printf("Debug: BEFORE processing at %d min, we have R=%d G=%d B=%d\n", i, potions[0], potions[1], potions[2]);
            for (int j = 0; j < 3; ++j) {
                if (max < potions[j]) {
                    max = potions[j];
                    max_idx = j;
                }
            }
            printf("Debug: max=%d max_idx=%d\n", max, max_idx);
            potions[max_idx] /= 2;
            for (int j = 0; j < 3; ++j) {
                if (j != max_idx) {
                    potions[j] += colours[j];
                    //potions[j] += 1;
                }
            }
            printf("Debug: AFTER processing at %d min, we have R=%d G=%d B=%d\n", i, potions[0], potions[1], potions[2]);
        }
        max = 0;
        for (int j = 0; j < 3; ++j) {
            if (max < potions[j]) {
                max = potions[j];
                max_idx = j;
            }
        }
        printf("%d\n", max);
    }
    
    return 0;
}
