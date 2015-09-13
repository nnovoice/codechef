#include <stdio.h>
//#include <climits>

//using namespace std;

int main()
{
    //cout << "ulonglongmax=" << ULONG_LONG_MAX << endl;
    unsigned long long int location = 0;
    while (scanf("%llu", &location) != EOF) {
        if ((location % 3) == 0) {
            printf("yes\n");
        }
        else {
            if (((location - 1) % 6) == 0) {
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
        }
    }
    return 0;
}
