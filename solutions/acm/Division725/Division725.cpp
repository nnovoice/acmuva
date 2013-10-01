#include <stdio.h>

bool AreDigitsUnique(int a, int b)
{
    int positionCounts[10] = {0};
    int digit = 0;
    int numbers[2] = {a, b};
    //printf("Debug: %d %d\n", numbers[0], numbers[1]);
    for (unsigned int i = 0; i < 2; ++i) {
        while (numbers[i] > 0) {
            digit = numbers[i] % 10;
            //printf("Debug: digit=%d\n", digit);
            if (positionCounts[digit] == 0) {
                positionCounts[digit] = 1;
            }
            else {
                break;
            }
            //numbers[i] -= digit;
            numbers[i] /= 10;
            //printf("Debug: number=%d i=%d\n", numbers[i], i);
        }
    }

    //printf("Debug: positionCounts[%d]=%d\n", 0, positionCounts[0]);
    if (positionCounts[0] > 1) {
        return false;
    }

    for (unsigned int i = 1; i < 10; ++i) {
        //printf("Debug: positionCounts[%d]=%d\n", i, positionCounts[i]);
        if (positionCounts[i] != 1)
            return false;
    }

    return true;
}

int main()
{
//    printf("%d", AreDigitsUnique(12345, 6789));
//    printf("%d", AreDigitsUnique(13579, 2468));
//    printf("%d", AreDigitsUnique(24681, 3579));
    int n = 0;
    int i = 0;
    int nSolutions = 0;
    bool uniqueDigits = false;
    int nCases = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;

        ++nCases;
        if (nCases > 1) {
            printf("\n\n");
        }
        nSolutions = 0;
        for (i = 12345; i < 98765; ++i) {
            if ((i % n) == 0) {
                uniqueDigits = AreDigitsUnique(i, (i/n));
                if (uniqueDigits) {
                    //printf ("a=%d b=%05d\n", i, (i/n));
                    ++nSolutions;
                    if (nSolutions > 1)
                        printf("\n");
                    printf ("%d / %05d = %d", i, (i/n), n);
                }
            }
        }
        if (nSolutions == 0) {
            printf("There are no solutions for %d.", n);
        }

    }
    return 0;
}
