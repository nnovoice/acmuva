#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUMBERS = 1001;
const int MAX2DNUMBERS = MAXNUMBERS * MAXNUMBERS;
long int numbers[MAXNUMBERS];
long int sums[MAX2DNUMBERS];

int GetClosestNumBinSearch (int num, int nNumbers)
{
    int left = 0;
    int right = nNumbers - 1;
    int mid = 0;
    while (left < right) {
        mid = left + ((right - left) / 2);
        if (num == sums[mid]) {
            //cout << "Debug: " << " left= " << left << " right= " << right << " sums[" << mid << "]= " << sums[mid] << endl;
            return sums[mid];
        }
        else if (num < sums[mid]) {
            //cout << "Debug: " << " left= " << left << " right= " << right << " sums[" << mid << "]= " << sums[mid] << endl;
            right = mid - 1;
        }
        else {
            //cout << "Debug: " << " left= " << left << " right= " << right << " sums[" << mid << "]= " << sums[mid] << endl;
            left = mid + 1;
        }
    }
    return sums[mid];
}

int GetClosestNum (long int num, int nNumbers)
{
    int prevIndex = 0;
    long int diff1 = 0;
    long int diff2 = 0;
    for (int i = 0; i < nNumbers; ++i) {
        if (sums[i] <= num)
            prevIndex = i;
        else
            break;
    }

    if ((prevIndex + 1) == nNumbers)
        return sums[prevIndex];

    diff1 = num - sums[prevIndex];
    diff2 = sums[prevIndex + 1] - num;
    return (diff1 < diff2) ? sums[prevIndex] : sums[prevIndex + 1];

}

int main()
{
    int nIntegers = 0;
    int mQueries = 0;
    int index = 0;
    long int query = 0;
    long int closestSum = 0;
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
                //cout << "Debug: " << "index= " << index << " sum= " << sums[index] << endl;
                ++index;
            }
        }

        totalSumIntegers = (nIntegers * (nIntegers - 1)) / 2;

        sort (sums, sums + totalSumIntegers);

//      // Completely debug code below
//        index = 0;
//        for (int i = 0; i < nIntegers; ++i) {
//            for (int j = (i + 1); j < nIntegers; ++j) {
//                cout << "Debug: " << "index= " << index << " sum= " << sums[index] << endl;
//                ++index;
//            }
//        }

        cin >> mQueries;
        for (int j = 0; j < mQueries; ++j) {
            cin >> query;
            closestSum = GetClosestNum(query, totalSumIntegers);
            //cout << "Debug: " << "query = " << query << " " << " Closest num= ";
            cout << "Closest sum to " << query << " is " << closestSum << "." << endl;
        }
    }

    return 0;
}
