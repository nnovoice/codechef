#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>

const int MAX_N = 101;

int main()
{
    srand(time(NULL));
    printf("%d\n", 1);
    //printf("%d %d\n", 100, (rand() % 10000) + 1);
    printf("%d %d\n", 100, 10000);
    for(int i = 1; i <= 100; ++i)
        //printf("%d ", (rand()%100) + 1);
        printf("%d ", i);
    return 0;
}
