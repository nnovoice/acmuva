/* UVa 12004 - Bubble Sort */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> swapCount;
int numPermutations;

void bubbleSort(vector<int>& v)
{
    int* nums = new int[v.size()];
    for (unsigned int i = 0; i < v.size(); ++i)
        nums[i] = v[i];

    int temp = 0;
    int nFlips = 0;

    for (unsigned int i = 0; i < v.size(); ++i) {
        for (unsigned int j = 0; j < (v.size() - 1); ++j) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                ++nFlips;
            }
        }
    }

    //cout << "# swaps : " << nFlips << endl;
    //cout << nFlips << endl;
    swapCount[nFlips] += 1;
    delete [] nums;
}

void generatePermutationsOfNum(int num) {
    typedef std::vector<int> V; //<or_any_class>
    V v;
    numPermutations = 0;

    for(int i=1; i <= num; ++i)
        v.push_back(i);

    do{
        cout << endl;
        for(int i = 0; i < num;++i)
            std::cout<<v[i]<<", ";
        //cout << endl;
        ++numPermutations;
        bubbleSort(v);
    }
    while(std::next_permutation(v.begin(),v.end()));
}

int main()
{
    for (int i = 1; i < 6; ++i) {
        swapCount.erase(swapCount.begin(), swapCount.end());
        cout << "# permutations= " << numPermutations << ",Swap counts for " << i << ":,";
        generatePermutationsOfNum(i);
        map<int, int>::iterator endIter = swapCount.end();
        for (map<int, int>::iterator startIter = swapCount.begin(); startIter != endIter; ++ startIter) {
            cout << (*startIter).first << "~~" << (*startIter).second << ",";
        }
        cout << endl;
    }

//    unsigned int nCases = 0;
//    unsigned int num = 0;
//    unsigned int totalSwaps = 0;
//
//    cin >> nCases;
//
//    for (unsigned int i = 0; i < nCases; ++i) {
//        cin >> num;
//
//        cout << "Case " << (i + 1) << ": ";
//
//        totalSwaps = (num * (num - 1)) / 2;
//        if ((totalSwaps % num) == 0) {
//            cout << (totalSwaps / num);
//        }
//        else {
//            cout << totalSwaps << "/" << num;
//        }
//        cout << endl;
//    }
    return 0;
}
