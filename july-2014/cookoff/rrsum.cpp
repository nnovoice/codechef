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
	//printf("D:%u %u\n", n, m);

	twice_n = 2 * n;
	unsigned int num_start = n + 2;
	unsigned int num_end = 3 * n;


	for(int i = 0; i < m; ++i) {
		scanf ("%u", &num_for_query);
		//printf("D:%u\n", num_for_query);

		count = 0;

		if (num_for_query < num_start || num_for_query > num_end) {
			printf("%u\n", count);
		}
		else {
			if (num_for_query >= num_start && num_for_query <= (twice_n + 1)) {
				count = num_for_query - (n + 1);
			}
			else {
				count = n - (num_for_query - (twice_n + 1));
			}

			printf("%u\n", count);
		}


	}
	return 0;
}
