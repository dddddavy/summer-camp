#include <iostream>
#include <string>
using namespace std;

string s[200];

int main(int argc, char const *argv[])
{
    int cnt = 0;
    while (cin >> s[cnt])
        cnt += 1;
    for (int i = cnt - 1; i > 0; --i)
        cout << s[i] << " ";
    cout << s[0] << endl;
    return 0;
}
