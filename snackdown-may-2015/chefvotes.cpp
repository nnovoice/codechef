#include <iostream>
using namespace std;

int main()
{
	bool possible = false;
	int votes[57];
	int combinations[57], count = 0;
	int T = 0, n = 0;
	cin >> T;
	while (T--) {
		cin >> n;
		possible = true;
        count = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> votes[i];
			combinations[i] = 0;
            count += votes[i];
		}

		for (int i = 1; i <= n; ++i) {
			if (votes[i] < n) {
				continue;
            }
			else {
				possible = false;
                break;
			}
		}
		if  (possible == false)
			cout << -1 << endl;
		else {
            if (count != n)
                cout << -1 << endl;
            else {
			    for (int i = 1; i <= n; ++i) {
				    if (votes[i] > 0) {
                        int total = votes[i];
					    for (int j = 1; j <= n; ++j) {
						    if (j != i && combinations[j] == 0 && total > 0) {
							    combinations[j] = i;
                                total -= 1;
						    }
					    }
				    }
			    }
			    for (int i = 1; i <= n; ++i) {
				    if (i == (n - 1) && combinations[i+1] == 0) {
                        combinations[i+1] = combinations[i];
                        combinations[i] = i + 1;
                    }

                    cout << combinations[i] << " ";
                    
                }
                cout << endl;
            }
		}

	}
}
