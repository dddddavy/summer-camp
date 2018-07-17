#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int i, j;
    int map[5][5];
    int MIN[5], MAX[5];
    for (i=0;i<5;++i)
    for (j=0;j<5;++j)
        cin >> map[i][j];
    for (i=0;i<5;++i)
    {
        MAX[i]=0;
        MIN[i]= 1 << 30;
    }
    for (i=0;i<5;++i)
    {
        for (j=0;j<5;++j)
        {
            MAX[i] = max(MAX[i], map[i][j]);
            MIN[i] = min(MIN[i], map[j][i]);
        }
    }
    for (i=0;i<5;++i)
    {
        for (j=0;j<5;++j)
        {
            if (map[i][j] == MAX[i] && map[i][j] == MIN[j])
            {
                cout << i + 1 << " " << j + 1 << " " << map[i][j] << endl;
                return 0;
            }
        }
    }
    cout << "not found\n";
    return 0;
}
