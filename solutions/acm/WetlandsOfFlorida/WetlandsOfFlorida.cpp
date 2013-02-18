//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410
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
	char input;
	int row;
	int col;
	int rows;
	int cols;
	
private:
	void init() {
		rows = 0;
		cols = 0;
		row = 0;
		col = 0;
	}
	void initWetLandsArea() {
		wetlandsArea = 0;
	}
	void initWetLandsMap() {
		memset(wetlandsMap, ' ', sizeof(wetlandsMap[0][0]) * MAXDIMENSION * MAXDIMENSION);
	}
	void initWetLandsCount() {
		memset(wetlandsCount, 0, sizeof(wetlandsCount[0][0]) * MAXDIMENSION * MAXDIMENSION);
	}
public:
	WetlandsOfFlorida() { 
		//freopen("C:\\data\\personal\\programming\\acm\\input_files\\wetlandsofflorida\\uva.txt", "r", stdin); 
		init(); 
		initWetLandsArea();
		initWetLandsMap(); 
		initWetLandsCount();
	}
	~WetlandsOfFlorida() {
	}

	void start() {
		scanf("%d", &nCases);
		//printf("%d\n", nCases);

		for (int i = 0; i < nCases; ++i) {
			scanf("%c", &input);
			//printf("%c", input);

			if (input == '\n') {
				while((input = getchar()) == '\n') 
					;
				cin.putback(input);
				init();
				initWetLandsMap();
				initWetLandsCount();
				readWetlandsMap();
			}
			else {
				cin.putback(input);
			}
			//createWetlandsCount();
			processCommands();
			
			cout << endl;
		}
	}
private:
	void readWetlandsMap() {
		char ch = ' ';
		for(int i = 1; i < MAXDIMENSION; ++i) {
			for(int j = 1; j < MAXDIMENSION; ++j) {
				scanf("%c", &ch);
				//printf("%c", ch);
				if (ch == '\n') {
					cols = j;
					break;
				}
				if (ch == 'W' || ch == 'L') {
					wetlandsMap[i][j] = ch;
				}
				else {
					cin.putback(ch);
					rows = i;
					////cout << "rows= " << rows << " cols= " << cols << endl;
					return;
				}
				////cout << wetlandsMap[i][j] << " ";
			}
			////cout << endl;
		}
	}
	void printwetlandsMap() {
		for(int i = 1; i <= rows; ++i) {
			for(int j = 1; j <= cols; ++j) {
				//cout << wetlandsMap[i][j];
			}
			//cout << endl;
		}
		//cout << "Counts:" << endl;
		for(int i = 1; i <= rows; ++i) {
			for(int j = 1; j <= cols; ++j) {
				//cout << wetlandsCount[i][j];
			}
			//cout << endl;
		}
	}

	void processCommands() {
		//while(cin >> input) {
		while ((input = getchar()) != EOF) {
			if(input == '\n') {
				cin.putback(input);
				return;
			}

			cin.putback(input);

			scanf("%d %d", &row, &col);
			scanf("%c", &input);
			
			initWetLandsCount();
			
			initWetLandsArea();
			
			getWetlandsCountUsingDFS(row, col);
			
			cout << wetlandsArea << endl;
		}
	}

	bool areIndicesValid(int i, int j) {
		if(i < 1 )
			return false;
		if(j < 1)
			return false;
		if(i > rows)
			return false;
		if(j > cols)
			return false;

		//cout << "[" << i << "," << j << "] is valid." << endl;
		return true;
	}

	void pushStack(int stack[MAXDIMENSION*MAXDIMENSION*NUMNEIGHBOURS][2], int* pStackCount, int r, int c) {
		//if(wetlandsMap[r][c] == 'W'  && wetlandsCount[r][c] == 0) {
			//cout << "Pusing [" << r << "," << c << "] onto to the stack at: " << *pStackCount << endl;
			stack[*pStackCount][0] = (r); 
			stack[*pStackCount][1] = (c); 
			++(*pStackCount);
		//}
	}

	void getWetlandsCountUsingDFS(int i, int j) {
		//cout << "Finding wetlands for [" << i << "," << j << "]" << endl;
		int stack[MAXDIMENSION*MAXDIMENSION*NUMNEIGHBOURS][2];
		int stackCount = 0;
		int r = 0;
		int c = 0;

		stack[0][0] = i;
		stack[0][1] = j;
		++stackCount;

		while(stackCount) {
			--stackCount;
			r = stack[stackCount][0];
			c = stack[stackCount][1];
			if(areIndicesValid(r, c) == false) {
				continue;
			}
			
			if(wetlandsMap[r][c] == 'W'  && wetlandsCount[r][c] == 0) {
				wetlandsCount[r][c] = ++wetlandsArea;
				//cout << "[" << r << "," << c << "] is a wetland." << endl;
				//#define pushStack(i,j) stack[stackCount][0] = (i); stack[stackCount][1] = (j); ++stackCount
					pushStack(stack, &stackCount, r - 1, c - 1);
					pushStack(stack, &stackCount, r - 1, c);
					pushStack(stack, &stackCount, r - 1, c + 1);
					pushStack(stack, &stackCount, r,     c + 1);
					pushStack(stack, &stackCount, r + 1, c + 1);
					pushStack(stack, &stackCount, r + 1, c);
					pushStack(stack, &stackCount, r + 1, c - 1);
					pushStack(stack, &stackCount, r,     c - 1);
				//#undef pushStack
			}
			else {
				//cout << "[" << r << "," << c << "] has: " << wetlandsMap[r][c] << " count= " << wetlandsCount[r][c] << endl;
			}
		}
	}
};

int main() {
	WetlandsOfFlorida project;
	project.start();
	return 0;
}
