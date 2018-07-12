#include <stdio.h>
#include <string.h>

int dp[4000][13000];
int v[4000], w[4000];

int f(int n, int m)
{
    if (n <= 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int tmp = f(n - 1, m), p = 0;
    if (m >= w[n] && n > 0)
        p = f(n - 1, m - w[n]) + v[n];
    if (p > tmp)
        tmp = p;
    dp[n][m] = tmp;
    return tmp;
}


int main(int argc, char const *argv[])
{
    int n, m, i, j;
    int p, q;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%d %d", &w[i], &v[i]);
    // memset(dp, -1, sizeof(dp));

    // printf("%d\n", f(n, m));
    for (i = 1; i <= n; ++i)
        dp[i][0] = 0;
    for (i = 0; i < w[1]; ++i)
        dp[1][i] = 0;
    for (i = w[1]; i <= m; ++i)
        dp[1][i] = v[1];
    
    for (i = 2; i <= n; ++i)
    {
        for (j = 0; j <= m; ++j)
        {
            if (j >= w[i])
                p = dp[i - 1][j - w[i]] + v[i];
            else
                p = 0;
            q = dp[i - 1][j];
            if (p < q)
                p = q;
            dp[i][j] = p;
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
