#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXBUILDINGS = 5002;
int skyline[MAXBUILDINGS];
int buildingHeights[MAXBUILDINGS];
vector<int> buildingIDs[MAXBUILDINGS];

void PrintBuildings(int leftmost, int rightmost)
{
    vector<int>* pBuildingIDsList = 0;
    vector<int>::iterator li;
    vector<int>::iterator le;
    for (int i = leftmost; i <= rightmost; ++i) {
        printf("%5d", skyline[i]);
    }
    printf("\n");
    printf("Building IDs:\n");
    for (int i = leftmost; i <= rightmost; ++i) {
        pBuildingIDsList = &buildingIDs[i];
        printf("Height=%5d: {IDs=", skyline[i]);

        li = pBuildingIDsList->begin();
        le = pBuildingIDsList->end();
        for(; li != le; ++li) {
            printf("%d,", *li);
        }
        printf("}\n");
    }
    printf("\n");
}

bool GetMaxHeightOfCommonBuildings (vector<int>* pVX, vector<int>* pVNextX)
{
    int maxHeight = 0;
    vector<int>::iterator vxi = pVX->begin();
    vector<int>::iterator vxe = pVX->end();
    vector<int>::iterator vNextIter;
    for(; vxi != vxe; ++vxi) {
        vNextIter = find (pVNextX->begin(), pVNextX->end(), *vxi);
        if (vNextIter != pVNextX->end()) {
            if (maxHeight < buildingHeights[*vxi])
                maxHeight = buildingHeights[*vxi];
        }
    }
    return maxHeight;
}

bool HaveCommonBuildings (vector<int>* pVX, vector<int>* pVNextX)
{
    vector<int>::iterator vxi = pVX->begin();
    vector<int>::iterator vxe = pVX->end();
    for(; vxi != vxe; ++vxi) {
        if (find (pVNextX->begin(), pVNextX->end(), *vxi) != pVNextX->end()) {
            return true;
        }
    }
    return false;
}

void TraceSkyline(int leftmost, int rightmost)
{
    vector<int>* pVX = 0;
    vector<int>* pVNextX = 0;
    int x = leftmost - 1;
    int nextX = 0;
    bool shareCommonBuildings = false;
    int maxHeightOfCommonBuildings = 0;

    while (x <= rightmost) {
        if (skyline[x] == 0) ++x;
        else break;
    }

    if (x <= rightmost) {
        printf("%d %d ", x, skyline[x]);
        ++x;
    }

    while (x <= rightmost) {
        nextX = x + 1;
        if (nextX > rightmost) break;

        pVX = &buildingIDs[x];
        pVNextX = &buildingIDs[nextX];
        shareCommonBuildings = HaveCommonBuildings(pVX, pVNextX);
        maxHeightOfCommonBuildings = GetMaxHeightOfCommonBuildings(pVX, pVNextX);

        if (skyline[x] == skyline[nextX]) {
            if (shareCommonBuildings) {
                printf("%d %d ", x, maxHeightOfCommonBuildings);
                ++x;
            }
            else {
                printf("%d %d ", x, 0);
                ++x;
            }
        }
        else {
            if (shareCommonBuildings) {
                printf("%d %d ", x, maxHeightOfCommonBuildings);
                printf("%d %d ", nextX, skyline[nextX]);
                x += 2;
            }
            else {
                printf("%d %d ", x, 0);
                ++x;
            }
        }

        if (skyline[x] == 0) {
            while (x <= rightmost) {
                if (skyline[x] == 0) ++x;
                else break;
            }
            if (x <= rightmost) {
                printf("%d %d ", x, skyline[x]);
                ++x;
            }
        }
    }
    printf("%d\n", 0);
}

int main()
{
    int left = 0, height = 0, right = 0;
    int leftmost = 0;
    int rightmost = 0;
    int buildingID = 0;

    while (scanf("%d %d %d", &left, &height, &right) != EOF) {
        if (buildingID == 0) leftmost = left;
        ++buildingID;

        buildingHeights[buildingID] = height;

        for (int i = left; i <= right; ++i) {
            if (skyline[i] < height) {
                skyline[i] = height;
            }
            buildingIDs[i].push_back(buildingID);
        }
    }

    rightmost = right + 1; // to find the end
    PrintBuildings(leftmost, rightmost);
    TraceSkyline(leftmost, rightmost);
    return 0;
}
