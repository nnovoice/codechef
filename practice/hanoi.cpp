#include <stdio.h>

const int MAX = 64;
int A[MAX];
int aTop;

int B[MAX];
int bTop;

int C[MAX];
int cTop;

int totalMoves;

int MoveDisk(int n, 
	int* src, int* srcTop, char srcID,
	int* tgt, int* tgtTop, char tgtID,
	int* temp, int* tempTop, char tempID)
{
	++totalMoves;
	tgt[*tgtTop] = src[*srcTop - 1];
	*srcTop -=1;
	*tgtTop += 1;
	printf("Moved disk=%d from %c to %c srcTop=%d targetTop=%d\n", src[*srcTop], srcID, tgtID, *srcTop, *tgtTop);
	return 0;	
}

int hanoi(int n, 
	int* src, int* srcTop, char srcID,
	int* tgt, int* tgtTop, char tgtID,
	int* temp, int* tempTop, char tempID)
{
	printf ("Debug: hanoi called with n=%d, src=%c, srcTop=%d, tgt=%c, tgtTop=%d, temp=%c, tempTop=%d\n", n, 
		srcID, *srcTop, tgtID, *tgtTop, tempID, *tempTop);

	if (n == 1) {
		MoveDisk(n, src, srcTop, srcID, tgt, tgtTop, tgtID, temp, tempTop, tempID);
		return 0;
	}
	else if ((*srcTop - 1) == 1) { // just one disk left to move
		if (tgt[*tgtTop - 1] > src[*srcTop - 1]) {
			MoveDisk(src[*srcTop - 1], src, srcTop, srcID, tgt, tgtTop, tgtID, temp, tempTop, tempID);
		}
		else {
			if (temp[*tempTop - 1] > src[*srcTop - 1]) {
				MoveDisk(src[*srcTop - 1], src, srcTop, srcID, temp, tempTop, tempID, tgt, tgtTop, tgtID);
			}
		}
	}

	hanoi(n - 1, src, srcTop, srcID, temp, tempTop, tempID, tgt, tgtTop, tgtID);

	MoveDisk(n, src, srcTop, srcID, tgt, tgtTop, tgtID, temp, tempTop, tempID);
	
	hanoi(n - 1, temp, tempTop, tempID, tgt, tgtTop, tgtID, src, srcTop, srcID);
}

int hanoi_driver(int n)
{
	for (int i = n; i > 0; --i) {
		A[aTop++] = i;
	}

	return hanoi(n, A, &aTop, 'A', C, &cTop, 'C', B, &bTop, 'B');
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	hanoi_driver(n);
	printf("Total moves required was=%d\n", totalMoves);
	return 0;
}