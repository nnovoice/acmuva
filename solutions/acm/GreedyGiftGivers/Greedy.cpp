/* @JUDGE_ID: 44823RT 119 C++  */
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main ()
{
	int num_people = 0;
	string people[10] = { "" };
	map<string, int> people_map;
	int nCases = 0;

	while ( cin >> num_people )
	{
	    if (++nCases > 1)
            cout << endl;

		/* get the list of names */
		for (int i = 0; i < num_people; ++i)
			cin >> people[i];

		/* for each giver, distribute money to recepients */
		for (int j = 0; j < num_people; ++j)
		{
			string giver = "";
			cin >> giver;

			int amount = 0, ntakers = 0;
			cin >> amount >> ntakers;
			if ( !ntakers ) /* if no recepients, just move ahead */
				continue;

			people_map[giver] -= amount;
			string taker = "";
			/* recepient gets money here :-) */
			for (int k = 0; k < ntakers; ++k) {
				cin >> taker;
				people_map[taker] += (amount / ntakers);
			}

			/* any amount remaining stays with the giver */
			people_map[giver] += ( amount - ( ntakers * (amount / ntakers) ) );
		}

		/* print in the order we read the names */
		for (int i = 0; i < num_people; ++i)
			cout << people[i] << " " << people_map[people[i]] << endl;

		/* reset map */
		people_map.erase ( people_map.begin(), people_map.end() );
		//cout << endl; /* <???> one extra endl at the end. is this ok? */
	}
	return 0;
}
