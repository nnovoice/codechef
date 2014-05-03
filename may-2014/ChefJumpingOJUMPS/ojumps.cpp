#include <iostream>
//#include <climits>

using namespace std;

int main()
{
    //cout << "ulonglongmax=" << ULONG_LONG_MAX << endl;
    unsigned long long int location = 0;
    while (cin >> location) {
        if ((location % 3) == 0) {
            cout << "yes" << endl;
        }
        else {
            if (((location - 1) % 6) == 0) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
