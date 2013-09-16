#include <stdio.h>

using namespace std;

int main()
{
    int nCases = 0;
    int answer = 0;
    int n = 0;
    int digit = 0;
    scanf("%d", &nCases);
    for (int i = 0; i < nCases; ++i) {
        scanf("%d", &n);
        answer = (((((n * 567)/ 9) + 7492) * 235) / 47) - 498;
        //printf("Debug: answer so far= %d\n", answer);
        if (answer < 0) {
            answer = 0 - answer;
        }
        for (int j = 0; j < 2; ++j) {
            digit = answer % 10;
            answer -= digit;
            answer /= 10;
        }
        printf("%d\n", digit);
    }
    return 0;
}
