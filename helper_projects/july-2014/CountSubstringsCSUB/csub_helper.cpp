#include <stdio.h>

int main()
{
	char c = '1';
	int nOnesToGenerate = 0;
	printf("Enter the number of 1s (ones) to generate: ");
	scanf("%d", &nOnesToGenerate);
	for (int i = 0; i < nOnesToGenerate; ++i) {
		printf ("%c", c);
	}
	printf ("%c", '\n');

	return 0;
}
