#define MAXDIMENSION 27
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
	int imageNum;
	
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
	void findEagles() {
		for(int i = 1; i <= N; ++i) {
				for(int j = 1; j <= N; ++j) {
				//cout << "cellTypes[" << i << "][" << j << "] is= " << cellTypes[i][j] << endl;
				if (bitmap[i][j] == 1 && cellTypes[i][j] == NORMAL) {
					++nEagles;
					//	//cout << i << " " << j << " " << bitmap[i][j] << "is a part of EAGLE... ";
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
		pRows[0] = i - 1;
		pRows[1] = i + 1;
		pRows[2] = i;
		pRows[3] = i;
		pCols[0] = j;
		pCols[1] = j;
		pCols[2] = j - 1;
		pCols[3] = j + 1;
	}

	void spanEagleUsingDFS(int i, int j) {
		if(areIndicesValid(i, j) == false)
			return;
		
		int* pRows = new int[4];
		int* pCols = new int[4];
		initNeighbourRowsCols(pRows, pCols, i, j);

		if(cellTypes[i][j] == NORMAL) {
			cellTypes[i][j] = EAGLE;
			for(int m = 0; m < 4; ++m) {
				if(areIndicesValid(pRows[m], pCols[m]) == false)
					continue;

				if (bitmap[pRows[m]][pCols[m]] == 1 && cellTypes[pRows[m]][pCols[m]] == NORMAL) {
					//cout << i << " " << j << " neighbour " << pRows[m] << " " << cols[m] << "is unlocked" << endl;
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