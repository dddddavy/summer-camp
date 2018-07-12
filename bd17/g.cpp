#include <iostream>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, k, p;
    map<int, int> m;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        if (n == 1)
        {
            cin >> k >> p;
            m.insert(make_pair(p, k));
        }
        else if (n == 3)
        {
            if (m.empty())
            {
                cout << 0 << endl;
                continue;
            }
            auto ptr = m.begin();
            cout << ptr->second << endl;
            m.erase(ptr);
        }
        else if (n == 2)
        {
            if (m.empty())
            {
                cout << "0\n";
                continue;
            }
            auto ptr = m.end();
            ptr--;
            cout << ptr->second << endl;
            m.erase(ptr);
        }
        
    }
    return 0;
}
