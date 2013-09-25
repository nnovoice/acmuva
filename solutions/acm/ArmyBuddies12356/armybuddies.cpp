/* UVa 12356 - ArmyBuddies*/
#define MAXSOLDIERS 100001
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	bool soldiers[MAXSOLDIERS] = {false};
	int nSoldiers = 0;
	int nLossReports = 0;
	int leftSoldier = 0;
	int rightSoldier = 0;

	while (cin >> nSoldiers >> nLossReports) {
		if (nSoldiers == 0 && nLossReports == 0) 
			break;

		memset (soldiers, true, sizeof(bool) * (nSoldiers + 1));
		soldiers[0] = false;
		soldiers[nSoldiers + 1] = false;

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
				soldiers[j] = false;

			int leftBuddy = leftSoldier - 1;
			for (; leftBuddy > 0; --leftBuddy)
				if (soldiers[leftBuddy] == true)
					break;
			//cout << "Debug: " << "Left buddy = " << leftBuddy << endl;
			(soldiers[leftBuddy] == true) ? (cout << leftBuddy) : (cout << '*');
			cout << ' ';

			int rightBuddy = rightSoldier + 1;
			for (; rightBuddy <= nSoldiers; ++rightBuddy)
				if (soldiers[rightBuddy] == true)
					break;
			//cout << "Debug: " << "Right buddy = " << rightBuddy << endl;

			(soldiers[rightBuddy] == true) ? (cout << rightBuddy) : (cout << '*');
			cout << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}