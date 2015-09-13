#include <iostream>
using namespace std;

bool is_pow_of_2(long n) {
    long temp = n & ~(n - 1);
    return ((n - temp) == 0) ? true : false;
}

long num_ops(long a, long b) {
    long nops = 0;
    while (a != b) {
        nops += 1;
        if (is_pow_of_2(a)) {
            if (a < b) a <<= 1;
            else a >>= 1;
        }
        else {
            if (a % 2 == 0) a /= 2;
            else {
                a -= 1;
                a /= 2;
            }
        }
    }
    return nops;
}


int main()
{
    long a = 0, b = 0;
    int T = 0;
    long nops = 0;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        nops = num_ops (a, b);
        cout << nops << endl;
    }
    return 0;
}
