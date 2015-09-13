#define MAXSTRLEN 25001
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

bool isSubsequence(char name1[MAXSTRLEN], int name1Len, char name2[MAXSTRLEN], int name2Len) {
	int index1 = 0;
	int index2 = 0;
	bool subsequence = true;

	for (; index1 < name1Len; ++index1) {
		for (; index2 < name2Len; ++index2) {
			if (name1[index1] == name2[index2])
				break;
		}
		if (index2 >= name2Len && index1 < name1Len) {
			subsequence = false;
			break;
		}
	}

	return subsequence;
}

void printResult (bool isSubsequence) {
	(isSubsequence == true) ? cout << "YES" : cout << "NO";
	cout << endl;
}

int main() {
	char name1[MAXSTRLEN] = { ' ' };
	char name2[MAXSTRLEN] = { ' ' };
	int name1Len = 0;
	int name2Len = 0;
	int nCases = 0;
	bool subsequence = false;

	cin >> nCases;
	//cout << "nCases= " << nCases << endl;
	while (nCases--) {
		memset(name1, '\0', sizeof(char) * MAXSTRLEN);
		memset(name2, '\0', sizeof(char) * MAXSTRLEN);
		scanf("%s", name1);
		scanf("%s", name2);
		name1Len = strlen(name1);
		name2Len = strlen(name2);
		//printf("name1=%s name1Len=%d name2=%s name2len=%d\n", name1, name1Len, name2, name2Len);
		if (name1Len < name2Len) {
			subsequence = isSubsequence(name1, name1Len, name2, name2Len);
			printResult(subsequence);
		}
		else {
			subsequence = isSubsequence(name2, name2Len, name1, name1Len);
			if (subsequence == false) {
				if (name1Len == name2Len) {
					subsequence = isSubsequence(name1, name1Len, name2, name2Len);
					printResult(subsequence);
				}
			}
			else {
				printResult(subsequence);
			}
		}
	}

	return 0;
}

