#define MAXSTUDENTS 1000
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

class Trip {
private:
	int costs[MAXSTUDENTS];
	int nStudents;
	int dollars;
	int cents;
	int minMoneyExchanged;
	int total;
	int average;
	int diff;
	int nGivers;
	int nTakers;
public:
	Trip() { 
		//freopen ("C:\\data\\personal\\programming\\acm\\input_files\\thetrip\\input.txt", "r", stdin); 
	}
	
	void process() {
		while(cin >> nStudents) {
			if(nStudents == 0) { 
				return; 
			}

			initMembers();
			
			cout << nStudents << endl;
			
			for(int i = 0; i < nStudents; ++i) {
				scanf("%d.%d", &dollars, &cents);
				//printf("%d.%d= ", dollars, cents);
				costs[i] = dollars * 100;
				costs[i] += cents;
				cout << costs[i] << endl;
			}
			
			calculateMinimumMoneyExchanged();
			
			printMoneyExchanged();
		}
	}
private:
	void initMembers() {
		memset(costs, 0, sizeof(int) * MAXSTUDENTS);
		dollars = 0;
		cents = 0;
		minMoneyExchanged = 0;
		total = 0;
		average = 0;
		diff = 0;
		nGivers = 0;
		nTakers = 0;
	}
	void calculateMinimumMoneyExchanged() {
		sortCosts();

		calculateAverage();

		calculateNumGivers();
		cout << "Num givers= " << nGivers << endl;

		calculateNumTakers();
		cout << "Num takers= " << nTakers << endl;

		computeMoneyExchanged();
	}
	void printMoneyExchanged() {
		printf("$%d.%02d\n", (minMoneyExchanged / 100), (minMoneyExchanged % 100)); 
	}
	void sortCosts() {
		sort(costs, costs + nStudents);
	}
	void calculateAverage() {
		for(int i = 0; i < nStudents; ++i)
			total += costs[i];
		
		average = total / nStudents;
		cout << "Avg= " << average << endl;
		
		diff = total - (average * nStudents);
		cout << "Diff= " << diff << endl;
	}
	void calculateNumGivers() {
		for(int i = 0; i < nStudents; ++i) {
			if(costs[i] <= average) {
				++nGivers;
			}
		}
	}
	void calculateNumTakers() {
		for(int i = 0; i < nStudents; ++i) {
			if(costs[i] > average) {
				++nTakers;
			}
		}
	}
	void computeMoneyExchanged() {
		for(int i = 0; i < nStudents; ++i) {
			if(costs[i] <= average) {
				minMoneyExchanged += (average - costs[i]);
				cout << "Intermediate money exchanged= " << minMoneyExchanged << endl;
			}
			else {
				break;
			}
		}
		
		// this piece handles the extra pennies left out
		if (diff > 0) {
			diff -= nTakers; // make all the takers take 1 penny more
			
			if (diff > 0) { // more pennies left means, the givers get to retain the money [spending less :)]
				minMoneyExchanged -= (diff > nGivers) ? nGivers : (nGivers - diff);
				diff -= (diff > nGivers) ? nGivers : (nGivers - diff);
			}
			if (diff > 0) { // even more left means a BIG problems ;-)
				cout << "Something wrong." << endl;
			}
			cout << "Final money exchanged= " << minMoneyExchanged << endl;
		}
	}
};

int main(int argc, char* argv[])
{
	Trip theTrip;
	theTrip.process();
	return 0;
}

