// http://www.codechef.com/AUG14/problems/CRAWA
#include <stdio.h>

int main()
{
	int nCases = 0, x = 0, y = 0, diff = 0;

	scanf("%d", &nCases);

	while(nCases--) {
		scanf("%d %d", &x, &y);

		if (x >= 0) {
			if (x % 2 == 0) {
				if (y > 0) {
					if (y % 2 == 0 && y > x)
						printf ("YES\n");
					else
						printf ("NO\n");
				}
				else { 
					y *= -1;
					if (y % 2 == 0 && y >= x)
						printf("YES\n");
					else
						printf ("NO\n");
				}
			}
			else {
				if (y >= 0) {
					if (y >= 0 && y <= (x - 1))
						printf("YES\n");
					else if (y > (x + 1) && ((y % 2) == 0))
						printf ("YES\n");
					else
						printf("NO\n");
				}
				else {
					y *= -1;
					if (y > x && ((y % 2) == 0))
						printf("YES\n");
					else if (y <= (x - 1))
						printf("YES\n");
					else
						printf("NO\n");
				}
			}
		}
		else { // x < 0 
			x *= -1;
			if (x % 2 == 0) {
				if (y > 0 && y <= x)
					printf("YES\n");
				else if (y > (x + 1) && ((y % 2) == 0))
					printf ("YES\n");
				else
					printf("NO\n");
			}
			else {
				if (y == 0) 
					printf ("NO\n");
				else {
					if (y < 0) y *= -1;
					if (y > x && ((y % 2) == 0))
						printf ("YES\n");
					else
						printf("NO\n");
				}
			}
		}
	}

	return 0;
}

