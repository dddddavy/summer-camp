#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int num;
    char str[222];
    scanf("%d", &num);
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < num; ++i)
    {
        int flag = 0, tmp = 1;
        for(int j = i; j < len; j += num)
        {
            if (flag == 0)
            {
                printf("%c", str[j]);
                flag = 1;
            } else {
                printf("%c", str[tmp * num - 1 - j]);
                flag = 0;
            }
            tmp += 2;
        }
    }
    printf("\n");
    return 0;
}
