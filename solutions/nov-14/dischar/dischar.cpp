#include <stdio.h>
#include <string.h>

const int MAX_CHARS = 100001;
const int MAX_ALPHA = 26;
char input[MAX_CHARS];
int alphabet_present[MAX_ALPHA];

int main()
{
    int ncases = 0, maxlen = 0;
    scanf("%d", &ncases);
    while (ncases--) {
        maxlen = 0;
        memset(input, '\0', MAX_CHARS);
        memset(alphabet_present, 0, sizeof(int) * MAX_ALPHA);

        scanf("%s", input);
        //printf("Debug %s\n", input);
        for (int i = 0; input[i] != '\0'; ++i) {
            //printf("%c ", input[i]);
            if (alphabet_present[input[i] - 'a'] == 0) {
                //printf("Debug: maxlen=%d char=%c\n", maxlen, input[i]);
                maxlen += 1;
                alphabet_present[input[i] - 'a'] = 1;
            }
        }
        printf("%d\n", maxlen);
    }
    return 0;
}
