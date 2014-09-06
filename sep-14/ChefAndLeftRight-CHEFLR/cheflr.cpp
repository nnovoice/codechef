#include <stdio.h>

typedef unsigned long long int ULLI;
const ULLI MODNUM = 1000000007;

int main()
{
	int nCases = 0;
	int level = 1;
	ULLI num = 1, temp = 1;
	int c = ' ';
	scanf("%d", &nCases);
	scanf("%c", &c); // read the '\n'
	
	while(nCases--)
	{
		level = 1;
		num   = 1;
		
		while(scanf("%c", &c) != EOF) {
			if (c == '\n') break;
			temp = 2 * num;
			num = (temp < MODNUM) ? temp : (temp % MODNUM); 
			
			// odd level? L = 2 * num; R = 2 * num + 2;
			if ((level & 1) != 0) { 
				// (c == 'l') is just 2 * num
				if (c == 'r')
					num = (num + 2) % MODNUM; 
			}
			else {
				// even level: L = 2 * num - 1; R = 2 * num + 1;
				if (c == 'l')
					num = (num - 1) % MODNUM;
				else
					num = (num + 1) % MODNUM;
			}
			++level;
			//printf("Debug c=%c num=%llu ", c, num);
		}
		printf("%llu\n", num);
	}
	
	return 0;
}