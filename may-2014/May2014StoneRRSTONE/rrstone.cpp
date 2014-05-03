#include <stdio.h>
#include <limits.h>

#define MAXNUMBERS 100002
long long int numbersOddIter[MAXNUMBERS];
long long int numbersEvenIter[MAXNUMBERS];
int main()
{
    int n = 0, k = 0;
    long long int maxVal = LONG_LONG_MIN;
    long long int minVal = LONG_LONG_MAX;
    long long int maxValForEvenIter = 0;

    //printf("%lld %lld", LONG_LONG_MAX, LONG_LONG_MIN);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &numbersOddIter[i]);
        numbersEvenIter[i] = numbersOddIter[i];
        if (numbersOddIter[i] > maxVal) maxVal = numbersOddIter[i];
        if (numbersOddIter[i] < minVal) minVal = numbersOddIter[i];
    }

    if (k > 0) {
        maxValForEvenIter = maxVal - minVal;
        for(int i = 0; i < n; ++i) {
            numbersOddIter[i]  = maxVal - numbersOddIter[i];
            numbersEvenIter[i] = maxValForEvenIter - numbersOddIter[i];
        }
    }

    //long long int* pNumbers = 0;
    //((k % 2) == 0) ? pNumbers = &numbersEvenIter[0] : &numbersOddIter[0];
    //printf("0th val=%lld ", pNumbers[0]);
    for (int i = 0; i < n; ++i) {
        if ((k % 2) == 0) printf("%lld ", numbersEvenIter[i]);
        else printf("%lld ", numbersOddIter[i]);
    }
    printf("\n");

    return 0;
}
