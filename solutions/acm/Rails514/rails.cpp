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
    int coachNum = 1;
    int coachToMove = 0;
    bool haveCoachesToProcess = true;

    queue<int> expectedOrder;
    stack<int> stationCoaches;

    //freopen ("C:\\data\\personal\\programming\\acm\\input_files\\Rails514\\input.txt", "r", stdin);

    while (cin >> nCoaches) {
        if (nCoaches == 0) break;

        if (haveCoachesToProcess == false)
            cout << endl;

        while (1) {
            haveCoachesToProcess = true;
            coachNum = 1;

            while (expectedOrder.empty() == false)
                expectedOrder.pop();

            while (stationCoaches.empty() == false)
                stationCoaches.pop();

            for (int i = 0; i < nCoaches; ++i) {
                cin >> coach;

                if (coach == 0) {
                    haveCoachesToProcess = false;
                    //cout << endl;
                    break;
                }

                expectedOrder.push(coach);
            }

            if (haveCoachesToProcess == false)
                break;

            while (expectedOrder.empty() == false) {
                coachToMove = expectedOrder.front();
                expectedOrder.pop();

                for (; coachNum <= coachToMove; ++coachNum) {
                    stationCoaches.push(coachNum);
                }

                if (stationCoaches.empty() == false && stationCoaches.top() == coachToMove) {
                    stationCoaches.pop();
                }
                else {
                    break;
                }
            }

            if (stationCoaches.empty() == true) {
                if (expectedOrder.empty() == true)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}
