#include <iostream>
#include <cstring>
using namespace std;


char map[9][9];
int used[9];
int n, k, sum;

void doit(int l, int p)
{
    if (p == k)
    {
        sum += 1;
        return;
    }
    if (l >= n)
        return;
    for (int j = l; j < n; ++j)
    for (int i = 0; i < n; ++i)
    {
        if (map[j][i] == '#' && used[i] == 0)
        {
            used[i] = 1;
            doit(j + 1, p + 1);
            used[i] = 0;
        }
        // doit(l + 1, p);
    }
}

int main(int argc, char const *argv[])
{
    int i;
    cin >> n >> k;
    while (n != -1)
    {
        for (i = 0; i < n; ++i)
            cin >> map[i];
        memset(used, 0, sizeof(used));
        sum = 0;
        doit(0, 0);
        cout << sum << endl;
        cin >> n >> k;
    }
    return 0;
}
