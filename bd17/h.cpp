#include <iostream>
#include <cstring>
using namespace std;

unsigned map[1010][1010];

int main(int argc, char const *argv[])
{
    int n, m, x, start, end, len;
    // memset(map, -1, sizeof(map));
    cin >> n >> m >> x;
    for (int i = 1; i <= n; ++i)
    {
        // map[i][i] = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                map[i][j] = 0;
            else
                map[i][j] = 1 << 30;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> start >> end >> len;
        map[start][end] = len;
    }
    for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    if (map[i][j] > map[i][k] + map[k][j])
        map[i][j] = map[i][k] + map[k][j];
    
    unsigned MAX = 0;
    for (int i = 1; i <= n; ++i)
        MAX = max(MAX, map[i][x] + map[x][i]);
    // if ( < )
    cout << MAX << endl;


    return 0;
}
