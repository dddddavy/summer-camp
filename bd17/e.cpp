#include <iostream>
#include <cstring>
using namespace std;

int d[200], v[200], dp[200];
int n, k;
int last_use, MAX, now;

int main(int argc, char const *argv[])
{
    int t, i;
    cin >> t;
    for (int ti = 0; ti < t; ++ti)
    {
        cin >> n >> k;
        for (i = 0; i < n; ++i)
            cin >> d[i];
        for (i = 0; i < n; ++i)
            cin >> v[i];
        MAX = 0;
        memset(dp, 0, sizeof(dp));
        // doit(0);
        dp[0] = v[0];
        for (i = 1; i < n; ++i)
        {
            dp[i] = v[i];
            for (int j = 0; j < i; ++j)
                if (d[i] - d[j] > k)
                    dp[i] = max(dp[i], dp[j] + v[i]);
        }
        for (i = 0; i < n; ++i)
            MAX = max(MAX, dp[i]);

        cout << MAX << endl;
    }

    return 0;
}
