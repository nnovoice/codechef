#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX_NUMBERS = 100001;
typedef unsigned long long int ULLI;

int stones[MAX_NUMBERS];
int main()
{
	ULLI total = 0;
	int nCases = 0, n = 0;
	scanf("%d", &nCases);
	while (nCases--) {
		memset(stones, 0, sizeof(int) * MAX_NUMBERS);
		total = 0LLU;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &stones[i]);
		}
		sort(stones, stones + n);
		for (int i = n - 1; i >= 0; i -= 2) {
			total += stones[i];
		}
		printf("%llu\n", total);
	}
	return 0;
}