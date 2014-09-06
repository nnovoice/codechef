#include <stdio.h>

typedef unsigned long long int ULLI;
const ULLI MODNUM = 1000000007;

int main()
{
	int nCases = 0, level = 1;
	ULLI num = 1, temp = 1;
	char c = ' ';
	scanf("%d", &nCases);
	scanf("%c", &c); // read the '\n'
	
	while(nCases--)
	{
		level = 1;
		num   = 1;
		
		while(scanf("%c", &c) != EOF) {
			if (c == '\n') break;
			temp = num * 2;
			num = (temp < MODNUM) ? temp : (temp % MODNUM); 
			
			// odd level? L = 2 * num; R = 2 * num + 2;
			if ((level & 1) != 0) { 
				// (c == 'l') is just 2 * num
				if (c == 'r')
					num = (num + 2) % MODNUM; 
			}
			else {
				// even level: L = 2 * num - 1; R = 2 * num + 1;
				num = (c == 'l') ? ((num - 1) % MODNUM) : ((num + 1) % MODNUM);
			}
			//printf("Debug c=%c temp=%llu num=%llu\n", c, temp, num);
			
			++level;
		}
		printf("%llu\n", num);
	}
	
	return 0;
}