#include <iostream>
#include <cstring>
using namespace std;

char pre[50], in[50];

void doit(char * p, char * n, int len)
{
    if (len == 0)
        return;
    if (len == 1)
    {
        cout << p[0];
        return;
    }
    int i;
    for (i = 0; i < len; ++i)
        if (n[i] == p[0])
            break;
    doit(p + 1, n, i);
    doit(p + i + 1, n + i + 1, len - i - 1);
    cout << p[0];
}

int main(int argc, char const *argv[])
{
    while (cin >> pre >> in)
    {
        doit(pre, in, strlen(pre));
        cout << "\n";
    }
    return 0;
}
