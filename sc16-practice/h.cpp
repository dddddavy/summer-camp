#include <stdio.h>
#include <string.h>

int left[200], right[200], parent[200];

int main(int argc, char const *argv[])
{
    int t, m, n, x, y, z, type;
    scanf("%d", &t);
    for (int ti = 0; ti < t; ++ti)
    {
        scanf("%d %d", &n, &m);
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for (int i = 0; i < n; ++i)
            parent[i] = -1;
        for (int ni = 0; ni < n; ++ni)
        {
            scanf("%d %d %d", &x, &y, &z);
            left[x] = y;
            right[x] = z;
            if (y != -1)
                parent[y] = x;
            if (z != -1)
                parent[z] = x;
        }
        for (int i = 0; i < n; ++i)
        {
            // printf("%d %d %d\n", left[i], right[i], parent[i]);
        }
        for (int mi = 0; mi < m; ++mi)
        {
            scanf("%d", &type);
            if (type == 1)
            {
                scanf("%d %d", &x, &y);
                int px = parent[x];
                int py = parent[y];

                if (left[px] == x)
                    left[px] = y;
                else
                    right[px] = y;
                
                if (right[py] == y)
                    right[py] = x;
                else
                    left[py] = y;

                parent[x] = py;
                parent[y] = px;

            }
            else
            {
                scanf("%d", &x);
                while (left[x] != -1)
                    x = left[x];
                printf("%d\n", x);
            }
        }

    }
    return 0;
}
