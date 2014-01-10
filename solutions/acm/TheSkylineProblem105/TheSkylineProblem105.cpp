#include <stdio.h>

const int ZOOMFACTOR = 3;
const int MAXBUILDINGSCOORDINATE = 10010;
const int MAXZOOMEDBUILDINGS = MAXBUILDINGSCOORDINATE * ZOOMFACTOR;
int skyline[MAXZOOMEDBUILDINGS];
int coordinates[MAXZOOMEDBUILDINGS];
int index;

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
        while (skyline[x] == 0 && x <= zoomedRight) {
            ++x;
        }

        if (x > zoomedRight) break;

        prevX = x - 1;
        if (skyline[prevX] == 0) {
            coordinates[index] = x/ZOOMFACTOR; ++index;
            coordinates[index] = skyline[x]; ++index;
        }


        nextX = x + 1;
        if (skyline[x] != skyline[nextX]) {
            coordinates[index] = nextX/ZOOMFACTOR; ++index;
            coordinates[index] = skyline[nextX]; ++index;
            x += 2;
        }
        else {
            x += 1;
        }
    }

    //if (index > 0) {
    printf("%d", coordinates[0]);
    for (int i = 1; i < index; ++i)
        printf(" %d", coordinates[i]);
    //}

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
            if (skyline[i] < height) {
                skyline[i] = height;
            }
        }
    }
    rightmost = right + 1; // to find the end

    TraceSkyline(leftmost, rightmost);

    return 0;
}
