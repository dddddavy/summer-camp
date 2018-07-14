#include <iostream>
#include <cmath>
using namespace std;

// int a[200000]

int main(int argc, char const *argv[])
{
    int n, i, j;
    cin >> n;
    // for (i = 0; i < n; ++i)
    int cnt = 1;
    int prime = 2;
    while (1)
    {
        if (cnt == n)
            break;
        prime += 1;
        int flag = 1;
        for (i = 2; i <= sqrt(prime); ++i)
            if (prime % i == 0)
            {
                flag = 0;
                break;
            }
        if (flag)
            cnt += 1;
    }
    cout << prime << endl;

    return 0;
}
