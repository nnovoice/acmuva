#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const unsigned int MAXNUMBERS = 20000;

int main()
{
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int z = 0;
    unsigned int a[MAXNUMBERS] = {0};
    unsigned int b[MAXNUMBERS] = {0};
    int index = 0;

    while (scanf("%u", &z) != EOF) {
        index = 0;
        memset(a, 0, sizeof(a[0]) * MAXNUMBERS);
        memset(b, 0, sizeof(b[0]) * MAXNUMBERS);

        for (y = 2 * z; y != z; --y) {
            if (((z * y) % (y - z)) == 0) {
                x = (z * y) / (y - z);
                a[index] = x;
                b[index] = y;
                ++index;
            }
        }

        printf("%u\n", index);
        for (int i = (index - 1); i >= 0; --i) {
            printf("%u/%u = %u/%u + %u/%u\n", 1, z, 1, a[i], 1, b[i]);
        }
    }

    return 0;
}
