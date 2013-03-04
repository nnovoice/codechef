#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

class Approx {
	int nDigitsToApprox;
	char buf[20];
	int nCases;
private:

public:
	void output() {
		string firstLevel = "3.1";
		string recurringDecimal = "415926530119026040722614947737296840070086399613316";
		int recurringDecimalLength = recurringDecimal.length(); // 51
		cin >> nCases;
		for (int i = 0; i < nCases; ++i) {
			cin >> nDigitsToApprox;
			if (nDigitsToApprox == 0) {
				cout << 3 << endl;
			}
			else if (nDigitsToApprox == 1) {
				cout << firstLevel << endl;
			}
			else {
				int requiredNumberOfRecurringDecimalDigits = nDigitsToApprox - 1;
				int countOfNumberOfRecurringDecimalSet = requiredNumberOfRecurringDecimalDigits / recurringDecimalLength;
				int leftOverRecurringDecimalDigits = requiredNumberOfRecurringDecimalDigits % recurringDecimalLength;

				cout << firstLevel;
				for (int i = 0; i < countOfNumberOfRecurringDecimalSet; ++i) {
					cout << recurringDecimal;
				}
				for (int i = 0; i < leftOverRecurringDecimalDigits; ++i) {
					cout << recurringDecimal.at(i);
				}
				cout << endl;
			}
		}
	}
};

int main0() {
	Approx approx;
	approx.output();
	return 0;
}
