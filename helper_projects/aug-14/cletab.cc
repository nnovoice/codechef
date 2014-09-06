#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_ORDERS = 401;
const int MAX_PEOPLE = 201;
int main()
{
	srand(time(NULL));
	printf("%d\n", 1);
	printf("%d %d\n", 200, 400);
	for (int i = 1; i < MAX_ORDERS; ++i) {
		printf("%d ", (rand() % 400) + 1);
	}
	return 0;
}