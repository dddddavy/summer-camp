#include <iostream>
#include <string>
using namespace std;

int isthat(string s)
{
    int i, j;
    i = 0; j = s.size()-1;
    for (; i < j; ++i,--j)
    {
        if (s[i] != s[j])
            return 0;
    }
    return 1;
}


int main(int argc, char const *argv[])
{
    string s;
    int num, i, l, flag, j;
    cin >> num;
    for (j = 0; j < num; ++j)
    {
        cin >> s;
        flag = 0;
        for (l = s.size(); l >= 1; --l)
        {
            for (i = 0; i <= s.size() - l; ++i)
            if (isthat(s.substr(i, i + l)))
            {
                cout << s.substr(i, i + l) << endl;
                flag = 1;
                break;
            }
            if (flag)
                break;
        }
    }
    return 0;
}
