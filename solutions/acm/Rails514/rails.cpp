/* UVa 514 - Rails*/
#define MAXCOACHES 1001
#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    int nCoaches = 0;
    int coach = 0;
    //int coachesInOrder[MAXCOACHES] = {0};
    int coachNum = 1;
    int coachToMove = 0;
    bool haveCoachesToProcess = true;

//    for (int i = 0; i < MAXCOACHES; ++i) {
//        coachesInOrder[i] = i;
//    }

    queue<int> expectedOrder;
    stack<int> stationCoaches;

    freopen ("C:\\data\\personal\\programming\\acm\\input_files\\Rails514\\input.txt", "r", stdin);

    while (cin >> nCoaches) {
        if (nCoaches == 0) break;

        haveCoachesToProcess = true;
        coachNum = 1;

        for (int i = 0; i < nCoaches; ++i) {
            cin >> coach;

            if (coach == 0) {
                haveCoachesToProcess = false;
                cout << endl;
                break;
            }

            expectedOrder.push(coach);
        }

        if (haveCoachesToProcess == false)
            continue;

        while (expectedOrder.empty() == false) {
            coachToMove = expectedOrder.front();
            expectedOrder.pop();

            for (; coachNum <= coachToMove; ++coachNum) {
                stationCoaches.push(coachNum);
            }

            if (stationCoaches.empty() == true) {
                cout << "No" << endl;
                break;
            }

            if (stationCoaches.top() == coachToMove) {
                stationCoaches.pop();
            }
            else {
                cout << "No" << endl;
                break;
            }
        }

        if (expectedOrder.empty() == true && coachNum == nCoaches) {
                cout << "Yes" << endl;
        }
    }
}
