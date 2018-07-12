#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

void doit(int n)
{
    int index = 0;
    string fn[40];

    if (n == 0)
    {
        cout << "ROOT\n";
        if (s[0] == 'f')
        {
            fn[index] = s;
            index += 1;
        } else {
            cout << "|     ";
            cout << s << endl;
            doit(1);
        }
    }
    while (1)
    {
        cin >> s;
        if (s[0] == 'f')
        {
            fn[index] = s;
            index += 1;
        } else if (s[0] == 'd') {
            for (int i = 0; i <= n; ++i)
                cout << "|     ";
            // cout << "test:" << n;
            cout << s << endl;
            doit(n + 1);
        }
        // else if (s[0] == ']')
        //     return;
        else break;
    }
    sort(fn, fn + index);
    for (int i = 0; i < index; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << "|     ";
        cout << fn[i] << endl;
    }
}


int main(int argc, char const *argv[])
{
    int cnt = 1;
    while (1)
    {
        cin >> s;
        if (s[0] == '#')
            break;
        cout << "DATA SET " << cnt << ":\n";
        cnt += 1;
        doit(0);
        cout << "\n";
    }
    return 0;
}
