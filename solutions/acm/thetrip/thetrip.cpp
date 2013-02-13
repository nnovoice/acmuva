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
	int nTripNum;
public:
	Trip() { 
		//freopen ("C:\\data\\personal\\programming\\acm\\input_files\\thetrip\\input.txt", "r", stdin); 
		nTripNum = 0;
	}
	
	void process() {
		while(cin >> nStudents) {
			if(nStudents == 0) { 
				return; 
			}
			
			initMembers();

			++nTripNum;
			
			//cout<< nStudents << endl;
			
			for(int i = 0; i < nStudents; ++i) {
				scanf("%d.%d", &dollars, &cents);
				//printf("%d.%d= ", dollars, cents);
				costs[i] = dollars * 100;
				costs[i] += cents;
				//cout<< costs[i] << endl;
			}
			
			calculateMinimumMoneyExchanged();
			
			if (nTripNum > 1)
				printf("\n");

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
		//cout<< "Num givers= " << nGivers << endl;

		calculateNumTakers();
		//cout<< "Num takers= " << nTakers << endl;

		computeMoneyExchanged();
	}
	void printMoneyExchanged() {
		printf("$%d.%02d", (minMoneyExchanged / 100), (minMoneyExchanged % 100)); 
	}
	void sortCosts() {
		sort(costs, costs + nStudents);
	}
	void calculateAverage() {
		for(int i = 0; i < nStudents; ++i)
			total += costs[i];
		
		average = total / nStudents;
		if ((total % nStudents) != 0)
			average += 1;
		
		//cout<< "Avg= " << average << endl;
		
		diff = total - (average * nStudents);
		if(diff < 0) {
			diff = 0 - diff;
		}
		//cout<< "Diff= " << diff << endl;
	}
	void calculateNumGivers() {
		for(int i = 0; i < nStudents; ++i) {
			if(costs[i] < average) {
				++nGivers;
			}
		}
	}
	void calculateNumTakers() {
		for(int i = 0; i < nStudents; ++i) {
			if(costs[i] >= average) {
				++nTakers;
			}
		}
	}
	void computeMoneyExchanged() {
		for(int i = 0; i < nStudents; ++i) {
			if(costs[i] <= average) {
				minMoneyExchanged += (average - costs[i]);
				//cout<< "Intermediate money exchanged= " << minMoneyExchanged << endl;
			}
			else {
				break;
			}
		}
		
		//Still getting WA probably because of the below test case. 
		//15
		//0.01
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		//0.03
		// Expected answer is $0.02
		// What was missing in the problem statement or was hidden is that the
		// sharing has be be a fair thing. If there are people who have spent more
		// then, they get to keep the extra money, otherwise, the people who spent
		// less get to keep the extra.
		if (nGivers < nTakers) {
			if (diff > 0) { // extra pennies are first taken by receivers
				diff -= (diff > nTakers) ? nTakers : diff;
			}
			if (diff > 0) { // more pennies left means, the givers get to retain the money [spending less :)]
				minMoneyExchanged -= (diff > nGivers) ? nGivers : diff;
				diff -= (diff > nGivers) ? nGivers : diff;
			}
		}
		else {
			if (diff > 0) { // the givers get to retain the money first [spending less :)]
				minMoneyExchanged -= (diff > nGivers) ? nGivers : diff;
				diff -= (diff > nGivers) ? nGivers : diff;
			}
			if (diff > 0) { // extra pennies are then taken by receivers
				diff -= (diff > nTakers) ? nTakers : diff;
			}
		}
	}
};

int main(int argc, char* argv[])
{
	Trip theTrip;
	theTrip.process();
	return 0;
}

