#include <iostream>
#include <queue>
using namespace std;


int main(int argc, char const *argv[])
{
    int t, n;
    // cin >> t;
    t = 1;
    for (int ti = 0; ti < t; ++ti)
    {
        priority_queue<int> que;
        cin >> n;
        // n = 1;
        int type, num;
        for (int i = 0; i < n; ++i)
        {
            cin >> type;
            if (type == 1)
            {
                cin >> num;
                que.push(-num);
            }
            else
            {
                cout << -que.top() << endl;
                que.pop();
            }
        }
    }
    return 0;
}

