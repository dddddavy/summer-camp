#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int res[15][10][10][10][10];
int map[10][10];

int doit(int n, int x1, int y1, int x2, int y2)
{
    if (res[n][x1][y1][x2][y2] != -1)
        return res[n][x1][y1][x2][y2];

    
    
}

int main(int argc, char const *argv[])
{
    int n, total;

    memset(res, -1, sizeof(res));
    memset(map, 0, sizeof(map));

    cin >> n;
    for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
    {
        cin >> map[i][j];
        total += map[i][j];
    }

    int m = doit(n, 0, 0, 7, 7);    


    
    return 0;
}
