#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    int list[1000];
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    int l, end = 0;
    l = s.find('-');
    while (l != -1)
    {
        string temp = "";
        if (s[l - 1] >= s[l + 1])
        {
            list[end] = l;
            s.replace(l, 1, temp);
            l = s.find('-');
            end += 1;
            continue;
        }
        if (p3 == 1)
        {
            for (char c = s[l - 1] + 1; c != s[l + 1]; ++c)
            {
                for (int i = 0; i < p2; ++i)
                {
                    if (p1 == 1)
                    {
                        if (c >= 'A' && c <= 'Z')
                            temp += c + 'a' - 'A';
                        else
                            temp += c;
                    }
                    else if (p1 == 2)
                    {
                        if (c >= 'a' && c <= 'z')
                            temp += c + 'A' - 'a';
                        else
                            temp += c;
                    }
                    else
                        temp += '*';
                }
            }
        }
        else
        {
            for (char c = s[l + 1] - 1; c != s[l - 1]; --c)
            {
                for (int i = 0; i < p2; ++i)
                {
                    if (p1 == 1)
                    {
                        if (c >= 'A' && c <= 'Z')
                            temp += c + 'a' - 'A';
                        else
                            temp += c;
                    }
                    else if (p1 == 2)
                    {
                        if (c >= 'a' && c <= 'z')
                            temp += c + 'A' - 'a';
                        else
                            temp += c;
                    }
                    else
                        temp += '*';
                }
            }
        }
        s.replace(l, 1, temp);
        // cout << s << endl;
        l = s.find('-');
    }
    // cout << s << endl;
    // cout << end << " " << list[0] << endl;
    for (int i = 0; i < end; ++i)
    {
        // cout << list[i];
        s.insert(list[i], "-");
    }
    cout << s << endl;
    return 0;
}
