#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, char const *argv[])
{
    int x, y, i, j, cnt = 0;
    float t;
    cin >> x >> y;
    if (x > y)
    {
        i = x;
        x = y;
        y = i;
    }
    for (i = x; i <= y; ++i)
    {
        if (i == 1)
            continue;
        t = sqrt(i);
        // t = i - 1;
        int flag = 1;
        for (j = 2; j <= t; ++j)
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        cnt += flag;
    }
    cout << cnt << endl;
    return 0;
}
