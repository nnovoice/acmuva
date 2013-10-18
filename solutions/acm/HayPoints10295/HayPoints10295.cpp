#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, long> responsibilityPaymentMap;
    string responsibility;
    long salary = 0;
    long totalSalary = 0;
    int nWordsInHayPointDictionary = 0;
    int nJobDescriptions = 0;
    cin >> nWordsInHayPointDictionary >> nJobDescriptions;
        for (int i = 0; i < nWordsInHayPointDictionary; ++i) {
        cin >> responsibility >> salary;
        responsibilityPaymentMap[responsibility] = salary;
    }

    for (int i = 0; i < nJobDescriptions; ++i) {
        totalSalary = 0;
        while (cin >> responsibility) {
            if (responsibility == ".") break;
            totalSalary += responsibilityPaymentMap[responsibility];
        }
        cout << totalSalary << endl;
    }

    return 0;
}
