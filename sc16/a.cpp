#include <stdio.h>

int main()
{
    float n, result;
    scanf("%f", &n);
    if (n >= 0 && n < 5)
        result = 2.5 - n;
    else if (n >= 5 && n < 10)
        result = 2 - 1.5 * (n - 3) * (n - 3);
    else if (n >= 10 && n < 20)
        result = n / 2 - 1.5;
    
    printf("%.3f\n", result);
    return 0;
}