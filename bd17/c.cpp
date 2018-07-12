#include <iostream>
using namespace std;

int map[111][111];
int nmap[111][111];

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {0, -1, 1, -1, 1, 0, -1, 1};
int n, m;

int cntCell(int x, int y)
{
    int i, nx, ny, cnt = 0;
    for (i = 0; i < 8; ++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        cnt += map[nx][ny];
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int i, j;
    cin >> n >> m;
    for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
        cin >> map[i][j];
    for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
    {
        if (map[i][j] == 1)
        {
            int temp = cntCell(i, j);
            if (temp == 2 || temp == 3)
                nmap[i][j] = 1;
            else
                nmap[i][j] = 0;
        }
        else
        {
            int temp = cntCell(i, j);
            if (temp == 3)
                nmap[i][j] = 1;
            else
                nmap[i][j] = 0;
        }
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
            cout << nmap[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
