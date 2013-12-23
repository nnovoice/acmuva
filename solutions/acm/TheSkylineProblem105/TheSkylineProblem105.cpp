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
    int left = leftmost - 1;
    while (left <= rightmost) {
        /// traverse until a building is found
        while (left <= rightmost && skyline[left][bot] == 0 && skyline[left][top] == 0) {
            ++left;
            continue;
        }

        if (left == rightmost) break;

        printf("%d ", left);
        printf("%d ", skyline[left][top]);

        curHeight = skyline[left][top];

        /// traverse until there is a height change
        for (int i = left + 1; i <= rightmost; ++i) {
            nextHeight = skyline[i][top];
            if (curHeight != nextHeight) {
                left = i;
                break;
            }
        }

        /// do we have an intersection?
        if (skyline[left][bot] > 0 &&
            skyline[left + 1][bot] > 0 &&
            skyline[left][bot] == skyline[left + 1][bot])
        {
            printf("%d ", left);
            printf("%d ", skyline[left][bot]);
        }
        else {
            if (skyline[left][top] > skyline[left + 1][top]) {
                printf("%d ", left);
                printf("%d ", skyline[left][bot]);
            }
            else {
                printf("%d ", left + 1);
                printf("%d ", skyline[left + 1][bot]);
            }
        }

        left += 1;
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
    PrintBuildings(leftmost, rightmost);
    TraceSkyline(leftmost, rightmost);
    return 0;
}
