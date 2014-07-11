#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int x = 0, y = 0;
    int MAX = 25;
    cout << MAX << " " << MAX << " " << MAX << endl;

    for (int i = 0; i < MAX; ++i) {
        x = rand() % MAX + 1;
        y = rand() % MAX + 1;
        cout << x << " " << y << endl;
    }
    return 0;
}
