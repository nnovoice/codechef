// http://www.codechef.com/JULY14/problems/FROGV
#include <stdio.h>
#include <algorithm>

const int MAX_POSITIONS = 100001;

int positions[MAX_POSITIONS];
int sortedPositions[MAX_POSITIONS];
int diffs[MAX_POSITIONS];
int communications[MAX_POSITIONS];

int GetIndexFromSortedPositions(int frogIdx, int start, int end)
{
	int pos = positions[frogIdx]; // the actual position as received in the input
	//printf("Debug: frogIdx= %d and frogPos= %d\n", frogIdx, pos);
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

bool IsChannelOpen(int startIdx, int endIdx)
{
	if (endIdx - startIdx <= 1) {
		return (communications[endIdx - startIdx] == 0) ? true : false;
	}

	int mid = startIdx + (endIdx - startIdx) / 2;

	if (IsChannelOpen (startIdx, mid) == false) return false;

	return IsChannelOpen (mid, endIdx);
}

bool CanFrogsCommunicate(int frog1Idx, int frog2Idx, int n, int k)
{
	bool canCommunicate = false;
	int frog1SortedIdx = GetIndexFromSortedPositions(frog1Idx, 1, n);
	int frog2SortedIdx = GetIndexFromSortedPositions(frog2Idx, 1, n);
	//printf("Debug: frog1SortedIdx= %d and frog2SortedIdx= %d\n", frog1SortedIdx, frog2SortedIdx);
	if (frog1SortedIdx == frog2SortedIdx) {
	    return true;
	}
	if (frog1SortedIdx > frog2SortedIdx) {
	    std::swap(frog1SortedIdx, frog2SortedIdx);
	}

	//printf("Debug: After swap, frog1SortedIdx= %d and frog2SortedIdx= %d\n", frog1SortedIdx, frog2SortedIdx);

	// We are comparing data at i+1 with data at i, so, i < frog2SortedIdx; is the correct invariant below.
//	canCommunicate = true;
//	for (int i = frog1SortedIdx; i < frog2SortedIdx; ++i) {
//		//printf("Debug: k= %d pos(i+1)= %d and pos(i)= %d diff= %d\n", k, sortedPositions[i + 1], sortedPositions[i], diffs[i]);
//		if (diffs[i] > k) {
//			return false;
//		}
//	}
//	return canCommunicate;
	return IsChannelOpen(frog1SortedIdx, frog2SortedIdx);
}
a
int main()
{
	int n = 0, k = 0, p = 0;
	int frog1Idx = 0, frog2Idx = 0;
	bool canCommunicate = false;

	scanf("%d %d %d", &n, &k, &p);
	//printf("Debug: %d %d %d\n", n, k, p);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &positions[i]);
		//printf("D:(%d,%d) ", i, positions[i]);
		sortedPositions[i] = positions[i];
	}

	// off by one error if we use std::sort(sortedPositions, sortedPositions + n);
	std::sort(sortedPositions, sortedPositions + n + 1);

	for (int i = 1; i < n; ++i) {
		diffs[i] = sortedPositions[i + 1] - sortedPositions[i];
		//printf("D:(%d) ", diffs[i]);
		if (diffs[i] > k) {
			communications[i] = 1; // 1 means blocked, 0 (by default) means open :-)
		}
	}

	for (int i = 0; i < p; ++i) {
		if (scanf("%d %d", &frog1Idx, &frog2Idx) == -1)
		  break;

		//printf("Debug: Actual input= %d %d\n", frog1Idx, frog2Idx);

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
