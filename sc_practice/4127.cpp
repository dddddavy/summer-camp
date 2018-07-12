#include <iostream>
#include <queue>
using namespace std;

int map[9][9];
int flag[9][9];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct point
{
    int x, y;
    point() {}
    point(int _x, int _y) {x = _x; y = _y;}
};

point previ[9][9];
point route[30];
queue<point> bfs;


int main(int argc, char const *argv[])
{
    int i, j, nx, ny;
    for (i = 0; i < 5; ++i)
    for (j = 0; j < 5; ++j)
        cin >> map[i][j];

    bfs.push(point(0, 0));
    flag[0][0] = 1;

    while(!bfs.empty())
    {
        point p = bfs.front();
        if (p.x == 4 && p.y == 4)
            break;
        bfs.pop();
        for (i = 0; i < 4; ++i)
        {
            nx = p.x + dx[i];
            ny = p.y + dy[i];
            if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
                continue;
            if (flag[nx][ny] == 1 || map[nx][ny] == 1)
                continue;
            bfs.push(point(nx, ny));
            previ[nx][ny] = p;
            flag[nx][ny] = 1;
        }
    }
    // cout << "(4, 4)\n";
    // point p(4, 4);
    // while (p.x != 0 || p.y != 0)
    // {
    //     cout << "(" << p.x << ", " << p.y << ")\n";
    //     p = previ[p.x][p.y];
    // }

    int cnt = 0;
    point p(4, 4);
    while (p.x != 0 || p.y != 0)
    {
        route[cnt] = p;
        cnt += 1;
        p = previ[p.x][p.y];
    }
    route[cnt] = p;
    for (i = cnt; i >= 0; --i)
        cout << "(" << route[i].x << ", " << route[i].y << ")\n";
    return 0;
}
