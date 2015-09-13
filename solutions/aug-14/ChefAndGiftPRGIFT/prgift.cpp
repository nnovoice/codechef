// http://www.codechef.com/AUG14/problems/PRGIFT
#include <stdio.h>

int main()
{
	int nCases, n = 0, k = 0, num = 0, nEvenNumbers = 0;

	scanf("%d", &nCases);

	while(nCases--) {
		scanf("%d %d", &n, &k);
		
		nEvenNumbers = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &num);
			if (num % 2 == 0)
				nEvenNumbers += 1;
		}
		if (k == 0) {
			if (nEvenNumbers == n)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else {
			if (nEvenNumbers >= k) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}
