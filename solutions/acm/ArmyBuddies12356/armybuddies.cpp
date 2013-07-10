/* UVa 12356 - ArmyBuddies*/
#define MAXSOLDIERS 100001
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset <MAXSOLDIERS> soldiers;
	int nSoldiers = 0;
	int nLossReports = 0;
	int leftSoldier = 0;
	int rightSoldier = 0;

	while (cin >> nSoldiers >> nLossReports) {
		if (nSoldiers == 0 && nLossReports == 0) 
			break;

		soldiers.set();
		soldiers.flip(0);
		soldiers.flip(nSoldiers + 1);

		for (int i = 0; i < nLossReports; ++i) {
			cin >> leftSoldier >> rightSoldier;

			// mark the losses in range [left, right]
			for (int j = leftSoldier; j <= rightSoldier; ++j)
				soldiers.flip(j);

			int leftBuddy = leftSoldier - 1;
			for (; leftBuddy > 0; --leftBuddy)
				if (soldiers.test(leftBuddy) == true)
					break;
			
			(leftBuddy > 0) ? (cout << leftBuddy) : (cout << '*');
			cout << ' ';

			int rightBuddy = rightSoldier + 1;
			for (; rightBuddy <= nSoldiers; ++rightBuddy)
				if (soldiers.test(rightBuddy) == true)
					break;

			(soldiers.test(rightBuddy) == true) ? (cout << rightBuddy) : (cout << '*');
			cout << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}