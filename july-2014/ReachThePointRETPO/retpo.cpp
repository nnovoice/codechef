// http://www.codechef.com/JULY14/problems/RETPO
#include <stdio.h>

int main()
{
	int nCases = 0;
	int x = 0, y = 0;
	int nSteps = 0;

	scanf("%d", &nCases);
	for (int caseNum = 0; caseNum < nCases; ++caseNum) {
		scanf("%d %d", &x, &y);

		x = (x < 0) ? (0 - x) : x;
		y = (y < 0) ? (0 - y) : y;

		if (x > y) {
			nSteps = x + x;
			if (((x + y) % 2) != 0) {
				nSteps += 1;
			}

		}
		else {
			nSteps = y + y;
			if (((x + y) % 2) != 0) {
				nSteps -= 1;
			}
		}

		printf("%d\n", nSteps);
	}

	return 0;
}
