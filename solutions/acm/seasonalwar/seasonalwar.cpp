#define MAXDIMENSION 27
#define NUMNEIGHBOURS 8
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;

enum CellType {NORMAL, EAGLE};

int bitmap[MAXDIMENSION][MAXDIMENSION];
int cellTypes[MAXDIMENSION][MAXDIMENSION];

class SeasonalWar {
	int N;
	int nEagles;
	unsigned long long imageNum;
	
private:
	void init() {
		nEagles = 0;
	}
	void initbitmap() {
		memset(bitmap, 0, sizeof(bitmap[0][0]) * MAXDIMENSION * MAXDIMENSION);
		memset(cellTypes, NORMAL, sizeof(cellTypes[0][0]) * MAXDIMENSION * MAXDIMENSION);
	}
public:
	SeasonalWar() { 
		//freopen("C:\\data\\personal\\programming\\acm\\\seasonalwar.txt", "r", stdin); 
		imageNum = 0;
		init(); 
		initbitmap(); 
	}
	~SeasonalWar() {
		//delete [] isComposite;
		//delete [] primeIndexStore;
	}

	void start() {
		while(cin >> N) {
			//cout << N << endl;

			init();
			
			initbitmap();

			char ch = ' ';
			for(int i = 1; i <= N; ++i) {
				for(int j = 1; j <= N; ++j) {
					cin >> ch;
					bitmap[i][j] = ch - '0';
					//cout << bitmap[j][k] << " ";
				}
				//cout << endl;
			}
			
			findEagles();
		}
	}
private:
	void printBitmap() {
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= N; ++j) {
				cout << bitmap[i][j];
			}
			cout << endl;
		}
		cout << "State:" << endl;
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= N; ++j) {
				cout << cellTypes[i][j];
			}
			cout << endl;
		}
	}
	void findEagles() {
		for(int i = 1; i <= N; ++i) {
				for(int j = 1; j <= N; ++j) {
				//cout << "cellTypes[" << i << "][" << j << "] is= " << cellTypes[i][j] << endl;
				if (bitmap[i][j] == 1 && cellTypes[i][j] == NORMAL) {
					//printBitmap();
					++nEagles;
					//cout << i << " " << j << " " << bitmap[i][j] << "is a part of EAGLE... " << nEagles << endl;
					spanEagleUsingDFS(i, j);
				}
			}
		}
		cout << "Image number " << ++imageNum << " contains " << nEagles << " war eagles." << endl;
	}

	bool areIndicesValid(int i, int j) {
		//cout << "[" << i << "," << j << "]" << endl;
		if(i < 1 )
			return false;
		if(j < 1)
			return false;
		if(i > N)
			return false;
		if(j > N)
			return false;
			
		return true;
	}

	void initNeighbourRowsCols(int* pRows, int* pCols, int i, int j) {
		//int left	= j - 1;
		//int top	= i - 1;
		//int right	= j + 1;
		//int bottom= i + 1;
		/*bitmap[top][left]	
		bitmap[top][col]		
		bitmap[top][right]	
		bitmap[row][right]	
		bitmap[bottom][right]
		bitmap[bottom][col]	
		bitmap[bottom][left]	
		bitmap[row][left]*/	

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

	void spanEagleUsingDFS(int i, int j) {
		if(areIndicesValid(i, j) == false) {
			//cout << i << " " << j << "indices are invalid." << endl;
			return;
		}
		
		int* pRows = new int[NUMNEIGHBOURS];
		int* pCols = new int[NUMNEIGHBOURS];
		initNeighbourRowsCols(pRows, pCols, i, j);

		if(cellTypes[i][j] == NORMAL) {
			cellTypes[i][j] = EAGLE;
			//cout << i << " " << j << "cellType:" << cellTypes[i][j] << " is part of eagle:" << nEagles << endl;

			//printBitmap();
			for(int m = 0; m < NUMNEIGHBOURS; ++m) {
				if(areIndicesValid(pRows[m], pCols[m]) == false)
					continue;

				if (bitmap[pRows[m]][pCols[m]] == 1 && cellTypes[pRows[m]][pCols[m]] == NORMAL) {
					//cout << i << " " << j << " neighbour " << pRows[m] << " " << pCols[m] << "is part of eagle:" << nEagles << endl;
					spanEagleUsingDFS(pRows[m], pCols[m]);
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
	SeasonalWar war;
	war.start();
	return 0;
}