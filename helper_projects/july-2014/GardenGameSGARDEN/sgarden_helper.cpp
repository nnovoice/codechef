#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_POSITIONS = 100000;
int positions[MAX_POSITIONS];

int main()
{
	for (int i = 0; i < MAX_POSITIONS; ++i) {
		positions[i] = i + 1;
	}

	int rand_num = rand() % 100 + 1;
	for (int i = 0; i < rand_num; ++i) {
		random_shuffle(positions, positions + MAX_POSITIONS);
	}
//
//	int i = 0;
//	do {
//		++i;
//	} while(next_permutation(positions, positions + rand_num))

	for (int i = 0; i < MAX_POSITIONS; ++i) {
		cout << positions[i] << " ";
	}
	cout << endl;

	return 0;
}
