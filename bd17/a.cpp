#include <iostream>
#include <algorithm>
using namespace std;

int x0, y0;
struct point
{
    int x, y;
};
point a[200];

bool cmp(point p1, point p2)
{
    int d1 = (p1.x - x0) * (p1.x - x0) + (p1.y - y0) * (p1.y - y0);
    int d2 = (p2.x - x0) * (p2.x - x0) + (p2.y - y0) * (p2.y - y0);

    if (d1 != d2)
        return d1 < d2;
    
    if (p1.x != p2.x)
        return p1.x < p2.x;
    
    return p1.y < p2.y;
}

int main(int argc, char const *argv[])
{
    cin >> x0 >> y0;
    int n, i;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;

    sort(a, a + n, cmp);
    for (i = 0; i < n - 1; ++i)
        cout << "(" << a[i].x << "," << a[i].y << "), ";
    cout << "(" << a[i].x << "," << a[i].y << ")\n";
    
    return 0;
}
