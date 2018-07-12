#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    string s, max = "", min(200, 'c');
    while (cin >> s)
    {
        if (s.length() > max.length())
            max = s;
        if (s.length() < min.length())
            min = s;
    }

    cout << max << endl << min << endl;

    return 0;
}
