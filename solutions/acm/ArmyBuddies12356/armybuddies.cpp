/* UVa 12356 - ArmyBuddies*/
#define MAXSOLDIERS 100001
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int leftSoldiers[MAXSOLDIERS] = {0};
	int rightSoldiers[MAXSOLDIERS] = {0};
	int nSoldiers = 0;
	int nLossReports = 0;
	int leftSoldier = 0;
	int rightSoldier = 0;

	while (scanf("%d %d", &nSoldiers, &nLossReports) != EOF) {
		if (nSoldiers == 0 && nLossReports == 0)
			break;

		memset (leftSoldiers, 0, sizeof(int) * (nSoldiers + 1));
		memset (rightSoldiers, 0, sizeof(int) * (nSoldiers + 1));

		leftSoldiers[0] = -1;
		leftSoldiers[nSoldiers + 1] = nSoldiers;

		rightSoldiers[0] = 1;
		rightSoldiers[nSoldiers + 1] = -1;

		for (int i = 0; i < nLossReports; ++i) {
			/*cout << "Debug: ";
			for (int k = 1; k <= nSoldiers; ++k) {
				cout << soldiers[k] << " ";
			}
			cout << endl;*/
			//cin >> leftSoldier >> rightSoldier;
			scanf("%d %d", &leftSoldier, &rightSoldier);
			//cout << "Debug: " << leftSoldier << " " << rightSoldier << endl;
			//printf("left soldier= %d right Soldiers= %d\n", leftSoldier, rightSoldier);

			// mark the losses in range [left, right]
			int j = leftSoldier;
			int k = rightSoldier;
			for (; j <= rightSoldier && k >= leftSoldier; ++j, --k) {
				//leftSoldiers[j] = leftSoldiers[j - 1];
				leftSoldiers[j] = (leftSoldiers[j - 1] == 0) ? (j - 1) : leftSoldiers[j - 1];
				//printf("leftSoldiers[%d]=%d\n", j, leftSoldiers[j]);
				//cout << "Debug: " << leftSoldier << " " << rightSoldier << endl;
				//rightSoldiers[k] = rightSoldiers[k + 1];
				rightSoldiers[k] = (rightSoldiers[k + 1] == 0) ? (k + 1) : rightSoldiers[k + 1];
				//printf("rightSoldiers[%d]=%d\n", k, rightSoldiers[k]);
			}

			int leftBuddy = leftSoldier - 1;
			while (leftSoldiers[leftBuddy] != -1 && leftSoldiers[leftBuddy] != 0)
				leftBuddy = leftSoldiers[leftBuddy];

			//cout << "Debug: " << "Left buddy = " << leftBuddy << endl;
			(leftSoldiers[leftBuddy] == 0) ? (printf("%d ", leftBuddy)) : (printf("* "));

			int rightBuddy = rightSoldier + 1;
			while (rightSoldiers[rightBuddy] != -1 && rightSoldiers[rightBuddy] != 0)
				rightBuddy = rightSoldiers[rightBuddy];
			//cout << "Debug: " << "Right buddy = " << rightBuddy << endl;

			(rightSoldiers[rightBuddy] == 0) ? (printf("%d\n", rightBuddy)) : (printf("*\n"));
		}
		printf("-\n");
	}
	return 0;
}
