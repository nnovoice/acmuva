#include <stdio.h>

int skyline[5005][2];
const int top = 1;
const int bot = 0;

void PrintBuildings(int leftmost, int rightmost) {
    for (int i = leftmost; i <= rightmost; ++i) {
        printf("%5d", skyline[i][top]);
    }
    printf("\n");
    for (int i = leftmost; i <= rightmost; ++i) {
        printf("%5d", skyline[i][bot]);
    }
    printf("\n");
    for (int i = leftmost; i <= rightmost; ++i) {
        printf("%5d", i);
    }
    printf("\n");
}

void TraceSkyline(int leftmost, int rightmost) {
    for (int i = leftmost; i <= rightmost; ++i) {
        printf("%5d", skyline[i][top]);
    }
    printf("\n");
    for (int i = leftmost; i <= rightmost; ++i) {
        printf("%5d", skyline[i][bot]);
    }
    printf("\n");
    for (int i = leftmost; i <= rightmost; ++i) {
        printf("%5d", i);
    }
    printf("\n");
}

int main()
{

    int left = 0, height = 0, right = 0;
    int leftmost = 0;
    int rightmost = 0;
    int buildingNum = 0;
    //PrintBuildings(1, 30);
    while (scanf("%d %d %d", &left, &height, &right) != EOF) {
        if (buildingNum == 0) leftmost = left;
        ++buildingNum;
        for (int i = left; i <= right; ++i) {
            if (skyline[i][top] < height) {
                skyline[i][top] = height;
            }
            else {
                if (skyline[i][bot] < height)
                    skyline[i][bot] = height;
            }
        }
    }
    rightmost = right + 2; // to find the end
    PrintBuildings(leftmost, rightmost);
    return 0;
}
