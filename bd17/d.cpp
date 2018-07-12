#include <iostream>
#include <string>
using namespace std;

int a[40];
int MIN, now;
string s;

void doit(int n)
{    
    if (now >= MIN)
        return;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i)
        sum += a[i + 1];

    if (sum == 0 || sum == s.size())
    {
        MIN = min(MIN, now);
        return;
    }
    if (n == s.size())
        return;
    a[n] = 1 - a[n];
    a[n - 1] = 1 - a[n - 1];
    a[n + 1] = 1 - a[n + 1];
    now += 1;
    doit(n + 1);
    now -= 1;
    a[n] = 1 - a[n];
    a[n - 1] = 1 - a[n - 1];
    a[n + 1] = 1 - a[n + 1];
    doit(n + 1);
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            a[i + 1] = s[i] - '0';
            sum += a[i + 1];
        }
        // cout <<sum < endl;
        if (sum == 0)
            break;
        MIN = s.size() + 5;
        now = 0;
        doit(0);
        if (MIN == s.size() + 5)
            cout << "impossible\n";
        else
            cout << MIN << endl;
    }

    return 0;
}

