#include <stdio.h>

typedef unsigned long long ULL;

int main()
{
	int nCases = 0;
	int strLen = 0;
	int nOnes = 0;
	ULL nSubstrings = 0;
	
	scanf ("%d", &nCases);
	
	char c = ' ';
	while (nCases--) {
		scanf("%d%c", &strLen, &c);
		nOnes = 0;
		for (int i = 0; i < strLen; ++i) {
			scanf("%c", &c);
			if (c == '1') ++nOnes;
		}
		nSubstrings = nOnes;
		nSubstrings *= (nOnes + 1);
		nSubstrings >>= 1;
		printf("%llu\n", nSubstrings);
		scanf("%c", &c); // to read the '\n'
	}
	return 0;
}
