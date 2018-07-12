#include <stdio.h>
#include <string.h>

char map[3000][3000];

void doit(int i, int j, int n)
{
    if (n == 1)
    {
        map[i][j] = ' ';
        map[i][j + 1] = '/';
        map[i][j + 2] = '\\';
        map[i + 1][j] = '/';
        map[i + 1][j + 1] = '_';
        map[i + 1][j + 2] = '_';
        map[i + 1][j + 3] = '\\';
        return;
    }

    int _ = 1 << (n - 1);
    doit(i, j + _, n - 1);
    doit(i + _, j, n - 1);
    doit(i + _, j + (_ << 1), n - 1);

}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        memset(map, 0, sizeof(map));
        doit(0, 0, n);
        // printf("hhhh");
        for (int i = 0; i < (1 << n); ++i)
        {
            for (int j = 0; j <= (1 << n) + i; ++j)
                if (map[i][j] == 0)
                    printf(" ");
                else
                    printf("%c", map[i][j]);
            printf("\n");
        }
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("\n");
    }
    return 0;
}
