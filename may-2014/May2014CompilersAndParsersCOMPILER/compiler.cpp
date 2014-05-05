#include <stdio.h>
#include <string.h>

#define MAXSTACKLEN 1000002
char charStack[MAXSTACKLEN];
int stackIndex;

int main()
{
    int nCases = 0;
    scanf ("%d", &nCases);

    int nParamsRead = 0, maxLen = 0, curLen = 0;
    bool valid = true;

    char c = ' ';
    scanf("%c", &c); // read the '\n' after the nCases

    for (int i = 0; i < nCases; ++i) {
        memset(charStack, '\0', sizeof(char) * MAXSTACKLEN);
        stackIndex = maxLen = curLen = 0;
        valid = true;

        while (1) {
            nParamsRead = scanf("%c", &c);
            if (nParamsRead == EOF) {
                if (stackIndex == 0 && curLen > maxLen) maxLen = curLen;
                printf ("%d\n", maxLen);
                break;
            }
            if (c == '\n') { // end of test case
                if (stackIndex == 0 && curLen > maxLen) maxLen = curLen;
                printf ("%d\n", maxLen);
                break;
            }
            if (valid == false) continue;
            else {
                if (c == '<')
                    charStack[stackIndex++] = c;
                else { /// (c == '>')
                    if (stackIndex > 0 && charStack[stackIndex - 1] == '<') {
                        curLen += 2;
                        charStack[stackIndex - 1] = ' ';
                        --stackIndex;
                        if (stackIndex == 0 && curLen > maxLen) maxLen = curLen;
                    }
                    else {
                        if (stackIndex == 0 && curLen > maxLen) maxLen = curLen;
                        valid = false;
                        curLen = 0;
                    }
                }
            }
        }
    }
    return 0;
}
