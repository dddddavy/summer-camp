#include <string.h>
#include <stdio.h>

int main()
{
    char str[512];
    // scanf("%s", str);
    gets(str);
    int len = strlen(str);
    int start = 0, end = 0;
    for (int i = 0; i < len; ++i)
    {
        // printf("%c", str[i]);
        if (str[i] == ' ')
        {
            end = i;
            for (int j = end - 1; j >= start; --j)
                printf("%c", str[j]);
            printf(" ");
            start = i + 1;
        }
    }
    // printf("%d %d\n", start, len);
    for (int i = len - 1; i >= start; --i)
        printf("%c", str[i]);
    printf(" \n");

    return 0;
}