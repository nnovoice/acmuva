/* UVa 10107 - What is the Median?*/
#define MAXNUMBERS 10000
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long numbers[MAXNUMBERS] = {0};
	unsigned int count = 0;
	unsigned int medianIndex = 0;
	unsigned long median = 0;

	while (cin >> numbers[count++]) {
		sort (numbers, numbers + count);
		medianIndex = count / 2;
		if (count & 1) {
			median = numbers[medianIndex];
		}
		else {
			median = numbers[medianIndex];
			median += numbers[medianIndex - 1];
			median /= 2;
		}
		cout << median << endl;
	}
	return 0;
}
