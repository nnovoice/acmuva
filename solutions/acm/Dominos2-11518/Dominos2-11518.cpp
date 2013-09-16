#include <iostream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

const int MAXNUMBER = 10001;
bool visited[MAXNUMBER];
int dominosStack[MAXNUMBER];
int idx;

void PrintMap(map<int, vector<int>* >& dominoesConfigurationMap)
{
    map<int, vector<int>* >::iterator endIter = dominoesConfigurationMap.end();
    map<int, vector<int>* >::iterator iter = dominoesConfigurationMap.begin();
    vector<int>* pFallingDominos;
    for (; iter != endIter; ++iter) {
        cout << "Domino= " << (*iter).first << ": ";
        pFallingDominos = (*iter).second;
        for (unsigned int i = 0; i < pFallingDominos->size(); ++i) {
            cout << (*pFallingDominos)[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    map<int, vector<int>* > dominoesConfigurationMap;
    vector<int>* pFallingDominos;
    int nCases = 0;
    int nDominoesThatFell = 0;
    int n = 0; /// n dominos
    int m = 0; /// m lines containing x y means if x falls then so does y
    int l = 0; /// l lines containing dominos that are felled by hand
    int d1 = 0;
    int d2 = 0;
    int manualDomino = 0;
    int currentDomino = 0;

    cin >> nCases;
    while (nCases--) {
        memset (visited, false, sizeof(visited));
        memset (dominosStack, 0, sizeof(dominosStack));
        idx = 0;
        dominoesConfigurationMap = map<int, vector<int>* >();
        nDominoesThatFell = 0;

        cin >> n >> m >> l;
        for (int i = 0; i < m; ++i) {
            cin >> d1 >> d2;
            pFallingDominos = dominoesConfigurationMap[d1];
            if (pFallingDominos == 0) {
                pFallingDominos = new vector<int>();
                dominoesConfigurationMap[d1] = pFallingDominos;
            }
            dominoesConfigurationMap[d1]->push_back(d2);
        }
        //cout << "Debug: " << "Printing map" << endl;
        //PrintMap(dominoesConfigurationMap);
        //cout << "Debug: " << "End of Printing map" << endl;

        for (int j = 0; j < l; ++j) {
            cin >> manualDomino;
            //cout << "Debug: " << "manual domino= " << manualDomino << endl;
            dominosStack[idx++] = manualDomino;
            //cout << "Debug: " << "idx after inserting domino into stack= " << idx << endl;
            while (idx != 0) {
                currentDomino = dominosStack[--idx];
                //cout << "Debug: " << "current domino= " << currentDomino << endl;
                if (visited[currentDomino] == false) {
                        //cout << "Debug: " << "Visited current domino= " << visited[currentDomino] << endl;
                    visited[currentDomino] = true;
                    ++nDominoesThatFell;
                    pFallingDominos = dominoesConfigurationMap[currentDomino];
                    if (pFallingDominos != 0) {
                        for (unsigned int k = 0; k < pFallingDominos->size(); ++k) {
                            dominosStack[idx++] = (*pFallingDominos)[k];
                            //cout << "Debug: " << "Inserting domino into stack= " << dominosStack[idx - 1] << endl;
                        }
                    }
                }
            }
        }
        cout << nDominoesThatFell << endl;
    }

    return 0;
}
