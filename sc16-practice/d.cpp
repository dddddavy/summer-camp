#include <iostream>
#include <cstring>
using namespace std;


int main(int argc, char const *argv[])
{
    int map[44][44];
    memset(map, 0, sizeof(map));
    int n, num;
    cin >> n;
    num = 2 * n - 1;

    int i = 0, j = n - 1, cnt = 1, ni, nj;
    map[i][j] = 1;

    while (cnt != num * num)
    {
        ni = (i + num - 1) % num;
        nj = (j + 1) % num;
        if (map[ni][nj] != 0)
            i = (i + 1) % num;
        else
        {
            i = ni;
            j = nj;
        }
        cnt += 1;
        map[i][j] = cnt;
    }

    for (i = 0; i < num; ++i)
    {
        for (j = 0; j < num; ++j)
            cout << map[i][j] << " ";
        cout << endl;
    }


    return 0;
}
