#include <stdio.h>
#include <map>
using namespace std;

map<unsigned int, unsigned int> totalMap;

int main()
{
	unsigned int num_for_query = 0;
	unsigned int n = 0, m = 0;
	unsigned int count = 0;
	unsigned int twice_n = 0;

	scanf ("%u %u", &n, &m);

	twice_n = 2 * n;

	for (unsigned int i = 1; i <= n; ++i){
		for (unsigned int j = (n  + 1); j <= twice_n; ++j) {
			totalMap[i + j] += 1;
		}
	}

	for(int i = 0; i < m; ++i) {
		scanf ("%u", &num_for_query);

		count = totalMap[num_for_query];

		printf("%u\n", count);
	}
	return 0;
}
