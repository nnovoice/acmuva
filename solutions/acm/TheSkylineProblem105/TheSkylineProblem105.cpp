#include <stdio.h>

const int ZOOMFACTOR = 5;
const int MAXBUILDINGSCOORDINATE = 10010;
const int MAXZOOMEDBUILDINGS = MAXBUILDINGSCOORDINATE * ZOOMFACTOR;
int skyline[MAXZOOMEDBUILDINGS][2];
const int top = 1;
const int bot = 0;

void PrintBuildings(int leftmost, int rightmost) {
    int left = leftmost * ZOOMFACTOR;
    int right = rightmost * ZOOMFACTOR;
    for (int i = left; i <= right; ++i) {
        if ((i % ZOOMFACTOR) == 0)
            printf("%5d", skyline[i][top]);
    }
    printf("\n");
    for (int i = left; i <= right; ++i) {
        if ((i % ZOOMFACTOR) == 0)
            printf("%5d", skyline[i][bot]);
    }
    printf("\n");
    for (int i = left; i <= right; ++i) {
        if ((i % ZOOMFACTOR) == 0)
            printf("%5d", (i/ZOOMFACTOR));
    }
    printf("\n");
}

void PrintZoomedBuildings(int leftmost, int rightmost) {
    int left  = leftmost  * ZOOMFACTOR;
    int right = rightmost * ZOOMFACTOR;
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
    int zoomedLeft  = leftmost  * ZOOMFACTOR;
    int zoomedRight = rightmost * ZOOMFACTOR;
    int x = zoomedLeft;
    int nextX = 0, prevX = 0;

    while (x <= zoomedRight) {
        /// travel to the first non-zero height building
        while (skyline[x][top] == 0 && x <= zoomedRight) {
            ++x;
        }

        if (x > zoomedRight) break;

        prevX = x - 1;
        if (skyline[prevX][top] == 0)
            printf ("%d %d ", x/ZOOMFACTOR, skyline[x][top]);

        nextX = x + 1;
        if (skyline[x][top] != skyline[nextX][top]) {
            printf ("%d %d ", nextX/ZOOMFACTOR, skyline[nextX][top]);
            x += 2;
        }
        else {
            x += 1;
        }
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
        zoomedInLeft  = left  * ZOOMFACTOR;
        zoomedInRight = right * ZOOMFACTOR;
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

    TraceSkyline(leftmost, rightmost);

    return 0;
}
