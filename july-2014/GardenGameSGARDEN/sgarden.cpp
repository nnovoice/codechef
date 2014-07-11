// http://www.codechef.com/JULY14/problems/SGARDEN
#include <stdio.h>
//#include <numeric>

typedef unsigned long long int ULLI;

const int MOD_NUM = 1000000007;
const int MAX_POSITIONS = 100001;

int positions[MAX_POSITIONS];
bool visited[MAX_POSITIONS];
int cycles[MAX_POSITIONS];
//ULLI results[MAX_POSITIONS];

ULLI gcd(ULLI a, ULLI b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

ULLI lcm(ULLI a, ULLI b)
{
	ULLI temp = gcd(a, b);

	ULLI LCM = temp ? (a / temp * b) : 0;
	////printf("Debug: GCD of %llu, %llu is: %llu and LCM is: %llu\n", a, b, temp, LCM);

    return temp ? (a / temp * b) : 0;
}

ULLI GetNumWhistles(int nBandits)
{
	int cycleIndex = 0;
	int cycleLen = 0;
	int j = 0;
	ULLI curLCM = 0;
	for (int i = 1; i <= nBandits; ++i) {
		visited[i] = true;

		cycleLen = 1;

		j = positions[i];
		while (j != i) {
			if (visited[j]) {
				break;
			}
			cycleLen += 1;
			visited[j] = true;
			j = positions[j];
		}
		cycles[cycleIndex++] = cycleLen;
	}

	//ULLI result = std::accumulate(cycles, cycles + cycleIndex, 1, lcm);;
	ULLI result = cycles[0] % MOD_NUM;
	int idx = 0;
	for (int i = 1; i < cycleIndex; ++i) {
		if (cycles[i] != 1) {
			curLCM = lcm(result, cycles[i]) % MOD_NUM;
			//printf("Debug: LCM of %llu %d is %llu\n", result, cycles[i], curLCM);
			result = curLCM;
			//results[idx++] = result;
		}
	}
	result = result % MOD_NUM;

//	for(int i = 0; i < idx; ++i) {
		//printf("D: %llu ", results[i]);
//		if (i > 0 && i < idx && results[i] > results[i+1]) {
//			printf("ERROR...OVERFLOW ");
//		}
//	}
//	printf("Debug: \n");

	return result;
}

int main()
{
	int nCases = 0;
	scanf ("%d", &nCases);
	int nBandits = 0;

	for (int caseNum = 0; caseNum < nCases; ++caseNum) {
		scanf("%d", &nBandits);
		// start index at 1...to be in sync with the problem
		for (int i = 1; i <= nBandits; ++i) {
			scanf("%d", &positions[i]);

			visited[i] = false;
		}

		printf("%llu\n", GetNumWhistles(nBandits));
	}

	return 0;
}
