#include <stdio.h>
#include <string.h>

const int MAX_CHARS = 100001;
char input[MAX_CHARS];

int main()
{
    int ncases = 0, nmismatch = 0, len = 0, i = 0, j = 0;
    scanf("%d", &ncases);
    while (ncases--) {
        nmismatch = 0;
        memset(input, '\0', sizeof(char) * MAX_CHARS);

        scanf("%s", input);
        len = strlen(input);
        i = 0;
        j = len - 1;
        while (i < j) {
            if (input[i] == input[j]) {
                ++i;
                --j;
            }
            else {
                ++nmismatch;
                
                if (input[i + 1] == input[j])
                    ++i;
                else {
                    if (input[i] == input[j - 1])
                        --j;
                    else
                        ++nmismatch;
                }
                
                if (nmismatch > 1)
                    break;
            }
        }
        //printf("Debug: input=%s i=%d j=%d len=%d nmismatch=%d\n", input, i, j, len, nmismatch);

        if (nmismatch <= 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
