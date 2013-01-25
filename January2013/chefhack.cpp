#define MAXGRIDSIZE 352
#define NUMMAX 10000000
typedef unsigned long long int ULLI;
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;

enum ServerType {UNKNOWN, EVEN, ODD, PRIME};
class chefhack {
	int nCases;
	int N;
	int** grid;
	int serverState[MAXGRIDSIZE][MAXGRIDSIZE];
	ServerType gridServerType[MAXGRIDSIZE][MAXGRIDSIZE];
	ULLI nUnsuccessfulTries;

	bool *isComposite;
	int* primeIndexStore;
private:
	void init() {
		N = 0;
		nUnsuccessfulTries = 0;
		grid = new int*[MAXGRIDSIZE];
		for(int i = 0; i < MAXGRIDSIZE; ++i)
			grid[i] = new int[MAXGRIDSIZE];
	}
	void initGrid() {
		for (int i = 0; i < MAXGRIDSIZE; ++i) {
              memset(grid[i], 0, sizeof(grid[i][0]) * MAXGRIDSIZE);
        }
		memset(serverState, 0, sizeof(serverState[0][0]) * MAXGRIDSIZE * MAXGRIDSIZE);
		memset(gridServerType, UNKNOWN, sizeof(gridServerType[0][0]) * MAXGRIDSIZE * MAXGRIDSIZE);
	}
	void initPrimes() {
		genPrimesUsingEratosthenesSieve(NUMMAX);
	}
	void printServerStates() {
		for(int j = 1; j < MAXGRIDSIZE; ++j) {
			for(int k = 1; k < MAXGRIDSIZE; ++k) {
				//cout << serverState[j][k] << " ";
			}
			//cout << endl;
		}
	}
public:
	chefhack() { 
		//freopen("C:\\data\\personal\\programming\\codechef\\input_files\\Jan2013\\chefhack.txt", "r", stdin); 
		init(); 
		initGrid(); 
		initPrimes(); 
	}
	~chefhack() {
		delete [] isComposite;
	}

	void hack() {
		cin >> nCases;
		for(int i = 0; i < nCases; ++i) {
			init();
			
			initGrid();

			scanf("%d", &N);
			//cout << N << endl;
			for(int j = 1; j <= N; ++j) {
				for(int k = 1; k <= N; ++k) {
					scanf("%d", &grid[j][k]);
					//cout << grid[j][k] << " ";
				}
				//cout << endl;
			}
			
			processGrid();
		}
	}
private:
	void processGrid() {
		int curTries = 0;
		ServerType type = UNKNOWN;
		for(int j = 1; j <= N; ++j) {
			for(int k = 1; k <= N; ++k) {
				type = getServerType(j, k, grid[j][k]);

				cout << "serverState[" << j << "][" << k << "] is=" << serverState[j][k] << " server type= " << type << endl;
				if (serverState[j][k] == 0) {
					if(isANeighbourCracked(j, k, type) == false) {
						cout << j << " " << k << " " << grid[j][k] << "is LOCKED... ";
						curTries = getNumUnsuccessfulTries(j, k, grid[j][k], type);
						nUnsuccessfulTries += (ULLI) curTries;
						cout << "Current tries= " << curTries << " interim Tries= " << nUnsuccessfulTries << endl;
					}
				}

				unlockServers(j, k, type);
			}
		}
		//printf("%llu\n", nUnsuccessfulTries);
		cout << nUnsuccessfulTries << endl;
	}

	bool isANeighbourCracked(int i, int j, ServerType type) {
		if(type == PRIME)
			return false;

		int rows[4] = {i - 1, i,     i + 1, i};
		int cols[4] = {j,     j - 1, j,     j + 1,};

		ServerType neighbourType = UNKNOWN;
		for(int m = 0; m < 4; ++m) {
			if (serverState[rows[m]][cols[m]] == 1) { //if unlocked
				neighbourType = getServerType(rows[m], cols[m], grid[rows[m]][cols[m]]);
				if (type == neighbourType) {
					return true;
				}
			}
		}
		return false;
	}

	void unlockServers(int i, int j, ServerType type) {
		serverState[i][j] = 1;

		if(type == PRIME)
			return;

		int rows[4] = {i - 1, i + 1, i, i};
		int cols[4] = {j, j, j + 1, j - 1};
		ServerType neighbourType = UNKNOWN;
		for(int m = 0; m < 4; ++m) {
			if (serverState[rows[m]][cols[m]] == 0) {
				neighbourType = getServerType(rows[m], cols[m], grid[rows[m]][cols[m]]);
				if (type == neighbourType) {
					//cout << i << " " << j << " neighbour " << rows[m] << " " << cols[m] << "is unlocked" << endl;
					serverState[rows[m]][cols[m]] = 1;
				}
			}
		}
	}

	ServerType getServerType(int row, int col, int value) {
		if(gridServerType[row][col] == UNKNOWN) {
			//cout << row << " " << col << " " << " server type= " << UNKNOWN << endl;
			ServerType type = UNKNOWN;
			
			if(value == 2) {
				type = PRIME;
			}
			else if ((value % 2) == 0) {
				type = EVEN;
			}
			else if (isPrime(value)) {
				type = PRIME;
			}
			else {
				type = ODD;
			}
			gridServerType[row][col] = type;
		}
		
		//cout << row << " " << col << " " << " server type= " << gridServerType[row][col] << endl;
		return gridServerType[row][col];
	}

	bool isPrime(int value) {
		if (!isComposite[value])
			return true;
		return false;
	}

	int getPrimeTries(int value) {
		//cout << "Tries for " << value << " is= " << primeIndexStore[value] << endl;
		return primeIndexStore[value];
	}

	int getNumUnsuccessfulTries(int j, int k, int value, ServerType type) {
		int tries = 0;
		if (serverState[j][k] == 1)
			return tries;

		switch(type) {
			case EVEN:
				tries = value / 2;
				break;
			case ODD:
				tries = ((value + 1) / 2) + 1;
				break;
			case PRIME:
				tries = getPrimeTries(value);
				break;
			case UNKNOWN:
				tries = 0xFFFFFFFF;
				break;
		}
		return tries;
	}
//public:
	void genPrimesUsingEratosthenesSieve(int upperBound) {
		int upperBoundSquareRoot = (int)sqrt((double)upperBound);
		isComposite = new bool[upperBound + 1];
		primeIndexStore = new int[upperBound + 1];

		memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
		memset(primeIndexStore, 0, sizeof(int) * (upperBound + 1));
		isComposite[0] = true;
		isComposite[1] = true;
		int primeIndex = -1;
		for (int m = 2; m <= upperBoundSquareRoot; m++) {
			if (!isComposite[m]) {
				primeIndexStore[m] = ++primeIndex;
				//cout << m << "," << primeIndex << endl;
				for (int k = m * m; k <= upperBound; k += m)
					isComposite[k] = true;
			}
		}

		for (int m = upperBoundSquareRoot; m <= upperBound; m++)
		{
			if (!isComposite[m]) {
				primeIndexStore[m] = ++primeIndex;
				//cout << m << "," << primeIndex << endl;
			}
		}
	}
};

int main() {
	chefhack po;
	po.hack();
	//po.genPrimesUsingEratosthenesSieve(10000000);
	return 0;
}