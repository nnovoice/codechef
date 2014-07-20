#include <stdio.h>
#include <map>
using namespace std;
map<int, int> numbersMap;

int main()
{
	int nCases = 0;
	int num = 0;
	int n = 0;
	unsigned int total_numbers = 0;
	
	scanf ("%d", &nCases);
	//printf("D: %d\n", nCases);

	for(int i = 0; i < nCases; ++i) {
		numbersMap.clear();
		
		scanf ("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf ("%d", &n);
			numbersMap[n] += 1;
		}
		
		total_numbers = (unsigned int) numbersMap.size();
		printf("%u\n", total_numbers);
	}
	return 0;
}