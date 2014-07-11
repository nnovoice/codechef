// http://www.codechef.com/JULY14/problems/SGARDEN
#include <stdio.h>
#include <numeric>

typedef unsigned long long ULL;

const int MOD_NUM = 1000000007;
const int MAX_POSITIONS = 100001;

int positions[MAX_POSITIONS];
bool visited[MAX_POSITIONS];
int cycles[MAX_POSITIONS];

// TBD: check for overflows
// TBD: test with more inputs
// TBD: test with producing random long permutations

ULL gcd(ULL a, ULL b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

ULL lcm(ULL a, ULL b)
{
	ULL temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

ULL GetNumWhistles(int nBandits)
{
	int cycleIndex = 0;
	int cycleLen = 0;
	int j = 0;
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

	ULL result = std::accumulate(cycles, cycles + cycleIndex, 1, lcm);
	result = result % MOD_NUM;

	//printf("Debug: result= %d", result);

	//printf("Debug:\n");
	//for (int i = 0; i <= cycleIndex; ++i) {
		//printf("D:%d ", cycles[i]);
	//}
	//printf("Debug end.\n");
	return result;
}

int main()
{
	int nCases = 0;
	scanf ("%d", &nCases);
	//printf("Debug cases= %d\n", nCases);
	int nBandits = 0;

	for (int caseNum = 0; caseNum < nCases; ++caseNum) {
		scanf("%d", &nBandits);
		//printf("Debug num bandits= %d", nBandits);

		//printf("Debug bandit positions= ");
		// start index at 1...to be in sync with the problem
		for (int i = 1; i <= nBandits; ++i) {
			scanf("%d", &positions[i]);
			//printf("D: %d ", positions[i]);

			visited[i] = false;
		}

		printf("%llu\n", GetNumWhistles(nBandits));
	}

	return 0;
}
