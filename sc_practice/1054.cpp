// wa

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

pair<int, int> frog[10000];
set< pair<int, int> > s;

int row[6000], col[6000];

int main(int argc, char const *argv[])
{
    int r, c, n, i, j, x, y;
    cin >> r >> c;
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        cin >> x >> y;
        s.insert(make_pair(x, y));
        row[i] = x;
        col[i] = y;
    }

    int max_step = 0, new_step;

    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
    {
        if (j == i)
            continue;
        // auto ptr = s.find(make_pair(row[i], row[j]))
        int dx = row[j] - row[i];
        int dy = col[j] - col[i];
        int px = row[i] - dx;
        int py = col[i] - dy;
        int nx = row[j], ny = col[j];
        if (px >= 1 && px <= r && py >= 1 && py <= c)
            continue;

        if (max_step != 0)
        {
            px = row[i] + (max_step - 1) * dx;
            py = col[i] + (max_step - 1) * dy;
            if (!(px >= 1 && px <= r && py >= 1 && py <= c))
                continue;
        }

        int flag = 1;
        for (int k = 2; k < max_step; ++k)
        {
            nx = nx + dx;
            ny = ny + dy;
            if (!(nx >= 1 && nx <= r && ny >= 1 && ny <= c))
            {
                flag = 0;
                break;
            }
            if (s.find(make_pair(nx, ny)) == s.end())
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            continue;

        new_step = max(2, max_step);
        nx += dx;
        ny += dy;
        while (nx >= 1 || nx <= r || ny >= 1 || ny <= c)
        {
            if (s.find(make_pair(nx, ny)) != s.end())
            {
                new_step += 1;
                nx += dx;
                ny += dy;
            }
            else
                break;
        }
        if (new_step > max_step)
            max_step = new_step;
        
    }
    if (max_step < 3)
        cout << 0 << endl;
    else
        cout << max_step << endl;

    return 0;
}

