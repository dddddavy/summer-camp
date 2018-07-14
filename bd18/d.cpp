#include <iostream>
#include <cstring>
using namespace std;

int d[11000];
int dp[10010][510];

int main(int argc, char const *argv[])
{
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        cin >> d[i];
    memset(dp, 0, sizeof(dp));
    dp[0][1] = d[0];
    for (i = 1; i < n; ++i)
    {
        for (j = 1; j < min(i + 1, m); ++j)
            dp[i][j] = dp[i-1][j-1] + d[i];
        int t = min(i, m);
        for (j = 1; j <= t; ++j)
        {
            for (int k = 0; k <= j; ++k)
            dp[i][0] = max(dp[i][0], dp[i-j][k]);
        }
    }
    cout << dp[n-1][0] << endl;
    return 0;
}
