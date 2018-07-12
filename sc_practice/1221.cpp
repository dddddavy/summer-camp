#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


long long dp[260][260];

int main(int argc, char const *argv[])
{
    int n, i;
    memset(dp, 0, sizeof(dp));
    for (i = 1; i < 250; ++i)
    {
        dp[0][i] = 1;
        dp[i][1] = 1;
        dp[i][2] = 1 - (i % 2);
    }
    for (int l = 3; l < 250; ++l)
    {
        for (int n = l; n < 250; ++n)
        {
            int t = n / l;
            for (i = 1; i <= t; ++i)
            {
                dp[n][l] += dp[n - i * l + l - 2][l - 2];
            }
        }
    }
    cin >> n;
    while (n != 0)
    {
        cout << n << " ";
        int sum = 0;
        for (i = 1; i <= n; ++i)
        {
            // cout << dp[n][i] << " ";
            sum += dp[n][i];
        }
        // cout << sum << endl;
        printf("%lld\n", sum);
        cin >> n;
    }

    return 0;
}
