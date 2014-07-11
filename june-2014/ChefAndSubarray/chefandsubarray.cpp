#include <stdio.h>

int main()
{
    int nNumbers = 0;
    int number = 0;
    int max_len = 0, cur_len = 0;

    scanf("%d", &nNumbers);
    //printf("Debug: %d\n", nNumbers);

    for (int i = 0; i < nNumbers; ++i) {
        scanf("%d", &number);
        //printf("Debug: %d\n", numbers[i]);
        if (number > 0){
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
