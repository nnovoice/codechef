#include <stdio.h>
#include <map>
using namespace std;

const int MAX_NUM = 2001;
map<int, map<int, int> > friendsMap;

void PrintMatrix(int n)
{
	for(int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", friendsMap[i][j]);
		}
		printf("\n");
	}
}

int GetNumFriendRequests(int n)
{
	int numRequests = 0;
	map<int, int>::iterator iter, end_iter;
	for(int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("D: i,j = %d,%d \n", i, j);

			if (friendsMap[i][j] == 0) {
				if (i == j) continue;
				printf("D: inside: i,j = %d,%d \n", i, j);
				iter = friendsMap[i].begin();
				end_iter = friendsMap[i].end();
				for ( ; iter != end_iter; ++iter) {
					printf("D: iter->first, iter->second = %d,%d \n", iter->first, iter->second);
					if (friendsMap[iter->first][j] == 1 && friendsMap[j][iter->first] == 1) {
						printf("D: Found common friend: iter->first, j = %d,%d = %d\n", iter->first, j, friendsMap[iter->first][j]);
						PrintMatrix(n);
						numRequests += 2;
						friendsMap[i][j] = 1;
						friendsMap[j][i] = 1;
						PrintMatrix(n);
						break;
					}
				}
			}
		}
	}
	return numRequests;
}

int main()
{
	int n = 0;
	char c = ' ';

	scanf ("%d", &n);
	scanf("%c", &c); // read the '\n'

	for(int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%c", &c);
			friendsMap[i][j] = c - '0';
		}
		scanf("%c", &c); // read the '\n'
	}

	PrintMatrix(n);

	printf("%d\n", GetNumFriendRequests(n));

	PrintMatrix(n);

	return 0;
}
