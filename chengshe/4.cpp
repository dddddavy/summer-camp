#include <iostream>
using namespace std;

int w[20], s[20];

int main(int argc, char const *argv[])
{
    int thes, i, j, total, MAX = 0, first, last, xiaohao;
    cin >> thes;
    for (i = 0; i < 15; ++i)
    {
        cin >> w[i] >> s[i];
    }
    for (i = 0; i < (1 << 15); ++i)
    {
        total = xiaohao = 0;
        first = last = 0;
        for (j = 0; j < 15; ++j)
        {
            if (i & (1 << j))
            {
                xiaohao += s[j];
                total += w[j];
                if (j < 10)
                    first += 1;
                else
                    last += 1;
                if (first > 5)
                    break;
            }
        }
        if (j != 15 || first > last || xiaohao > thes)
            continue;
        MAX = max(MAX, total);
    }
    cout << MAX << endl;

    return 0;
}
