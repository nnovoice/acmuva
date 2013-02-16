#define MAXDIMENSION 101
#define NUMNEIGHBOURS 8
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;

char wetlandsMap[MAXDIMENSION][MAXDIMENSION];
int wetlandsCount[MAXDIMENSION][MAXDIMENSION];

class WetlandsOfFlorida {
	int nCases;
	int wetlandsArea;
	int currentWetlandCount;
	char input;
	int row;
	int col;
	int rows;
	int cols;
	
private:
	void init() {
		wetlandsArea = 0;
		currentWetlandCount = 0;
		row = 0;
		col = 0;
	}
	void initWetLandsMap() {
		memset(wetlandsMap, ' ', sizeof(wetlandsMap[0][0]) * MAXDIMENSION * MAXDIMENSION);
	}
	void initWetLandsCount() {
		memset(wetlandsCount, 0, sizeof(wetlandsCount[0][0]) * MAXDIMENSION * MAXDIMENSION);
	}
public:
	WetlandsOfFlorida() { 
		//freopen("C:\\data\\personal\\programming\\acm\\\WetlandsOfFlorida.txt", "r", stdin); 
		init(); 
		initWetLandsMap(); 
		initWetLandsCount();
	}
	~WetlandsOfFlorida() {
	}

	void start() {
		cin >> nCases;
		
		for (int i = 0; i < nCases; ++i) {
			cin >> input;
			if (input == '\n') {
				init();
				initWetLandsMap();
				initWetLandsCount();
				readWetlandsMap();
			}
			else {
				cin.push_back(input);
			}
			//createWetlandsCount();
			processCommands();
		}
	}
private:
	void readWetlandsMap() {
		char ch = ' ';
		for(int i = 1; i < MAXDIMENSION; ++i) {
			for(int j = 1; j < MAXDIMENSION; ++j) {
				cin >> ch;
				if (ch == '\n') {
					cols = j;
					break;
				}
				if (ch != 'W' || ch != 'L') {
					cin.push_back(ch);
					rows = i;
					return;
				}
				wetlandsMap[i][j] = ch;
				//cout << wetlandsMap[i][j] << " ";
			}
			//cout << endl;
		}
	}
	void printwetlandsMap() {
		for(int i = 1; i <= rows; ++i) {
			for(int j = 1; j <= cols; ++j) {
				cout << wetlandsMap[i][j];
			}
			cout << endl;
		}
		cout << "Counts:" << endl;
		for(int i = 1; i <= rows; ++i) {
			for(int j = 1; j <= cols; ++j) {
				cout << wetlandsCount[i][j];
			}
			cout << endl;
		}
	}
	

	void processCommands() {
		while(cin >> input) {
			cin.push_back(input);
			
			if(input == '\n') {
				return;
			}

			cin >> row >> col;
			
			initWetLandsCount();
			
			getWetlandsCountUsingDFS(row, col);
			
			cout << wetlandsArea << endl;
		}
	}

	bool areIndicesValid(int i, int j) {
		//cout << "[" << i << "," << j << "]" << endl;
		if(i < 1 )
			return false;
		if(j < 1)
			return false;
		if(i > rows)
			return false;
		if(j > cols)
			return false;
			
		return true;
	}

	void initNeighbourRowsCols(int* pRows, int* pCols, int i, int j) {
		//int left	= j - 1;
		//int top	= i - 1;
		//int right	= j + 1;
		//int bottom= i + 1;
		/*wetlandsMap[top][left]	
		wetlandsMap[top][col]		
		wetlandsMap[top][right]	
		wetlandsMap[row][right]	
		wetlandsMap[bottom][right]
		wetlandsMap[bottom][col]	
		wetlandsMap[bottom][left]	
		wetlandsMap[row][left]*/	

		pRows[0] = i - 1;
		pRows[1] = i - 1;
		pRows[2] = i - 1 ;
		pRows[3] = i;
		pRows[4] = i + 1;
		pRows[5] = i + 1;
		pRows[6] = i + 1;
		pRows[7] = i;

		pCols[0] = j - 1;
		pCols[1] = j;
		pCols[2] = j + 1;
		pCols[3] = j + 1;
		pCols[4] = j + 1;
		pCols[5] = j;
		pCols[6] = j - 1;
		pCols[7] = j - 1;
	}

	void getWetlandsCountUsingDFS(int i, int j) {
		if(areIndicesValid(i, j) == false) {
			//cout << i << " " << j << "indices are invalid." << endl;
			return;
		}
		
		int* pRows = new int[NUMNEIGHBOURS];
		int* pCols = new int[NUMNEIGHBOURS];
		initNeighbourRowsCols(pRows, pCols, i, j);

		if(wetlandsCount[i][j] == 0) {
			wetlandsCount[i][j] = ++wetlandsArea;
			//cout << i << " " << j << "cellType:" << wetlandsCount[i][j] << " is part of eagle:" << wetlandsArea << endl;

			//printwetlandsMap();
			for(int m = 0; m < NUMNEIGHBOURS; ++m) {
				if(areIndicesValid(pRows[m], pCols[m]) == false)
					continue;

				if (wetlandsMap[pRows[m]][pCols[m]] == 'W' && wetlandsCount[pRows[m]][pCols[m]] == 0) {
					//cout << i << " " << j << " neighbour " << pRows[m] << " " << pCols[m] << "is part of eagle:" << wetlandsArea << endl;
					getWetlandsCountUsingDFS(pRows[m], pCols[m]);
				}
			}
		}
		if (pRows != 0) {
			delete [] pRows;
			pRows = 0;
		}
		if (pCols != 0) {
			delete [] pCols;
			pCols = 0;
		}
	}
};

int main() {
	WetlandsOfFlorida project;
	project.start();
	return 0;
}

//void createWetlandsCount() {
	//	for(int i = 1; i <= N; ++i) {
	//		wetlandsArea = 0;
	//			for(int j = 1; j <= N; ++j) {
	//			//cout << "wetlandsCount[" << i << "][" << j << "] is= " << wetlandsCount[i][j] << endl;
	//			if (wetlandsMap[i][j] == 'W' && wetlandsCount[i][j] == 0) {
	//				//printwetlandsMap();
	//				
	//				//cout << i << " " << j << " " << wetlandsMap[i][j] << "is a part of EAGLE... " << wetlandsArea << endl;
	//				getWetlandsCountUsingDFS(i, j);
	//			}
	//		}
	//	}
	//	cout << "Image number " << ++imageNum << " contains " << wetlandsArea << " war eagles." << endl;
	//}