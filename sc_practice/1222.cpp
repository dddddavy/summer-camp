#include <stdio.h>
#include <string.h>

int map[9][9];
int kaiguan[9][9];

void doit()
{
    int i, j;
    for (int a1 = 0; a1 < 2; ++a1)
    for (int a2 = 0; a2 < 2; ++a2)
    for (int a3 = 0; a3 < 2; ++a3)
    for (int a4 = 0; a4 < 2; ++a4)
    for (int a5 = 0; a5 < 2; ++a5)
    for (int a6 = 0; a6 < 2; ++a6)
    {
        memset(kaiguan, 0, sizeof(0));
        kaiguan[1][1] = a1;
        kaiguan[1][2] = a2;
        kaiguan[1][3] = a3;
        kaiguan[1][4] = a4;
        kaiguan[1][5] = a5;
        kaiguan[1][6] = a6;

        for (i = 2; i <= 5; ++i)
        {
            for (j = 1; j <= 6; ++j)
            {
                if (map[i - 1][j] ^ kaiguan[i - 1][j] ^ kaiguan[i-1][j-1] ^ kaiguan[i-1][j+1] ^ kaiguan[i-2][j])
                    kaiguan[i][j] = 1;
                else
                    kaiguan[i][j] = 0;
            }
        }
        int flag = 1;
        for (j = 1; j <= 6; ++j)
        {
            if (map[5][j] ^ kaiguan[5][j] ^ kaiguan[4][j] ^ kaiguan[5][j-1] ^ kaiguan[5][j+1])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            return;
    }
}

int main(int argc, char const *argv[])
{
    int n, i, j;
    scanf("%d", &n);
    for (int ni = 0; ni < n; ++ni)
    {
        for (i = 1; i <= 5; ++i)
        for (j = 1; j <= 6; ++j)
        {
            scanf("%d", &map[i][j]);
            kaiguan[i][j] = 0;
        }
        printf("PUZZLE #%d\n", ni + 1);
        doit();

        for (i = 1; i <= 5; ++i)
        {
            for (j = 1; j <= 6; ++j)
                printf("%d ", kaiguan[i][j]);
            printf("\n");
        }
    }


    return 0;
}
