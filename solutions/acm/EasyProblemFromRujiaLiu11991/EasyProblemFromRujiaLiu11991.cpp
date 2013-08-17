#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<int, vector<int>* > numberOccurrencesMap;
    map<int, vector<int>* >::iterator mapiterEnd;
    map<int, vector<int>* >::iterator mapiter;
    int nElems = 0;
    int mQueries = 0;
    int num = 0;
    unsigned int kthOccurrence = 0;
    vector<int>* pIndicesVector;

    while (cin >> nElems >> mQueries) {
        numberOccurrencesMap = map<int, vector<int>* >();
        for (int i = 1; i <= nElems; ++i) {
            cin >> num;
            pIndicesVector = numberOccurrencesMap[num];
            if (pIndicesVector == 0) {
                pIndicesVector = new vector<int>();
                numberOccurrencesMap[num] = pIndicesVector;
            }
            pIndicesVector->push_back(i);
        }

        for (int i = 1; i <= mQueries; ++i) {
            cin >> kthOccurrence >> num;
            pIndicesVector = numberOccurrencesMap[num];
            if (kthOccurrence <= pIndicesVector->size()) {
                cout << (*pIndicesVector)[kthOccurrence - 1] << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }

        mapiterEnd = numberOccurrencesMap.end();
        mapiter = numberOccurrencesMap.begin();
        for(; mapiter != mapiterEnd; ++mapiter) {
            delete (*mapiter).second;
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
