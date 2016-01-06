#include <iostream>
#include <climits>
using namespace std;

const int MOD = 1000000 + 7;
const int MAX = MOD + 11;
int a[MAX];

//# times the index appears in the products...they represent a[0], a[1], a[2]...
//                 0, 1, 2, 3, 4, 5,  6,  7,  8,   9,  10,  11,   12,   13, 14...                  
int occurs[MAX] = {0, 1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

typedef unsigned long long int ULLI;

int main()
{
    int T = 0, n = 0;
    //a[0] = INT_MIN;
    ULLI tot = 0, t = 0;
    cin >> T;
    while(T--) {
        cin >> n;
        n += 1; // a[0] to a[n] being read into a[1] to a[n+1]
        cout << "debug: " << " n=" << n << endl;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cout << a[i] << " ";
        }
        cout << endl;

        tot = 0;
        t = 0;
        for (int i = 2; i <= n; ++i) {
            if (occurs[i] == 0) {
                occurs[i] = (occurs[i - 1] << 1);
            }
            for (int j = 1; j < i; ++j) {
                t += (occurs[j] * a[j]);
                tot += t * a[i];
                cout << "debug: " << "tot=" << tot << " t=" << t << " occurs[" << j << "]=" << occurs[j] << " a[" << i << "]= " << a[i] << endl;
            }
            tot *= 2;
            cout << "debug: " << "tot= " << tot << endl;
        }
        cout << tot << endl;

    }
    return 0;
}
