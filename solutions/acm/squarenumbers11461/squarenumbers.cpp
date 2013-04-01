#define MAX 100000
#define NUMSQUARENUMBERS 316
#include <iostream>
#include <cstdio>
using namespace std;

int getSquareIndex(int* squares, int num) {
	for (int i = 1;  i <= NUMSQUARENUMBERS; ++i) {
		if (squares[i] > num) {
			return i - 1;
		}
	}
	return -1;
}

bool isSquareNumber(int* squares, int num) {
	int low = 1;
	int high = NUMSQUARENUMBERS;
	int mid = 0;
	while (low < high) {
		mid = low + ((high - low) / 2);
		if (squares[mid] == num) {
			return true;
		}
		else if (squares[mid] < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	
	return false;
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
	
	if (squares[mid] > num) {
		return mid - 1;
	}
	
	return mid + 1;
}

void constructSquares(int* squares, int nMaxSquares) {
	squares[0] = 0;
	for (int i = 1; i <= nMaxSquares; ++i) {
		squares[i] = i * i;
	}
}

int getNumSquaresBetween(int* squares, int a, int b) {
	bool isSquareNumA = isSquareNumber(squares, a);
	bool isSquareNumB = isSquareNumber(squares, b);
	
	int aIndex = getSquareIndexUsingBinSearch(squares, a);
	int bIndex = getSquareIndexUsingBinSearch(squares, b);
	
	int diff = aIndex - bIndex;
	if (diff < 0)
		diff = 0 - diff;

	if (diff != 0) {
		diff -= 1; // index 1, index 3 yields diff = 2, but # of squares b/w them is 1.
		diff += 2;
		/*if (isSquareNumA)
			diff += 1; 
		if (isSquareNumB)
			diff += 1;*/
	}
	else {
		int numDiff = a - b;
		if (numDiff != 0) {
			diff += 1;
		}
		else {
			if (isSquareNumA || isSquareNumB)
				diff += 1;
		}
	}
	return diff;
}

int main() {
	//freopen("C:\\data\\personal\\programming\\acm\\input_files\\squarenumbers11461\\input.txt", "r", stdin);
	int squares[NUMSQUARENUMBERS + 1];
	constructSquares (squares, NUMSQUARENUMBERS);
    
	int a = 0;
	int b = 0;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			return 0;
		}
		cout << getNumSquaresBetween(squares, a, b) << endl;
	}
	return 0;
}
