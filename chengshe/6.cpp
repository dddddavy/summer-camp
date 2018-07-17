#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int pic[52][52], visit[52][52];

struct point{
    int x, y;
    point(){}
    point(int _x, int _y) {x=_x;y=_y;}
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(int argc, char const *argv[])
{
    int h,w,m,i,j,nx,ny;
    cin >> h >> w >> m;
    while (h+w+m!=0)
    {
        int total = 0,cnt = 0;
        for (i=0; i < h;++i)
        for (j = 0;j < w;++j)
        {
            cin >> pic[i][j];
            visit[i][j]=0;
        }

        queue<point> que;
        while(cnt < h*w)
        {
            int flag = 0;
            total += 1;
            for (i=0;i<h;++i)
            {
                for (j=0;j<w;++j)
                    if (visit[i][j]==0)
                    {
                        flag = 1;
                        break;
                    }
                if (flag)
                    break;
            }
            visit[i][j]=1;
            cnt += 1;
            que.push(point(i,j));
            while (!que.empty())
            {
                point pt = que.front();
                que.pop();
                for (i =0;i<4;++i)
                {
                    nx = pt.x+dx[i];
                    ny = pt.y+dy[i];
                    if (nx>=0 && nx < h && ny >= 0 && ny < w && abs(pic[pt.x][pt.y] - pic[nx][ny]) <= m && visit[nx][ny] == 0)
                    {
                        visit[nx][ny]=1;
                        cnt += 1;
                        que.push(point(nx, ny));
                    }
                }
            }
        }

        cout << total << endl;

        cin >> h >> w >> m;
    }
    return 0;
}
