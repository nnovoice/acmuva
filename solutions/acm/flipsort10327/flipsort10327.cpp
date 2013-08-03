/* UVa 10327 - Flip Sort */
#include <iostream>
using namespace std;

int main()
{
    int nums[1000] = {0};
    int num = 0;
    int temp = 0;
    int nFlips = 0;

    while (cin >> num) {
        for (int i = 0; i < num; ++i) {
            cin >> nums[i];
        }

        nFlips = 0;

        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < (num - 1); ++j) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    ++nFlips;
                }
            }
        }

        cout << "Minimum exchange operations : " << nFlips << endl;
    }
    return 0;
}
