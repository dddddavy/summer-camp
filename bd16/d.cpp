#include <iostream>
#include <set>
using namespace std;

int a[200];

int main(int argc, char const *argv[])
{
    multiset<int> s;
    int n, i, total;
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    total = 0;
    while(s.size() != 1)
    {
        auto p1 = s.begin();
        auto p2 = s.begin();
        p2++;
        int val = *p1;
        val += *p2;
        total += val;
        // cout << val << " ";
        s.erase(p1);
        s.erase(p2);
        s.insert(val);
    }

    cout << total << endl;

    return 0;
}
