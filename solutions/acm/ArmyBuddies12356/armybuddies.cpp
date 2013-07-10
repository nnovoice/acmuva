/* UVa 12356 - ArmyBuddies*/
#define MAXSOLDIERS 100001
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int soldiers[MAXSOLDIERS] = {0};
	int nSoldiers = 0;
	int nLossReports = 0;
	int leftSoldier = 0;
	int rightSoldier = 0;

	while (cin >> nSoldiers >> nLossReports) {
		if (nSoldiers == 0 && nLossReports == 0) 
			break;

		// memset sets each byte to the value passed to it
		// so, it is not equivalent to 2, but 0x02020202
		// memset (soldiers, 2, sizeof(int) * MAXSOLDIERS);

		// set to 0 means everyone is alive. set to 1 means there is a loss.
		memset (soldiers, 0, sizeof(int) * MAXSOLDIERS);
		soldiers[0] = 1;
		soldiers[nSoldiers + 1] = 1;

		for (int i = 0; i < nLossReports; ++i) {
			/*cout << "Debug: ";
			for (int k = 1; k <= nSoldiers; ++k) {
				cout << soldiers[k] << " ";
			}
			cout << endl;*/
			cin >> leftSoldier >> rightSoldier;
			//cout << "Debug: " << leftSoldier << " " << rightSoldier << endl;

			// mark the losses in range [left, right]
			for (int j = leftSoldier; j <= rightSoldier; ++j)
				soldiers[j] = 1;

			int leftBuddy = leftSoldier - 1;
			for (; leftBuddy > 0; --leftBuddy)
				if (soldiers[leftBuddy] == 0)
					break;
			//cout << "Debug: " << "Left buddy = " << leftBuddy << endl;
			(leftBuddy > 0) ? (cout << leftBuddy) : (cout << '*');
			cout << ' ';

			int rightBuddy = rightSoldier + 1;
			for (; rightBuddy <= nSoldiers; ++rightBuddy)
				if (soldiers[rightBuddy] == 0)
					break;
			//cout << "Debug: " << "Right buddy = " << rightBuddy << endl;

			(soldiers[rightBuddy] == 0) ? (cout << rightBuddy) : (cout << '*');
			cout << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}