#include <iostream>
#include <cstdio>
using namespace std;

int ball[100], hp[100];
int dp[1000][500];

int main(int argc, char const *argv[])
{
    int n, m, k, i, j;
    // cin >> n >> m >> k;
    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i < k; ++i)
        // cin >> ball[i] >> hp[i];
        scanf("%d %d", &ball[i], &hp[i]);
    
    for (i = ball[0]; i <= n; ++i)
    for (j = hp[0]; j <= m; ++j)
    {
        // if (i >= ball[0] && j >= hp[0])
        dp[i][j] = 1;
        // else
            // dp[i][j][0] = 0;
    }

    for (int t = 1; t < k; ++t)
    {
        // for (i = ball[t]; i <= n; ++i)
        // for (j = hp[t]; j <= m; ++j)
        for (i = n; i >= ball[t]; --i)
        for (j = m; j >= hp[t]; --j)
        {
            // if (i >= ball[t] && j >= hp[t])
            dp[i][j] = max(dp[i][j], dp[i-ball[t]][j-hp[t]] + 1);
            // else
            //     dp[i][j][t] = dp[i][j][t-1];
        }
    }

    int MAX = 0, index = 0;
    for (j = 0; j <= m; ++j)
    {
        if (dp[n][j] == dp[n][m])
        {
            MAX = dp[n][j];
            index = j;
            break;
        }
    }
    // cout << MAX << " " << m- index << endl;
    printf("%d %d\n", MAX, m-index);

    return 0;
}
