#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int map[11][11], visit[11][11], mytime[11][11];
int dx[4] = {1, -1, 0,0};
int dy[4]={0,0,1,-1};

struct point{
    int x, y;
    point(){}
    point(int _x, int _y) { x= _x;y=_y;}
};

int main(int argc, char const *argv[])
{
    int k, ki, m, t, i, j, sx, sy,ex,ey,nx,ny;
    char c;
    cin >> k;
    for (ki=0;ki<k;++ki)
    {
        cin >> m >> t;
        memset(map, 0, sizeof(map));
        for (i=0;i<m;++i)
        for (j=0;j<m;++j)
        {
            cin >> c;
            if (c == 'S')
            {
                sx=i;
                sy = j;
            }
            if (c=='E')
            {
                ex=i;
                ey=j;
            }
            if (c == '#')
                map[i][j] = 1;
            visit[i][j] = 0;
            mytime[i][j] = t +100;
        }
        
        queue<point> que;
        visit[sx][sy] = 1;
        mytime[sx][sy] = 0;
        que.push(point(sx, sy));
        
        while(!que.empty())
        {
            point pt = que.front();
            que.pop();
            if (pt.x == ex && pt.y == ey)
                break;
            for (i=0;i<4;++i)
            {
                nx=pt.x+dx[i];
                ny=pt.y+dy[i];
                if (nx >=0 && nx < m && ny >= 0 && ny < m && map[nx][ny]==0 && visit[nx][ny] == 0)
                {
                    visit[nx][ny]=1;
                    mytime[nx][ny]=mytime[pt.x][pt.y] + 1;
                    que.push(point(nx, ny));
                }
            }
        }

        if (mytime[ex][ey] <= t)
            cout << "YES\n";
        else 
            cout << "NO\n";

    }
    return 0;
}
