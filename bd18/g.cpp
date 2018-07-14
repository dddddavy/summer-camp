#include <iostream>
#include <stack>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, first_block = 1, i;
    int a[1100];
    cin >> n;
    while (1)
    {
        if (n == 0)
            break;
        int f = 0;
        for (i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                cin >> n;
                f = 1;
                cout << endl;
                break;
            }
        }
        if (f == 1)
            continue;
        
        // algorithm start
        stack<int> s;
        while (!s.empty())
            s.pop();
        int num = 1, flag = 1;
        for (i = 0; i < n; ++i)
        {
            if (s.empty())
            {
                if (num > n)
                {
                    flag = 0;
                    break;
                }
                s.push(num);
                ++num;
            }
            if (a[i] > s.top())
            {
                while (a[i] > s.top())
                {
                    if (num > n)
                    {
                        flag = 0;
                        break;
                    }
                    s.push(num);
                    num += 1;
                }
                if (flag == 0)
                    break;
                s.pop();
            }
            else if (a[i] == s.top())
                s.pop();
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            cout << "No\n";
        else
            cout << "Yes\n";
        // end
    }
    return 0;
}
