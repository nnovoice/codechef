#include <iostream>
#include <string.h>
using namespace std;

#define MAXSTACKLEN 1000002
char charStack[MAXSTACKLEN];
int stackIndex;

int main()
{
    int nCases = 0;
    cin >> nCases;
    cout << nCases;

    int maxLen = 0;
    int curLen = 0;

    char c = ' ';
//    while (cin >> c) {
//        cout << c;
//    }
//    return 0;
    while (nCases--) {
        memset(charStack, '\0', sizeof(char) * MAXSTACKLEN);
        stackIndex = 0;
        maxLen = 0;
        curLen = 0;

        while (cin >> c) {
            cout << c;
            if (c == '\n') { // end of test case
                if (curLen > maxLen) maxLen = curLen;
                cout << maxLen << endl;
                break;
            }
            else {
                if (c == '>') {
                    if (charStack[stackIndex - 1] == '<') {
                        curLen += 2;
                        --stackIndex;
                    }
                    else { //invalid
                        if (curLen > maxLen) maxLen = curLen;
                        curLen = 0;
                    }
                }
                else if (c == '<') {
                    charStack[stackIndex++] = c;
                }
            }
        }
    }
    return 0;
}
