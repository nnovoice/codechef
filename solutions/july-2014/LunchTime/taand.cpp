#include <stdio.h>

const unsigned int MAX_NUMS = 300000; 

typedef unsigned int UI;
UI numbers[MAX_NUMS];

UI ComputeMax(int N)
{
	UI maxVal = 0, curVal = 0;
	for (int i = 0; i < (N - 1); ++i) {
		for (int j = i + 1; j < N; ++j) {
			curVal = numbers[i] & numbers[j];
			if (curVal > maxVal) maxVal = curVal;
		}
	}
	return maxVal;
}


int main()
{
	UI N = 0;
	
	scanf ("%u", &N);
	for (int i = 0; i <= N; ++i) {
		scanf ("%u", &numbers[i]);
	}
	
	printf ("%u\n", ComputeMax(N));
	
	return 0;
}