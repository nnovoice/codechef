#include <iostream>
#include <bitset>
#define MAXSIZE 100001
#define MAX 100000
using namespace std;

bitset <MAXSIZE> friendsMatrix[MAXSIZE];
bitset <MAXSIZE> employees;

class FireEscapeRoutes {
private:
	int nCases;
	int nEmployees;
	int nRelations;
	int employeeNum1, employeeNum2;
private:
	void init() {
		for (int i = 0; i < (nEmployees + 1); ++i) {
			friendsMatrix[i].reset();
		}
		employees.reset();
	}
	void printFriendsMatrix() {
		for (int i = 1; i <= nEmployees; ++i) {
			cout << "Friends of " << i << " : ";
			for (int j = 1; j <= nEmployees; ++j) {
				if (friendsMatrix[i].test(j)) {
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
	void create() {
		cin >> nCases;
		while(nCases--) {
			cin >> nEmployees >> nRelations;

			init();

			for (int i = 1; i <= nRelations; ++i) {
				cin >> employeeNum1 >> employeeNum2;

				friendsMatrix[employeeNum1].set(employeeNum2);
				friendsMatrix[employeeNum2].set(employeeNum1);
				
				employees.set(employeeNum1);
				employees.set(employeeNum2);
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
