#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[20][20];
int used_time[20][20];
int visit[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct point
{
    int x, y;
    point() {}
    point(int _x, int _y) {x = _x; y = _y;}
};

queue<point> que;

int main(int argc, char const *argv[])
{
    int k, m, t, i, j, sx, sy, ex, ey, nx, ny;
    char c;
    cin >> k;
    for (int ki = 0; ki < k; ++ki)
    {
        while(!que.empty())
            que.pop();
        cin >> m >> t;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        for (i = 0; i < m; ++i)
        for (j = 0; j < m; ++j)
        {
            used_time[i][j] = 1 << 30;
            cin >> c;
            if (c == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (c == 'E')
            {
                ex = i;
                ey = j;
            }
            else if (c == '#')
                map[i][j] = 1;
        }
        used_time[sx][sy] = 0;
        visit[sx][sy] = 1;
        que.push(point(sx, sy));
        while (!que.empty())
        {
            point now = que.front();
            que.pop();
            if (now.x == ex && now.y == ey)
                break;
            for (i = 0; i < 4; ++i)
            {
                nx = now.x + dx[i];
                ny = now.y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < m && visit[nx][ny] == 0 && map[nx][ny] != 1)
                {
                    visit[nx][ny] = 1;
                    used_time[nx][ny] = used_time[now.x][now.y] + 1;
                    que.push(point(nx, ny));
                }
            }
        }
        // cout << ex << " " << ey << "\n";
        // for (i = 0; i < m; ++i)
        // for (j = 0; j < m; ++j)
        // cout << used_time[i][j] << " ";
        if (used_time[ex][ey] <= t)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
