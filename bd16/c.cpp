#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int map[20][20];
    int n;
    cin >> n;
    int cnt = 2, x = 1, y = 0, nx, ny;
    int direction = -1;
    map[0][0] = 1;
    map[x][y] = cnt;
    while (cnt < n * n)
    {
        cnt += 1;
        nx = x + direction;
        ny = y - direction;
        if (nx < 0)
        {
            direction = 1;
            if (ny >= n)
            {
                x += 1;
                map[x][y] = cnt;
            }
            else
            {
                y += 1;
                map[x][y] = cnt;
            }
            continue;
        }
        if (ny < 0)
        {
            direction = -1;
            if (nx >= n)
            {
                y += 1;
                map[x][y] = cnt;
            }
            else
            {
                x += 1;
                map[x][y] = cnt;
            }
            continue;
        }
        if (nx >= n)
        {
            direction = -1;
            y += 1;
            map[x][y] = cnt;
            continue;
        }
        if (ny >= n)
        {
            direction = 1;
            x += 1;
            map[x][y] = cnt;
            continue;
        }
        x = nx;
        y = ny;
        map[x][y] = cnt;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << map[j][i] << " ";
        cout << endl;
    }

    return 0;
}
