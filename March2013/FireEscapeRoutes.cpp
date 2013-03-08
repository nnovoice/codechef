#include <iostream>
#define MAX 100000
#define NUMINTS 3125

int friendsMatrix[NUMINTS * NUMINTS];
int employees[NUMINTS];
int visited[NUMINTS];

using namespace std;

class FireEscapeRoutes {
private:
	int nCases;
	int nEmployees;
	int nRelations;
	int employeeNum1, employeeNum2;
private:
	void init() {
		memset(friendsMatrix, 0, sizeof(int) * NUMINTS * NUMINTS);
		memset(employees, 0, sizeof(int) * NUMINTS);
		memset(visited, 0, sizeof(int) * NUMINTS);
	}
	void setFriends() {
		
	}
	void setEmployees() {
	}
	bool isFriend(int* pEmployee1, int* pEmployee2) {
		return true;
	}
	void printFriendsMatrix() {
		for (int i = 1; i <= nEmployees; ++i) {
			cout << "Friends of " << i << " : ";
			for (int j = 1; j <= nEmployees; ++j) {
				if (isFriend(&i, &j)) {
					cout << j << " ";
				}
			}
			cout << endl;
		}
	}
public:
	FireEscapeRoutes() {
		freopen("C:\\data\\personal\\programming\\codechef\\input_files\\March2013\\fireescaperoutes.txt", "r", stdin);
	}
	~FireEscapeRoutes() {
	}
	void create() {
		cin >> nCases;
		while(nCases--) {
			cin >> nEmployees >> nRelations;

			init();

			for (int i = 1; i <= nRelations; ++i) {
				cin >> employeeNum1 >> employeeNum2;

				setFriends();
				
				setEmployees();
			}

			printFriendsMatrix();

		}
	}
};

int main() {
	FireEscapeRoutes routes;
	routes.create();
	return 0;
}
