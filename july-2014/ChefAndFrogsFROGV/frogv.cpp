// http://www.codechef.com/JULY14/problems/FROGV
#include <stdio.h>
#include <algorithm>

const int MAX_POSITIONS = 100001;

int positions[MAX_POSITIONS];
int sortedPositions[MAX_POSITIONS];

int GetIndexFromSortedPositions(int frogIdx, int start, int end)
{
	int pos = positions[frogIdx]; // the actual position as received in the input
	int mid = 0;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (sortedPositions[mid] > pos) {
			end = mid - 1;
		}
		else if (sortedPositions[mid] < pos) {
			start = mid + 1;
		}
		else {
			break;
		}
	}
	return mid;
}

bool CanFrogsCommunicate(int frog1Idx, int frog2Idx, int n, int k)
{
	bool canCommunicate = true;
	int frog1SortedIdx = GetIndexFromSortedPositions(frog1Idx, 1, n);
	int frog2SortedIdx = GetIndexFromSortedPositions(frog2Idx, 1, n);
	for (int i = frog1SortedIdx; i < frog2SortedIdx; ++i) {
		if ((sortedPositions[i + 1] - sortedPositions[i]) > k) {
			canCommunicate = false;
			break;
		}
	}
	return canCommunicate;
}

int main()
{
	int n = 0, k = 0, p = 0;
	int frog1Idx = 0, frog2Idx = 0;
	bool canCommunicate = false;

	scanf("%d %d %d", &n, &k, &p);
	//printf("Debug: %d %d %d\n", n, k, p);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &positions[i]);
		//printf("D:%d ", positions[i]);
		sortedPositions[i] = positions[i];
	}

	// off by one error if we use std::sort(sortedPositions, sortedPositions + n);
	std::sort(sortedPositions, sortedPositions + n + 1);

	for (int i = 0; i < p; ++i) {
		scanf("%d %d", &frog1Idx, &frog2Idx);
		//printf("Debug: %d %d\n", frog1Idx, frog2Idx);
		if (frog2Idx < frog1Idx){
			std::swap(frog1Idx, frog2Idx);
		}
		canCommunicate = CanFrogsCommunicate(frog1Idx, frog2Idx, n, k);
		if (canCommunicate) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}
