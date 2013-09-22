#include <iostream>

using namespace std;
const int NUMMONTHS = 12;
int main()
{
    int required[NUMMONTHS] = {0};
    int available[NUMMONTHS] = {0};
    int nProblemsAvailableAtStart = 0;
    int currentlyAvailableProblems = 0;
    int caseNum = 0;

    while (cin >> nProblemsAvailableAtStart) {
        if (nProblemsAvailableAtStart < 0) break;

        for (int i = 0; i < NUMMONTHS; ++i) {
            cin >> available[i];
        }

        for (int i = 0; i < NUMMONTHS; ++i) {
            cin >> required[i];
        }

        cout << "Case " << ++caseNum << ":" << endl;
        currentlyAvailableProblems = nProblemsAvailableAtStart;
        for (int i = 0; i < NUMMONTHS; ++i) {
            //cout << "Debug: " << "required[" << i << "]= " << required[i] << " available= "<< currentlyAvailableProblems << endl;
            if (required[i] > currentlyAvailableProblems) {
                cout << "No problem. :(" << endl;
            }
            else {
                cout << "No problem! :D" << endl;
                currentlyAvailableProblems -= required[i];
                currentlyAvailableProblems += available[i];
            }
        }
    }
    return 0;
}
