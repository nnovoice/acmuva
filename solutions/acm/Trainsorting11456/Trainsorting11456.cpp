#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAXTRAINCARS = 2001;
int LDS[MAXTRAINCARS]; /// Longest Decreasing Subsequence

int GetTrainLength(const list<int>& trainCars, const int& nTrainCars)
{
    vector<int> carWeights (trainCars.begin(), trainCars.end());
    int nMaxTrainLength = 0;
    int curMaxLength = 0;
    for (int i = 0; i < nTrainCars; ++i) {
        LDS[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (carWeights[i] < carWeights[j]) {
                curMaxLength = LDS[j] + 1;
                if (LDS[i] < curMaxLength) {
                    LDS[i] = curMaxLength;
                    if (nMaxTrainLength < curMaxLength) {
                        nMaxTrainLength =  curMaxLength;
                    }
                }
            }
        }
    }
    return nMaxTrainLength;
}

int main()
{
    int nTestCases = 0;
    list<int> trainCars;
    int nTrainCars = 0;
    int carWeight = 0;

    int nLengthWhenCarAddedToFront = 0;
    int nLengthWhenCarAddedToEnd = 0;
    int nMaxTrainLength = 0;

    cin >> nTestCases;
    for (int nTestCase =  0; nTestCase < nTestCases; ++nTestCase) {
        trainCars = list<int>();
        nLengthWhenCarAddedToFront = 0;
        nLengthWhenCarAddedToEnd = 0;
        nMaxTrainLength = 0;

        cin >> nTrainCars;
        for (int i = 0; i < nTrainCars; ++i) {
            cin >> carWeight;

            trainCars.push_front(carWeight);
            nLengthWhenCarAddedToFront = GetTrainLength(trainCars, (i + 1));
            trainCars.pop_front();

            trainCars.push_back(carWeight);
            nLengthWhenCarAddedToEnd = GetTrainLength(trainCars, (i + 1));
            trainCars.pop_back();

            if (nLengthWhenCarAddedToFront > nLengthWhenCarAddedToEnd) {
                trainCars.push_front(carWeight);
                nMaxTrainLength = nLengthWhenCarAddedToFront;
            }
            else {
                trainCars.push_back(carWeight);
                nMaxTrainLength = nLengthWhenCarAddedToEnd;
            }
        }

        cout << nMaxTrainLength << endl;
    }

    return 0;
}
