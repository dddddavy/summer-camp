#include <iostream>
#include <cstring>
using namespace std;

int save[210][210][210];
int color[210], num[210];

int doit(int s, int e, int extra_len)
{
    if (s > e)
        return 0;
    if (save[s][e][extra_len] > 0)
        return save[s][e][extra_len];
    int res = extra_len + num[e];
    res = res * res;
    if (s == e)
    {
        save[s][e][extra_len] = res;
        return res;
    }
    res += doit(s, e-1, 0);
    for (int i = e - 1; i >= s; --i)
    {
        if (color[i] != color[e])
            continue;
        int tmp = doit(s, i, extra_len + num[e]) + doit(i + 1, e - 1, 0);
        if (tmp > res)
            res = tmp;
    }
    save[s][e][extra_len] = res;
    return res;
}

int main(int argc, char const *argv[])
{
    int t, i, n, j;
    cin >> t;
    for (i = 1; i <= t; ++i)
    {
        memset(save, 0, sizeof(save));
        cin >> n;
        int end = 0, tcolor;
        cin >> color[end];
        num[end] = 1;
        for (j = 1; j < n; ++j)
        {
            cin >> tcolor;
            if (tcolor == color[end])
                num[end] += 1;
            else
            {
                end += 1;
                color[end] = tcolor;
                num[end] = 1;
            }
        }
        cout << "Case " << i << ": " << doit(0, end, 0) << endl;
    }
    return 0;
}
