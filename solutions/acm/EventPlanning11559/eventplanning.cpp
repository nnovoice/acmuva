/* 11559 - Event Planning */
#define MAXHOTELS 18
#include <iostream>
#include <algorithm>
using namespace std;

//1 <= N <= 200    N- number of participants
//1 <= B <= 500000 B - budget
//1 <= H <= 18     H - number of hotels to consider
//1 <= W <= 13     W - weeks to consider
//1 <= p <= 10000  p - price per person per weekend
//W integers per hotel

int main()
{
	int numParticipants = 0;
	int budget = 0;
	int numHotels = 0;
	int weeksToChooseFrom = 0;
	int pricePerPerson = 0;
	int numAvailableBeds = 0;
	int prices[MAXHOTELS] = {0};
	int numPrices = 0;
	bool isHotelAvailable = false;

	while (cin >> numParticipants >> budget >> numHotels >> weeksToChooseFrom) {
		numPrices = 0;
		
		for (int i = 0; i < numHotels; ++i) {
			isHotelAvailable = false;
			cin >> pricePerPerson;
			for (int j = 0; j < weeksToChooseFrom; ++j) {
				cin >> numAvailableBeds;
				if (isHotelAvailable == false && numAvailableBeds >= numParticipants) {
					isHotelAvailable = true;
				}
			}
			if (isHotelAvailable) {
				prices[numPrices++] = numParticipants * pricePerPerson;
			}
		}
		sort (prices, prices + numPrices);
		
		if (numPrices > 0 && prices[0] <= budget) {
			cout << prices[0] << endl;
		}
		else {
			cout << "stay home" << endl;
		}
	}
	return 0;
}

