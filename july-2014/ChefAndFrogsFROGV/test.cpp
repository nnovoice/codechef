// http://www.codechef.com/JULY14/problems/FROGV
#include <stdio.h>
#include <algorithm>

const int MAX_POSITIONS = 100001;

int positions[MAX_POSITIONS];
int sortedPositions[MAX_POSITIONS];

int main()
{
	int n = 0, k = 0, p = 0;
	int frog1Idx = 0, frog2Idx = 0;
	bool canCommunicate = false;

	//scanf("%d %d %d", &n, &k, &p);
	//printf("Debug: %d %d %d\n", n, k, p);

//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &positions[i]);
//		//printf("D:%d ", positions[i]);
//		sortedPositions[i] = positions[i];
//	}

	n = 100000;

	sortedPositions[100000] = -1;
	std::sort(sortedPositions, sortedPositions + n + 1);
	printf("Debug: 0=%d 100000=%d\n", sortedPositions[0], sortedPositions[100000]);


	return 0;
}
