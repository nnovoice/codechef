#include <stdio.h>
#include <string.h>

typedef unsigned long long int ULLI;
const ULLI MODNUM = 1000000007;
const int MAX_LEN = 100010;

int main()
{
	char input[MAX_LEN] = {'\0'};
	int nCases = 0, level = 0, retVal = 0;
	ULLI num = 1ULL; 
	char c = ' ';
	scanf("%d", &nCases);
	scanf("%c", &c); // read the '\n'
	
	while(nCases--)
	{
		memset(input, '\0', sizeof(char) * MAX_LEN);
		level = 1;
		num   = 1ULL;
		
		scanf("%s", input);
		//printf("Debug input %s=", input);

		for (int i = 0; input[i] != '\0'; ++i) {
			c = input[i];

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
		printf("%llu\n", num);
	}
	
	return 0;
}
