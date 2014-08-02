// http://www.codechef.com/AUG14/problems/PRGIFT
#include <stdio.h>

const int MAX_NUMBERS = 51;

int numbers[MAX_NUMBERS];

int main()
{
	int nCases, n = 0, k = 0, nEvenNumbers = 0;

	scanf("%d", &nCases);

	while(nCases--) {
		scanf("%d %d", &n, &k);
		
		for (int i = 0; i < n; ++i) {
			scanf("%d", &numbers[i]);
		}
		
		nEvenNumbers = 0;
		for (int i = 0; i <= (n - k); ++i) {
			nEvenNumbers = 0;
			for (int j = i; j < (i + k); ++j) {
				if (numbers[j] % 2 == 0)
					nEvenNumbers += 1;
			}
			if (nEvenNumbers == k) {
				break;
			}
		}
		
		if (nEvenNumbers == k) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
