#include <iostream>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, num, i, j, dis, total, mi, mj;
    char c, x;
    int map[30][30];
    int visit[30];
    cin >> n;
    while (n != 0)
    {
        memset(map, 0, sizeof(map));
        for (i = 0; i < n - 1; ++i)
        {
            cin >> c;
            cin >> num;
            for (j = 0; j < num; ++j)
            {
                cin >> x >> dis;
                map[c - 'A'][x - 'A'] = map[x - 'A'][c - 'A'] = dis;
            }
        }

        memset(visit, 0, sizeof(visit));
        total = 0;
        visit[0] = 1;
        num = 1;

        while (num != n)
        {
            int min = 1 << 30;
            mi = mj = 0;
            for (i = 0; i < n; ++i)
            {
                if (visit[i] == 0)
                    continue;
                for (j = 0; j < n; ++j)
                {
                    if (visit[j] == 1 || j == i || map[i][j] == 0)
                        continue;
                    if (map[i][j] < min)
                    {
                        min = map[i][j];
                        mi = i;
                        mj = j;
                    }
                }
                
            }
            visit[mj] = 1;
            num += 1;
            total += map[mi][mj];
        }

        cout << total << endl;
        cin >> n;
    }
    return 0;
}
