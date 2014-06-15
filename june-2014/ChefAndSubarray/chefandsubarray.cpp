#include <stdio.h>
const int MAXNUMBERS = 100000;

int main()
{
    int nNumbers = 0;
    int numbers[MAXNUMBERS] = {0};
    int max_len = 0, cur_len = 0;

    scanf("%d", &nNumbers);
    //printf("Debug: %d\n", nNumbers);

    for (int i = 0; i < nNumbers; ++i) {
        scanf("%d", &numbers[i]);
        //printf("Debug: %d\n", numbers[i]);
        if (numbers[i] > 0){
            ++cur_len;
            if (cur_len > max_len)
                max_len = cur_len;
        }
        else {
            cur_len = 0;
        }
    }

    printf("%d\n", max_len);

    return 0;
}
