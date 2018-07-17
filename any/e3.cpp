#include <iostream>
using namespace std;

int h[110][110], dp[110][110];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int r,c;

int f(int x, int y)
{
    if (dp[x][y] != 0)
        return dp[x][y];
    int nx, ny;
    dp[x][y] = 1;
    for (int i = 0;i < 4;++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >=0 && nx<r && ny >=0&& ny < c && h[x][y] > h[nx][ny])
            dp[x][y] = max(dp[x][y], f(nx, ny) + 1);
    }
    return dp[x][y];
}

int main(int argc, char const *argv[])
{
    int i, j;
    cin >> r >> c;
    for (i = 0;i< r;++i)
    for (j = 0;j< c;++j)
    {
        cin >> h[i][j];
        dp[i][j] = 0;
    }
    int MAX = 0;
    for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j)
        MAX = max(MAX, f(i, j));
    
    cout << MAX << endl;

    return 0;
}
