#include <stdio.h>

const int MAXBUILDINGSCOORDINATE = 10005;
const int MAXZOOMEDBUILDINGS = MAXBUILDINGSCOORDINATE * 5;
int skyline[MAXZOOMEDBUILDINGS][2];
const int top = 1;
const int bot = 0;

void PrintBuildings(int leftmost, int rightmost) {
    int left = leftmost * 5;
    int right = rightmost * 5;
    for (int i = left; i <= right; ++i) {
        if ((i % 5) == 0)
            printf("%5d", skyline[i][top]);
    }
    printf("\n");
    for (int i = left; i <= right; ++i) {
        if ((i % 5) == 0)
            printf("%5d", skyline[i][bot]);
    }
    printf("\n");
    for (int i = left; i <= right; ++i) {
        if ((i % 5) == 0)
            printf("%5d", (i/5));
    }
    printf("\n");
}

void PrintZoomedBuildings(int leftmost, int rightmost) {
    int left = leftmost * 5;
    int right = rightmost * 5;
    printf("ZoomedLeft=%4d ZoomedRight=%4d\n", left, right);
    for (int i = left; i <= right; ++i) {
        printf("%4d", skyline[i][top]);
    }
    printf("\n");
    for (int i = left; i <= right; ++i) {
        printf("%4d", skyline[i][bot]);
    }
    printf("\n");
    for (int i = left; i <= right; ++i) {
        printf("%4d", i);
    }
    printf("\n");
}

/// The central idea is to store a zoomed in version of the building: 5 times zoomed in :)
/// That will help in determining the common skyline connection between buildings which is
/// otherwise difficult to find out :)
void TraceSkyline(int leftmost, int rightmost) {
    int zoomedLeft = leftmost * 5;
    int zoomedRight = rightmost * 5;
    int x = zoomedLeft;
    int nextX = 0;
    int prevX = 0;

    //printf("Debug: ZoomedLeft=%4d ZoomedRight=%4d\n", zoomedLeft, zoomedRight);

    while (x <= zoomedRight) {
        /// travel to the first non-zero height building
        while (skyline[x][top] == 0) ++x;

        if (x > zoomedRight) break;
        //printf("Debug: %d %d\n", x, skyline[x][top]);

        prevX = x - 1;
        if (x <= zoomedRight) {
            //printf("Debug: inside prevX %d %d\n", x, skyline[x][top]);
            if (skyline[prevX][top] == 0)
                printf ("%d %d ", x/5, skyline[x][top]);
            //x += 1;
        }

        nextX = x + 1;
        if (skyline[x][top] != skyline[nextX][top]) {
            //printf("Debug: inside NOTEQ nextX=%d %d\n", nextX, skyline[nextX][top]);
            printf ("%d %d ", nextX/5, skyline[nextX][top]);
            x += 2;
        }
        else {
            x += 1;
        }
        //printf("Debug: near while loop end: %d %d\n", x, skyline[x][top]);
    }

    printf("\n");
}

int main()
{
    int left = 0, height = 0, right = 0;
    int zoomedInLeft = 0, zoomedInRight = 0;
    int leftmost = 0;
    int rightmost = 0;
    int buildingNum = 0;

    while (scanf("%d %d %d", &left, &height, &right) != EOF) {
        if (buildingNum == 0) leftmost = left;
        ++buildingNum;
        zoomedInLeft  = left * 5;
        zoomedInRight = right * 5;
        for (int i = zoomedInLeft; i <= zoomedInRight; ++i) {
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
    rightmost = right + 1; // to find the end
    //PrintBuildings(leftmost, rightmost);
    //PrintZoomedBuildings(leftmost, rightmost);
    TraceSkyline(leftmost, rightmost);
    return 0;
}
