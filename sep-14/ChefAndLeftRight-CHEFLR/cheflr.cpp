#include <stdio.h>
using namespace std;

typedef unsigned long long int ULLI;
const ULLI MODNUM = 1000000007;

int main()
{
	int nCases = 0, level = 0;
	ULLI num = 1ULL, unmodded_num = 1ULL, modofunmodnum = 1ULL;
	char c = ' ';
	scanf("%d", &nCases);
	scanf("%c", &c); // read the '\n'
	
	while(nCases--)
	{
		level = 1;
		num   = 1ULL;
		//unmodded_num = 1ULL;
		
		while(scanf("%c", &c) != EOF) {
			if (c == '\n')  {
				printf("%llu\n", num);
				c = ' ';
				break;
			}

			++level;
			
			num = ((num % MODNUM) * 2ULL) % MODNUM;
			//unmodded_num *= 2ULL;
			
			// even level L = 2 * num; R = 2 * num + 2;
			if ((level & 1) == 0) { 
				// (c == 'l') is just 2 * num
				if (c == 'r') {
					num += 2ULL; 
					//unmodded_num += 2; 
				}
			}
			else {
				// odd level: L = 2 * num - 1; R = 2 * num + 1;
				num = (c == 'l') ? ((num - 1ULL)) : ((num + 1ULL));
				//unmodded_num = (c == 'l') ? (unmodded_num - 1ULL) : (unmodded_num + 1ULL);
			}
			
			num %= MODNUM;
			//modofunmodnum = unmodded_num % MODNUM;
			//printf("Debug c=%c num=%llu unmodded_num=%llu modofunmod=%llu\n", c, num, unmodded_num, modofunmodnum);
			
		}
		
		if (c != ' ') {
			printf("%llu\n", num);
		}
	}
	
	return 0;
}
