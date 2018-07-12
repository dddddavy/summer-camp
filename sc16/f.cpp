#include <stdio.h>
#include <string.h>

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(int argc, char const *argv[])
{
    int l, r, c;
    int map[33][33][33];
    int pass[33][33][33];
    int ilist[40000], jlist[40000], klist[40000], tlist[40000];
    char tmp[200];
    scanf("%d %d %d", &l, &r, &c);
    while (l != 0)
    {
        int i, j, k, si, sj, sk, ei, ej, ek, ci, cj, ck, ni, nj, nk;
        char ch;
        gets(tmp);
        for (i = 1; i <= l; ++i)
        {
            for (j = 1; j <= r; ++j)
            {
                for (k = 1; k <= c; ++k)
                {
                    scanf("%c", &ch);
                    if (ch == '#')
                        map[i][j][k] = 1;
                    else
                    {
                        map[i][j][k] = 0;
                        if (ch == 'S')
                        {
                            si = i;
                            sj = j;
                            sk = k;
                        }
                        else if (ch == 'E')
                        {
                            ei = i;
                            ej = j;
                            ek = k;
                        }
                    }
                }
                gets(tmp);
            }
            gets(tmp);
        }

        // printf("%d %d %d %d %d %d\n", si, sj, sk, ei, ej, ek);

        memset(pass, 0, sizeof(pass));
        int index = 0, count = 1;
        ilist[index] = si;
        jlist[index] = sj;
        klist[index] = sk;
        tlist[index] = 0;

        int flag = 0;

        while(index != count)
        {
            ci = ilist[index];
            cj = jlist[index];
            ck = klist[index];
            if (ci == ei && cj == ej && ck == ek)
            {
                printf("Escaped in %d minute(s).\n", tlist[index]);
                flag = 1;
                break;
            }

            for (i = 0; i < 6; ++i)
            {
                ni = ci + dx[i];
                nj = cj + dy[i];
                nk = ck + dz[i];
                if (ni > 0 && ni <= l && nj > 0 && nj <= r && nk > 0 && nk <= c)
                {
                    if (map[ni][nj][nk] == 0 && pass[ni][nj][nk] == 0)
                    {
                        pass[ni][nj][nk] = 1;
                        ilist[count] = ni;
                        jlist[count] = nj;
                        klist[count] = nk;
                        tlist[count] = tlist[index] + 1;
                        count += 1;
                    }
                }
            }

            index += 1;

        }
        if (flag == 0)
            printf("Trapped!\n");

        scanf("%d %d %d", &l, &r, &c);
    }
    return 0;
}
