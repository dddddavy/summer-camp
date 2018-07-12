#include <iostream>
#include <cstring>
using namespace std;

int h[200], dp[200], pd[200];

int main(int argc, char const *argv[])
{
    int k, n, i;
    cin >> k;
    for (int ki = 0; ki < k; ++ki)
    {
        cin >> n;
        for (i = 0; i < n; ++i)
            cin >> h[i];
        dp[0] = 1;
        for (i = 1; i < n; ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
                if (h[i] < h[j])
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        pd[n - 1] = 1;
        for (i = n - 2; i >= 0; --i)
        {
            pd[i] = 1;
            for (int j = n - 1; j > i; --j)
                if (h[j] > h[i])
                    pd[i] = max(pd[i], pd[j] + 1);
        }
        int MAX = 0;
        for (i = 0; i < n; ++i)
        {
            MAX = max(MAX, dp[i]);
            MAX = max(MAX, pd[i]);
        }
        cout << MAX << endl;
    }
    return 0;
}
