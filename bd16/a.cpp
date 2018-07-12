#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double weight, price;
    char quick;
    while (cin >> weight >> quick)
    {
        if (weight <= 1)
            price = 0.8;
        else
            price = 0.8 + (weight - 1) * 0.5;
        if (quick == 'y')
            price += 2;
        cout << price << endl;
    }
    return 0;
}
