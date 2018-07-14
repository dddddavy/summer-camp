#include <iostream>
#include <cstring>
using namespace std;

struct myclock
{
    int h, m;
    myclock(){}
    myclock(int _h, int _m) {h=_h;m=_m;}
    myclock operator - (myclock c)
    {
        int h = c.h, m = c.m;
        m -= 15;
        if (m < 0)
        {
            h -= 1;
            m += 60;
        }
        if (h < 0)
            h += 24;
        return myclock(h, m);
    }
};

int pic[10][9] = {
    {0, 2, 0, 1, 0, 1, 1, 2, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 2, 0, 0, 2, 1, 1, 2, 0},
    {0, 2, 0, 0, 2, 1, 0, 2, 1},
    {0, 0, 0, 1, 2, 1, 0, 0, 1},
    {0, 2, 0, 1, 2, 0, 0, 2, 1},
    {0,2,0,1,2,0,1,2,1},
    {0,2,0,0,0,1,0,0,1},
    {0,2,0,1,2,1,1,2,1},
    {0,2,0,1,2,1,0,2,1}
};

int now[4][9], pre[4][9], cnow[4][9], cpre[4][9];
char s[3][30];
char fu[20];

int main(int argc, char const *argv[])
{
    int t, i, j, k, theh, them;
    cin >> t;
    gets(fu);
    for (int ti = 0; ti < t; ++ti)
    {
        for (j = 0; j < 3; ++j)
            gets(s[j]);
        for (i = 0; i < 3; ++i)
        {
            // cout << "fucku " << strlen(s[i]);
            for (j = 0; j < 12; ++j)
                if (s[i][j] == ' ')
                    now[j/3][j%3+i*3] = 0;
                else if (s[i][j] == '|')
                    now[j/3][j%3+i*3] = 1;
                else if (s[i][j] == '_')
                    now[j/3][j%3+i*3] = 2;
            for (k = 13; k < 25; ++k)
            {
                j = k - 13;
                if (s[i][k] == ' ')
                    pre[j/3][j%3+i*3] = 0;
                else if (s[i][k] == '|')
                    pre[j/3][j%3+i*3] = 1;
                else if (s[i][k] == '_')
                    pre[j/3][j%3+i*3] = 2;
            }
        }
        int cnt = 0;
        for (int h = 0; h < 24; ++h)
        {
        for (int m = 0; m < 60; ++m)
        {
            struct myclock nclock = myclock(h, m);
            // struct myclock pclock = nclock - myclock(0, 15);
            myclock pclock = myclock(h, m - 15);
            if (m - 15 < 0)
            {
                pclock.m += 60;
                pclock.h -= 1;
            }
            if (pclock.h < 0)
                pclock.h += 24;
            
            // build clock: cnow & nclock
            int hhigh = h / 10;
            for (i = 0; i < 9; ++i)
                cnow[0][i] = pic[hhigh][i];
            int hlow = h % 10;
            for (i = 0; i < 9; ++i)
                cnow[1][i] = pic[hlow][i];
            int mhigh = m / 10;
            for (i = 0; i < 9; ++i)
                cnow[2][i] = pic[mhigh][i];
            int mlow = m % 10;
            for (i = 0; i < 9; ++i)
                cnow[3][i] = pic[mlow][i];

            // build clock: cpre & pclock
            hhigh = pclock.h / 10;
            for (i = 0; i < 9; ++i)
                cpre[0][i] = pic[hhigh][i];
            hlow = pclock.h % 10;
            for (i = 0; i < 9; ++i)
                cpre[1][i] = pic[hlow][i];
            mhigh = pclock.m / 10;
            for (i = 0; i < 9; ++i)
                cpre[2][i] = pic[mhigh][i];
            mlow = pclock.m % 10;
            for (i = 0; i < 9; ++i)
                cpre[3][i] = pic[mlow][i];

            // check now & cnow
// for (i = 0; i < 3; ++i)
// cout << s[i];

// cin >> t;
            int flag = 1;
            for (i = 0; i < 4; ++i)
            {
                for (j = 0; j < 9; ++j)
                {
                    if ((now[i][j] == 1 && cnow[i][j] != 1) || (now[i][j] == 2 && cnow[i][j] != 2))
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                    break;
            }
            if (flag == 0)
                continue;

            // check pre & cpre
            for (i = 0; i < 4; ++i)
            {
                for (j = 0; j < 9; ++j)
                {
                    if ((pre[i][j] == 1 && cpre[i][j] != 1) || (pre[i][j] == 2 && cpre[i][j] != 2))
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                    break;
            }
            if (flag == 0)
                continue;
            cnt += 1;
//             cout << h << " " << m << " " << pclock.h << " " << pclock.m << endl;
// for (i = 0; i < 4; ++i)
// {
//     for (j = 0; j < 9; ++j)
//         cout << now[i][j];
//     cout << endl;
// }
// for (i = 0; i < 4; ++i)
// {
//     for (j = 0; j < 9; ++j)
//         cout << cnow[i][j];
//     cout << endl;
// }
// for (i = 0; i < 4; ++i)
// {
//     for (j = 0; j < 9; ++j)
//         cout << pre[i][j];
//     cout << endl;
// }
// for (i = 0; i < 4; ++i)
// {
//     for (j = 0; j < 9; ++j)
//         cout << cpre[i][j];
//     cout << endl;
// }
            if (cnt != 1)
                break;
            theh = h; them = m;
        }
        if (cnt != 1 & cnt != 0)
            break;
        }
        // cout << cnt << endl;
        if (cnt == 1)
        {
            cout << theh / 10 << theh % 10 << them / 10 << them % 10 << endl;
        }
        else
            cout << "Not Sure\n";
    }
    return 0;
}
