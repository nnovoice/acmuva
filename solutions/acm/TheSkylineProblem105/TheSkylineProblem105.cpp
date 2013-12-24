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
    int curHeight = 0;
    int nextHeight = 0;

    /// print x -> the co-ordinate where the max(curHeight, nextHeight)
    /// print y -> the max(curHeight, nextHeight)
    /// If there is an intersection (detect via the change in the buildings height
    /// and the two buildings intersect at the same height, then the intersection
    /// must be printed
    int x = leftmost - 1;
    while (x <= rightmost) {
        curHeight = skyline[x][top];

        /// traverse until there is a height change
        for (int i = x + 1; i <= rightmost; ++i) {
            nextHeight = skyline[i][top];
            if (curHeight != nextHeight) {
                x = i - 1;
                break;
            }
        }

        if (x == rightmost) break;

        /// do we have an intersection?
        if (skyline[x][bot] > 0 &&
            skyline[x + 1][bot] > 0 &&
            skyline[x][bot] == skyline[x + 1][bot])
        {
            printf("%d ", x);
            printf("%d ", skyline[x][bot]);

            printf("%d ", x + 1);
            printf("%d ", skyline[x + 1][top]);

            x += 1;
        }
        else if (skyline[x][top] > skyline[x + 1][top]) {
             if (skyline[x][bot] == skyline[x + 1][top] &&
                 skyline[x][bot] > 0)
            {
                printf("%d ", x);
                printf("%d ", skyline[x][bot]);
            }
            else {
                printf("%d ", x);
                if (skyline[x + 1][top] == 0 && skyline[x + 1][bot] == 0)
                    printf("%d ", 0);
                else
                    printf("%d ", skyline[x][top]);
            }

            x += 1;
        }
        else {
            printf("%d ", x + 1);
            printf("%d ", skyline[x + 1][top]);

            x += 2;
        }
    }
    printf("\n");
}

int main()
{
    int x = 0, height = 0, right = 0;
    int leftmost = 0;
    int rightmost = 0;
    int buildingNum = 0;
    //PrintBuildings(1, 30);
    while (scanf("%d %d %d", &x, &height, &right) != EOF) {
        if (buildingNum == 0) leftmost = x;
        ++buildingNum;
        for (int i = x; i <= right; ++i) {
            if (skyline[i][top] < height) {
                skyline[i][bot] = skyline[i][top];
                skyline[i][top] = height;
            }
            else {
                if (skyline[i][bot] < height)
                    skyline[i][bot] = height;
            }
        }
    }
    rightmost = right + 2; // to find the end
    ///PrintBuildings(leftmost, rightmost);
    TraceSkyline(leftmost, rightmost);
    return 0;
}
