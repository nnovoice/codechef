#include <iostream>
#define MODNUM 1000000007
#define MAX 100000
#define NUMINTS 3125
// 3125 integers = 3125 * 32 bits (at least) = 100000 bits
typedef unsigned long long int ULLI;

int friendsMatrix[NUMINTS * NUMINTS];
int employees[NUMINTS];
int visited[NUMINTS];
int friendsStack[MAX + 1];
int stackNum;

using namespace std;

class FireEscapeRoutes {
private:
	int nCases;
	int nEmployees;
	int nRelations;
	int employeeNum1, employeeNum2;
	int nBitsInInt;

	int indexEmployee;
	int employeeBitPos;
	int actualBitPos;
	int bit;
	ULLI nFriendsInGroup;
	ULLI nWaysOfSelectingCaptains;
	ULLI nFireEscapeRoutes;
private:
	void init() {
		memset(friendsMatrix, 0, sizeof(int) * NUMINTS * NUMINTS);
		memset(employees, 0, sizeof(int) * NUMINTS);
		memset(visited, 0, sizeof(int) * NUMINTS);
		memset(friendsStack, 0, sizeof(int) * MAX);
		nFireEscapeRoutes = 0;
		nWaysOfSelectingCaptains = 1;
	}

	void setFriends() {
		setFriend(&employeeNum1, &employeeNum2);
		setFriend(&employeeNum2, &employeeNum1);
	}

	void setFriend(int* pEmployee1, int* pEmployee2) {
		indexEmployee = (*pEmployee2) / nBitsInInt;
		employeeBitPos = (*pEmployee2) % nBitsInInt;
		actualBitPos = nBitsInInt - employeeBitPos;
		bit = 1 << actualBitPos;
		friendsMatrix[(*pEmployee1)*MAX + indexEmployee] |= bit;
	}

	void setEmployees() {
		setEmployee(&employeeNum1);
		setEmployee(&employeeNum2);
	}

	void setEmployee(int* pEmployee) {
		indexEmployee = (*pEmployee) / nBitsInInt;
		employeeBitPos = (*pEmployee) % nBitsInInt;
		actualBitPos = nBitsInInt - employeeBitPos;
		bit = 1 << actualBitPos;
		employees[indexEmployee] |= bit;
	}

	bool isFriend(int* pEmployee1, int* pEmployee2) {
		indexEmployee = (*pEmployee2) / nBitsInInt;
		employeeBitPos = (*pEmployee2) % nBitsInInt;
		actualBitPos = nBitsInInt - employeeBitPos;
		bit = 1 << actualBitPos;
		if (friendsMatrix[(*pEmployee1)*MAX + indexEmployee] & bit) {
			return true;
		}
		return false;		
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
	
	void printEmployees() {
		int nEmployeesWithoutFriends = 0;
		int nEmployeesWithFriends = 0;
		cout << endl << "employees who are friends with others= ";

		for (int i = 1; i <= nEmployees; ++i) {
			indexEmployee = (i) / nBitsInInt;
			employeeBitPos = (i) % nBitsInInt;
			actualBitPos = nBitsInInt - employeeBitPos;
			bit = 1 << actualBitPos;
			if (employees[indexEmployee] & bit) {
				cout << i << " ";
				++nEmployeesWithFriends;
			}
			else
			{
				++nEmployeesWithoutFriends;
			}
		}
		cout << endl << "employees with friends= " << nEmployeesWithFriends;
		cout << endl << "employees without friends= " << nEmployeesWithoutFriends;

	}
	
	void numRoutes() {
		ULLI nEmployeesWithoutFriends = 0;

		for (int i = 1; i <= nEmployees; ++i) {
			indexEmployee = (i) / nBitsInInt;
			employeeBitPos = (i) % nBitsInInt;
			actualBitPos = nBitsInInt - employeeBitPos;
			bit = 1 << actualBitPos;

			if (employees[indexEmployee] & bit) {
				if (isVisited(i) == false) {
					findNumFriends(i);
					if (nFriendsInGroup > 0) {
						nWaysOfSelectingCaptains *= (nFriendsInGroup % MODNUM);
						++nFireEscapeRoutes;
					}
				}
			}
			else
			{
				++nEmployeesWithoutFriends;
			}
		}

		if (nEmployeesWithoutFriends > 0) {
			nFireEscapeRoutes += nEmployeesWithoutFriends;
			//nWaysOfSelectingCaptains *= (nEmployeesWithoutFriends % MODNUM); // bug here: nWays remain same because 
			// we can get 3 * 1 * 1 (3 friends in 1 group) * 1 emp with no friends * 1 emp with no friends
		}
	}
	
	void findNumFriends(int employeeNum) {
		nFriendsInGroup = 0;
		int stackNum = 0;
		int currentEmployeeNum = 0;

		friendsStack[stackNum++] = employeeNum;
		++nFriendsInGroup;
		while (stackNum) {
			currentEmployeeNum = friendsStack[--stackNum];
			setVisited(currentEmployeeNum);
			for (int i = currentEmployeeNum + 1; i <= nEmployees; ++i) {
				if (isFriend(&currentEmployeeNum, &i) && isVisited(i) == false) {
					++nFriendsInGroup;
					friendsStack[stackNum++] = i;
				}
			}
		}
	}
	
	void setVisited(int employeeNum) {
		indexEmployee = (employeeNum) / nBitsInInt;
		employeeBitPos = (employeeNum) % nBitsInInt;
		actualBitPos = nBitsInInt - employeeBitPos;
		bit = 1 << actualBitPos;
		visited[indexEmployee] |= bit;
	}
	
	bool isVisited(int employeeNum) {
		indexEmployee = (employeeNum) / nBitsInInt;
		employeeBitPos = (employeeNum) % nBitsInInt;
		actualBitPos = nBitsInInt - employeeBitPos;
		bit = 1 << actualBitPos;
		if (visited[indexEmployee] & bit) {
			return true;
		}
		return false;
	}
public:
	FireEscapeRoutes() {
		freopen("C:\\data\\personal\\programming\\codechef\\input_files\\March2013\\fireescaperoutes.txt", "r", stdin);
		nBitsInInt = sizeof(int) * 8;
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

			/*printFriendsMatrix();
			printEmployees();*/

			numRoutes();

			cout << nFireEscapeRoutes << " " << nWaysOfSelectingCaptains << endl;
		}
	}
};

int main() {
	FireEscapeRoutes routes;
	routes.create();
	return 0;
}
