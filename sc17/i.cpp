#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    long long a, b, c, k, i, p, c0, b0, k0;
    while (1)
    {
        cin >> a >> b >> c >> k;
        if (a + b + c + k == 0)
            break;
        for (i = k; i >= 0; --i)
            if (c % (1 << i) == 0)
                break;
        p = 1 << i;         // p 是最大公约数
        b = b - a;
        while (b < 0)
            b += (1 << k);
        if (b % p != 0)
        {
            cout << "FOREVER\n";
            continue;
        }
        c0 = c / p;
        b0 = b / p;
        k0 = k - i;
        // cout << c0 << " " << b0 << " " << k0 << " ";
        long long ans = 1;
        for (i = 0; i < k0 - 1; ++i)
        {
            // ans = ans << 1;
            ans = ans * ans;
            ans *= c0;
            ans = ans & ((1 << k0) - 1);
        }
        // cout << ans << endl;
        ans *= b0;
        ans = ans & ((1 << k0) - 1);
        cout << ans << endl;
    }
    return 0;
}
