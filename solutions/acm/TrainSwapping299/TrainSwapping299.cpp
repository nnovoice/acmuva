#define MAXCOACHES 51
#include <iostream>

using namespace std;

// bubble sort
int TrainSwaps(int coaches[MAXCOACHES], int nCoaches)
{
    int nSwaps = 0;
    int temp = 0;
    for (int i = 0; i < nCoaches; ++i) {
        for (int j = 0; j < (nCoaches - 1); ++j) {
            if (coaches[j] > coaches[j + 1]) {
                temp = coaches[j];
                coaches[j] = coaches[j + 1];
                coaches[j + 1] = temp;
                ++nSwaps;
            }
        }
    }
    return nSwaps;
}

int main()
{
    int coaches[MAXCOACHES] = {0};
    int nCases = 0;
    int nCoaches = 0;

    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> nCoaches;
        for (int j = 0; j < nCoaches; ++j) {
            cin >> coaches[j];
        }
        cout << "Optimal train swapping takes " << TrainSwaps(coaches, nCoaches) << " swaps." << endl;
    }
    return 0;
}
