#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUMBERS = 1001;
const int MAX2DNUMBERS = MAXNUMBERS * MAXNUMBERS;
int numbers[MAXNUMBERS];
int sums[MAX2DNUMBERS];

int GetClosestNum (int num, int nNumbers)
{
    int left = 0;
    int right = nNumbers - 1;
    int mid = 0;
    while (left < right) {
        mid = left + ((right - left) / 2);
        if (num == sums[mid]) {
            cout << "Debug: " << " sums[" << mid << "]= " << sums[mid] << endl << endl;
            return sums[mid];
        }
        else if (num < sums[mid]) {
            cout << "Debug: " << " sums[" << mid << "]= " << sums[mid] << endl << endl;
            right = mid - 1;
        }
        else {
            cout << "Debug: " << " sums[" << mid << "]= " << sums[mid] << endl << endl;
            left = mid + 1;
        }
    }

    int newMid = mid;
    if (sums[newMid == num]) {
        return sums[newMid];
    }
    else if (sums[mid] < num) {
        for (int i = mid + 1; i < nNumbers; ++i) {
            newMid = i - 1;
            if (sums[i] > num) {
                break;
            }
        }
    }
    else {
        for (int i = mid - 1; i >= 0; --i) {
            newMid = i;
            if (sums[i] < num) {
                break;
            }
        }
    }
    return sums[newMid];
}

int main()
{
    int nIntegers = 0;
    int mQueries = 0;
    int index = 0;
    int query = 0;
    int closestSum = 0;
    int totalSumIntegers = 0;
    int caseNum = 0;

    while (cin >> nIntegers) {
        if (nIntegers == 0) break;

        cout << "Case " << ++caseNum << ":" << endl;
        for (int i = 0; i < nIntegers; ++i) {
            cin >> numbers[i];
        }

        index = 0;
        for (int i = 0; i < nIntegers; ++i) {
            for (int j = (i + 1); j < nIntegers; ++j) {
                sums[index] = numbers[i] + numbers[j];
                cout << "Debug: " << "index= " << index << " sum= " << sums[index] << endl;
                ++index;
            }
        }

        totalSumIntegers = (nIntegers * (nIntegers - 1)) / 2;

        sort (sums, sums + totalSumIntegers);

        index = 0;
        for (int i = 0; i < nIntegers; ++i) {
            for (int j = (i + 1); j < nIntegers; ++j) {
                cout << "Debug: " << "index= " << index << " sum= " << sums[index] << endl;
                ++index;
            }
        }

        cin >> mQueries;
        for (int j = 0; j < mQueries; ++j) {
            cin >> query;
            closestSum = GetClosestNum(query, totalSumIntegers);
            cout << "Debug: " << "query = " << query << " " << " Closest num= ";
            cout << "Closest sum to " << query << " is " << closestSum << "." << endl;
        }
    }

    return 0;
}
