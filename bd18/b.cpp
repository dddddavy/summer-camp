#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int o2s[30], s2o[30], used[30];


int main(int argc, char const *argv[])
{
    string s, o, need;
    cin >> s >> o;
    cin >> need;
    int i, flag = 1;
    for (i = 0; i < 26; ++i)
    {
        o2s[i] = -1;
        s2o[i] = -1;
        used[i] = 0;
    }
    for (i = 0; i < s.size(); ++i)
    {
        if (used[s[i]-'A'] != 0)
        {
            if (s2o[s[i]-'A'] != o[i]-'A')
            {
                flag = 0;
                // cout << "sssssssssss";
                // cout << i << " " << s[i] << " " << o[i];
                // cout << " " << s2o[s[i]-'A'];
                break;
            }
        }
        used[s[i]-'A'] = 1;
        o2s[o[i]-'A'] = s[i] - 'A';
        s2o[s[i]-'A'] = o[i] - 'A';
    }
    for (i = 0; i < 26; ++i)
        if (o2s[i] == -1)
        {
            flag = 0;
            // cout << "zzzzzzzz";
            break;
        }
    if (flag == 0)
    {
        cout << "Failed" << endl;
        return 0;
    }
    for (i = 0; i < need.size(); ++i)
        printf("%c", s2o[need[i]-'A']+'A');
    cout << endl;
    return 0;
}
