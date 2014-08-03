// http://www.codechef.com/AUG14/problems/CRAWA
#include <stdio.h>

int main()
{
	int nCases, x = 0, y = 0, diff = 0;

	scanf("%d", &nCases);

	while(nCases--) {
		scanf("%d %d", &x, &y);

		if (y < 0) y = -1 * y;
		if (x < 0) x = -1 * x;
		
		if (y % 2 != 0)
			printf("NO\n");
		else {
			diff = y - x;
			if (diff < 0) diff = -1 * diff; 
			
			if (diff == 1)
				printf("YES\n");
			else if (diff == 0)
				printf("YES\n");
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}
