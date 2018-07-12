#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s[1010];

int main(int argc, char const *argv[])
{
    char str[2000];
    cin >> str;
    int len = strlen(str);
    int end = 0, i, cur_len = 1;
    for (i = 0; i < len; ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    i = 1;
    char now = str[0];
    while (i != len)
    {
        if (now == str[i])
            cur_len += 1;
        else
        {
            printf("(%c,%d)", now, cur_len);
            now = str[i];
            cur_len = 1;
        }
        i += 1;
    }

    printf("(%c,%d)\n", now, cur_len);
    
    return 0;
}
