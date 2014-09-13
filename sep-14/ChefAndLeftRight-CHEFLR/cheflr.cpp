#include <stdio.h>

typedef unsigned long long int ULLI;
const ULLI MODNUM = 1000000007;

int main()
{
	int nCases = 0, level = 0, retVal = 0;
	ULLI num = 1ULL; 
	char c = ' ';
	scanf("%d", &nCases);
	scanf("%c", &c); // read the '\n'
	
	while(nCases--)
	{
		level = 1;
		num   = 1ULL;
		
		while(1) {
			retVal = scanf("%c", &c);
			if (c == '\n' || retVal == EOF) {
				printf("%llu\n", num);
				break;
			}

			++level;
			
			num = ((num % MODNUM) * 2ULL) % MODNUM;
			
			// even level L = 2 * num; R = 2 * num + 2;
			if ((level & 1) == 0) { 
				// (c == 'l') is just 2 * num
				if (c == 'r') {
					num += 2ULL; 
				}
			}
			else {
				// odd level: L = 2 * num - 1; R = 2 * num + 1;
				num = (c == 'l') ? ((num - 1ULL)) : ((num + 1ULL));
			}
			
			num %= MODNUM;
		}
		
	}
	
	return 0;
}
