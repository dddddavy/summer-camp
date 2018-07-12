#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int a[2000];
    memset(a, 0x01234567, sizeof(a));
    char * ptr;
    ptr = (char *)a;
    char t = a[0], s = a[1], r = a[2];
    printf("%x %x %x\n", t, s, r);
    return 0;
}
