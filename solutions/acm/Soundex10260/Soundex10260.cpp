/* UVa 10260 - Soundex*/
#include <stdio.h>
#include <string.h>
#define MAXCHARS 20

int main()
{
    char input[MAXCHARS] = {'\0'};
    char output[MAXCHARS] = {'\0'};
    int idx = 0;
    int lastChar = ' ';
    while (scanf("%s", input) != EOF) {
        memset(output, '\0', sizeof(output));
        idx = 0;
        for (int i = 0; input[i] != '\0'; ++i) {
            if (lastChar != input[i]) {
                switch(input[i]) {
                // A, E, I, O, U, H, W, and Y are not represented in Soundex coding
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'H':
                case 'W':
                case 'Y':
                    break;
                case 'B':
                case 'F':
                case 'P':
                case 'V':
                    if (lastChar != 'B' && lastChar != 'F' && lastChar != 'P' && lastChar != 'V')
                        output[idx++] = '1';
                        //printf ("1");
                    break;
                //2 represents C, G, J, K, Q, S, X,  or Z
                case 'C':
                case 'G':
                case 'J':
                case 'K':
                case 'Q':
                case 'S':
                case 'X':
                case 'Z':
                    if (lastChar != 'C' && lastChar != 'G' && lastChar != 'J' && lastChar != 'K' &&
                        lastChar != 'Q' && lastChar != 'S' && lastChar != 'X' && lastChar != 'Z')
                        output[idx++] = '2';
                        //printf("2");
                    break;
                //3 represents D or T
                case 'D':
                case 'T':
                    if (lastChar != 'D' && lastChar != 'T')
                        output[idx++] = '3';
                        //printf ("3");
                    break;
                // 4 represents L
                case 'L':
                    output[idx++] = '4';
                    //printf ("4");
                    break;
                //5 represents M or N
                case 'M':
                case 'N':
                    if (lastChar != 'M' && lastChar != 'N')
                        output[idx++] = '5';
                        //printf ("5");
                    break;
                // 6 represents R
                case 'R':
                    output[idx++] = '6';
                    //printf ("6");
                    break;
                }
            }
            lastChar = input[i];
        }
        if (idx > 0)
            printf("%s", output);

        printf("\n");
    }
    return 0;
}
