#include <iostream>
#include <cstring>
using namespace std;

int map[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(int argc, char const *argv[])
{
    int n, m, i, j, x, y;
    cin >> n >> m;
    memset(map, 0, sizeof(map));
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
        cin >> map[i][j];
    int cnt = 0;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
    {
        for (int k = 0; k < 4; ++k)
        {
            x = i + dx[i];
            y = j + dy[i];
            if (map[i][j] + map[x][y] == 1)
                cnt += 1;
        }
    }
    cout << cnt / 2 << endl;
    

    return 0;
}
