#include <stdio.h>
#include <string.h>

const int MAXLEN = 101;
int main()
{
    char input[MAXLEN] = {'\0'};
    int inputLen = 0;
    int groupLen = 0;
    int numGroups = 0;
    int i = 0, j = 0, k = 0;
    char temp = ' ';
    while (scanf("%d", &numGroups) != EOF) {
        if (numGroups == 0) break;
        //memset(input, '\0', sizeof(input));
        scanf("%s", input);
        inputLen = strlen(input);
        groupLen = inputLen / numGroups;
        //printf("Debug: groupLen= %d, inputLen= %d, numGroups= %d\n", groupLen, inputLen, numGroups);
        for (i = 0; i < numGroups; ++i) {
            j = i * groupLen;
            k = j + (groupLen - 1);
            //printf("Debug: j= %d, k= %d\n", j, k);
            for (; j < k; ++j, --k) {
                temp = input[j];
                input[j] = input[k];
                input[k] = temp;
            }
        }

        printf("%s\n", input);
    }
    return 0;
}
