#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXNUMAGES 2000001
char ages[MAXNUMAGES];

int main()
{
    int nAges = 0;
    int age = 0;
    int lastAgeIndex = 0;
    while (scanf("%d", &nAges) != EOF) {
        if (nAges == 0) break;
        for (int i = 0; i < nAges; ++i) {
            scanf("%d", &age);
            ages[i] = (char)age;
        }
        sort (ages, ages + nAges);
        lastAgeIndex = nAges - 1;
        for (int i = 0; i <= lastAgeIndex; ++i) {
            if (i < lastAgeIndex)
                printf("%d ", ages[i]);
            else
                printf("%d", ages[i]);
        }
        printf("\n");
    }
    return 0;
}
