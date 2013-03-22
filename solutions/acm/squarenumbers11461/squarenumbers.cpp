#define MAX 100000
#define NUMSQUARENUMBERS 316
#include <iostream>
using namespace std;

int getSquareIndex(int* squares, int num) {
	for (int i = 1;  i <= NUMSQUARENUMBERS; ++i) {
		if (squares[i] > num) {
			return i - 1;
		}
	}
}

int getSquareIndexUsingBinSearch(int* squares, int num) {
	//[] = 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 186, 225, 256, 289, 324, 361, 400
	//[] = 1, 2, 3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20

	int low = 1;
	int high = NUMSQUARENUMBERS;
	int mid = 0;
	while (low < high) {
		mid = low + ((high - low) / 2);
		if (squares[mid] == num) {
			return mid;
		}
		else if (squares[mid] < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	if (squares[mid] > num)
		return mid - 1;
	return mid;
}

int main() {
	int squares[NUMSQUARENUMBERS + 1];
	squares[0] = 0;
	for (int i = 1; i*i <= MAX; ++i) {
		squares[i] = i * i;
	}
    
	int a = 0;
	int b = 0;
	int aIndex = 0;
	int bIndex = 0;
	int diff = 0;
	while (cin >> a >> b) {
		aIndex = getSquareIndex(squares, a);
		bIndex = getSquareIndex(squares, b);
		diff = aIndex - bIndex;
		if (diff < 0)
			diff = 0 - diff;
		cout << diff << endl;
	}
}

