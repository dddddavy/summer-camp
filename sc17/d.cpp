#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num[7][20];
int len;

void doit(int target)
{
    string ans = "AAAAA";
    for (int v = 0; v < len; ++v)
    {
        for (int w = 0; w < len; ++w)
        {
            if (w == v)
                continue;
            for (int x = 0; x < len; ++ x)
            {
                if (x == w || x == v)
                    continue;
                for (int y = 0; y < len; ++y)
                {
                    if (y == x || y == w || y == v)
                        continue;
                    for (int z = 0; z < len; ++z)
                    {
                        if (z == y || z == x || z == w || z == v)
                            continue;
                        int temp = num[1][v] - num[2][w] + num[3][x] - num[4][y] + num[5][z];
                        if (temp == target)
                        {
                            string nans = "";
                            nans += num[1][v] + 'A' - 1;
                            nans += num[1][w] + 'A' - 1;
                            nans += num[1][x] + 'A' - 1;
                            nans += num[1][y] + 'A' - 1;
                            nans += num[1][z] + 'A' - 1;
                            if (nans > ans)
                                ans = nans;
                        }
                    }
                }
            }
        }
    }
    if (ans == "AAAAA")
        printf("no solution\n");
    else
        cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int target;
    char str[20];
    cin >> target >> str;
    while (1)
    {
        if (target == 0 && str[0] == 'E' && str[1] == 'N' && str[2] == 'D')
            break;
        int i, j;
        len = strlen(str);
        for (i = 0; i < len; ++i)
        num[1][i] = str[i] - 'A' + 1;
        for (j = 2; j <= 5; ++j)
        for (i = 0; i < len; ++i)
            num[j][i] = num[j - 1][i] * num[1][i];
        doit(target);
        cin >> target >> str;
    }
    return 0;
}
