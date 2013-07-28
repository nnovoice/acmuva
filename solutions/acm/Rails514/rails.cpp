/* UVa 514 - Rails*/
#define MAXCOACHES 1001
#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

void makeEmpty(queue<int>& expectedOrder, stack<int>& stationCoaches)
{
    while (expectedOrder.empty() == false)
        expectedOrder.pop();

    while (stationCoaches.empty() == false)
        stationCoaches.pop();
}

int main()
{
    int nCoaches = 0;
    int coach = 0;
    int coachNum = 1;
    int coachToMove = 0;
    bool haveCoachesToMove = true;

    queue<int> expectedOrder;
    stack<int> stationCoaches;

    //freopen ("C:\\data\\personal\\programming\\acm\\input_files\\Rails514\\input.txt", "r", stdin);

    while (cin >> nCoaches) {
        if (nCoaches == 0) break;

//        if (haveCoachesToMove == false)
//            cout << endl;

        while (1) {
            haveCoachesToMove = true;
            coachNum = 1;

            makeEmpty(expectedOrder, stationCoaches);

            for (int i = 0; i < nCoaches; ++i) {
                cin >> coach;

                if (i == 0 && coach == 0) {
                    haveCoachesToMove = false;
                    cout << endl;
                    break;
                }

                expectedOrder.push(coach);
            }

            if (haveCoachesToMove == false)
                break;

            while (expectedOrder.empty() == false) {
                coachToMove = expectedOrder.front();
                expectedOrder.pop();

                while (coachNum <= coachToMove) {
                    stationCoaches.push(coachNum);
                    ++coachNum;
                }

                if (stationCoaches.empty() == false && stationCoaches.top() == coachToMove) {
                    stationCoaches.pop();
                }
                else {
                    break;
                }
            }

            if ((stationCoaches.empty() == true) && (expectedOrder.empty() == true)) {
                 cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}
