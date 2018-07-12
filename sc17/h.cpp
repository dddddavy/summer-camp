#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

double map[2020][2020];
int x[2020], y[2020];
double d[2020];
int pass[2020];

int main(int argc, char const *argv[])
{
    int x0, y0, x1, y1;
    int cnt = 1;
    cin >> x0 >> y0 >> x1 >> y1;
    x[0] = x0;
    y[0] = y0;
    x[1] = x1;
    y[1] = y1;
    memset(map, 0, sizeof(map));
    while(cin >> x0 >> y0)
    {
        while (1)
        {
            cnt += 1;
            x[cnt] = x0;
            y[cnt] = y0;
            cin >> x1 >> y1;
            if (x1 == -1 && y1 == -1)
                break;
            map[cnt][cnt + 1] = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)) / 1000 / 40 * 60;
            map[cnt + 1][cnt] = map[cnt][cnt + 1];
            x0 = x1;
            y0 = y1;
        }
    }
    for (int i = 0; i < cnt; ++i)
    for (int j = i + 1; j <= cnt; ++j)
    {
        if (map[i][j] != 0)
            continue;
        double temp = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        temp = temp / 1000 / 10 * 60;
        map[i][j] = temp;
        map[j][i] = temp;
    }

    for (int i = 0; i <= cnt; i++)
    {
        d[i] = map[0][i];
        pass[i] = 0;
    }
    pass[0] = 1;
    for (int i = 0; i < cnt; ++i)
    {
        // for (int j = 0; j <= cnt; ++j)
        //     cout << d[j] << " ";
        // cout << "\n";

        int tag = 1;
        for (int j = 2; j <= cnt; ++j)
        {
            if (d[j] < d[tag] && pass[j] == 0)
                tag = j;
        }
        if (tag == 1)
            break;
        pass[tag] = 1;
        for (int j = 0; j <= cnt; ++j)
            if (d[tag] + map[tag][j] < d[j])
                d[j] = d[tag] + map[tag][j];
    }
    // cout << cnt << endl;
    // for (int i = 0; i <= cnt; ++i)
    //     cout << x[i] << " " << y[i] << endl;
        //     for (int j = 0; j <= cnt; ++j)
        //     cout << d[j] << " ";
        // cout << "\n";
    long long temp = d[1];
    // cout << temp << endl;
    // cout << (int)(d[1] + 0.5) << endl;
    cout << round(d[1]) << endl;
    return 0;
}
