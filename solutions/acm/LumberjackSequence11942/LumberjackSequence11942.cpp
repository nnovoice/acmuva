#include <iostream>
using namespace std;

enum BeardsLengthType { EQUAL, INCREASING, DECREASING};

int main(int argc, char* argv[])
{
	BeardsLengthType lastBeardsLengthType = EQUAL;
	BeardsLengthType currentBeardsLengthType = EQUAL;
	bool ordered = true;
	int beardLengthDiff = 0;
	int N = 0;
	int lumberjacks[10] = {0};
	
	cin >> N;
	cout << "Lumberjacks:" << endl;	
	while (N--) {
		for (int i = 0; i < 10; ++i) {
			cin >> lumberjacks[i];
		}
		
		ordered = true;
		lastBeardsLengthType = EQUAL;

		for (int i = 1; i < 10; ++i) {
			beardLengthDiff = lumberjacks[i - 1] - lumberjacks[i];
			if (beardLengthDiff == 0) {
				currentBeardsLengthType = EQUAL;
			}
			else if (beardLengthDiff < 0) {
				currentBeardsLengthType = DECREASING;
			}
			else {
				currentBeardsLengthType = INCREASING;
			}

			if (currentBeardsLengthType != EQUAL) {
				if (lastBeardsLengthType != EQUAL) {
					if (currentBeardsLengthType != lastBeardsLengthType) {
						ordered = false;
						break;
					}
				}
				else {
					lastBeardsLengthType = currentBeardsLengthType;
				}
			}
		}

		if (ordered) {
			cout << "Ordered" << endl;
		}
		else {
			cout << "Unordered" << endl;
		}
	}
	return 0;
}

