#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    int num, i, max_age = 0, min_age = 999, age[10000], flag[10000];
    string id[10000];
    cin >> num;
    for (i = 0; i < num; ++i)
    {
        cin >> id[i] >> age[i];
        flag[i] = 0;
        if (age[i] > max_age)
            max_age = age[i];
        if (age[i] < min_age)
            min_age = age[i];
    }

    if (max_age >= 60)
    {
        // old first
        for (int j = max_age; j >= 60; --j)
        {
            for (i = 0; i < num; ++i)
                if (age[i] == j)
                {
                    cout << id[i] << endl;
                    flag[i] = 1;
                }
        }
    }
    for (i = 0; i < num; ++i)
        if (flag[i] == 0)
            cout << id[i] << endl;


    return 0;
}
