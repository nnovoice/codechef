#include <stdio.h>
#include <string.h>

#define MAXSTACKLEN 1000002
char charStack[MAXSTACKLEN];
int stackIndex;

int main()
{
    int nCases = 0;
    scanf ("%d", &nCases);

    int nParamsRead = 0;
    int maxLen = 0;
    int curLen = 0;

    char c = ' ';
    scanf("%c", &c); // read the '\n' after the nCases

    for (int i = 0; i < nCases; ++i) {
        memset(charStack, '\0', sizeof(char) * MAXSTACKLEN);
        stackIndex = 0;
        maxLen = 0;
        curLen = 0;

        while (1) {
            nParamsRead = scanf("%c", &c);
            if (nParamsRead == EOF) {
                printf ("%d\n", maxLen);
                break;
            }

            //printf ("%c", c);
            if (c == '\n') { // end of test case
                if (curLen > maxLen) maxLen = curLen;
                printf ("%d\n", maxLen);
                break;
            }
            else {
                if (c == '>') {
                    if (charStack[stackIndex - 1] == '<') {
                        curLen += 2;
                        --stackIndex;
                        if (stackIndex == 0) { // don't accumulate cur len if there is nothing on stack
                            if (curLen > maxLen) maxLen = curLen;
                            curLen = 0;
                        }
                    }
                    else { //invalid combination => end of current combination
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
