#include <iostream>
#include <cstring>
using namespace std;

int nailao[100010];
int dp[100010];
int mymax[100010];

int main(int argc, char const *argv[])
{
    int t, ti, n, i;
    cin >> t;
    for (ti = 0; ti < t; ++ti)
    {
        cin >> n;
        memset(dp, 0, sizeof(int)*n);
        for (i = 0; i < n; ++i)
        {
            cin >> nailao[i];
            mymax[i] = 0;
        }
        dp[0] = mymax[0] = nailao[0];
        dp[1] = mymax[1] = nailao[1];
        for (i = 2; i < n; ++i)
        {
            dp[i] = mymax[i-2]+nailao[i];
            mymax[i]= max(dp[i], dp[i-1]);
        }
        cout << mymax[n-1] << endl;

    }
    return 0;
}
