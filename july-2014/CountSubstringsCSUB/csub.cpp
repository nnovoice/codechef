#include <stdio.h>
//#include <iostream>
//#include <limits>
//using namespace std;

typedef unsigned long long ULL;

int main()
{
//	cout << UINT_MAX << " " << ULONG_MAX << endl;
	int nCases = 0;
	int strLen = 0;
	int nOnes = 0;
	ULL nSubstrings = 0;
	
	scanf ("%d", &nCases);
//	printf ("%d\n", nCases);
	
	char c = ' ';
	while (nCases--) {
		scanf("%d%c", &strLen, &c);
//		printf ("%d\n", strLen);
		nOnes = 0;
		for (int i = 0; i < strLen; ++i) {
			scanf("%c", &c);
			//printf ("%c", c);
			if (c == '1') ++nOnes;
		}
		nSubstrings = nOnes;
		nSubstrings *= (nOnes + 1);
		nSubstrings >>= 1;
		//printf("out=");
		printf("%llu\n", nSubstrings);
		scanf("%c", &c); // to read the '\n'
	}
	return 0;
}
