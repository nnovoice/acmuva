#include <stdio.h>

int main()
{
    int A = 0, B = 0, C = 0;
    int occurrences[2] = {0};
    int count = 0;
    int index = 0;
    while (scanf("%d %d %d", &A, &B, &C) != EOF) {
        occurrences[0] = 0;
        occurrences[1] = 0;

        count = 0;
        index = 0;

        occurrences[A] += 1;
        occurrences[B] += 1;
        occurrences[C] += 1;

        if (occurrences[0] == 3 || occurrences[1] == 3) {
            printf("*\n");
        }
        else {
            count = occurrences[0];
            index = 0;
            if (count > occurrences[1]) {
                count = occurrences[1];
                index = 1;
            }

            if (index == A) {
                printf("A\n");
            }
            else if (index == B) {
                printf("B\n");
            }
            else {
                printf("C\n");
            }
        }
    }
    return 0;
}
