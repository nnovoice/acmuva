//PC/UVa IDs: 110501/10035, Popularity: A, Success rate: average Level: 1
#define MAXLEN 11

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

class PrimaryArithmetic {
private:
	char num1[MAXLEN];
	char num2[MAXLEN];
	char revNum1[MAXLEN];
	char revNum2[MAXLEN];
	int nCarryOvers;
	int nTestCases;
private:
	void init() {
		memset(revNum1, '\0', sizeof(char) * MAXLEN);
		memset(revNum2, '\0', sizeof(char) * MAXLEN);
		nCarryOvers = 0;
	}
	void constructReverseNumbers() {
		constructReverseNumber(num1, revNum1);
		constructReverseNumber(num2, revNum2);
	}
	void constructReverseNumber(char num[MAXLEN], char revNum[MAXLEN]) {
		int len = strlen(num);
		for (int i = len - 1; i >= 0; --i) {
			revNum[len - i - 1] = num[i];
		}
	}
public:
	PrimaryArithmetic() { 
		//freopen("C:\\data\\personal\\programming\\acm\\input_files\\primaryarithmetic\\uva.txt", "r", stdin);
		nTestCases = 0;
	}
	int process() {
		while (cin >> num1 >> num2) {
			++nTestCases;
			if (strcmp(num1, "0") == 0 && strcmp(num2, "0") == 0) {
				break;
			}

			init();

			numCarryOvers();
		}

		return 0;
	}
	int numCarryOvers() {
		constructReverseNumbers();
		int len1 = strlen(num1);
		int len2 = strlen(num2);
		int minLen = (len1 < len2) ? len1 : len2;
		char* pNumWithMoreDigits = (len1 < len2) ? num2 : num1;

		int curCarry = 0;
		int curTotal = 0;
		for (int i = 0; i < minLen; ++i) {
			curTotal = curCarry + (num1[i] - '0') + (num2[i] - '0');
			curCarry = (curTotal >= 10) ? 1 : 0;
			nCarryOvers += curCarry;
		}

		pNumWithMoreDigits += minLen;
		while (*pNumWithMoreDigits != '\0') {
			curTotal = curCarry + (*pNumWithMoreDigits - '0');
			curCarry = (curTotal >= 10) ? 1 : 0;
			nCarryOvers += curCarry;
			++pNumWithMoreDigits;
		}

		if (nTestCases > 1) {
			cout << endl;
		}

		if (nCarryOvers == 0) {
			cout << "No carry operation.";
		}
		else if(nCarryOvers == 1) {
			cout << nCarryOvers << " carry operation.";
		}
		else {
			cout << nCarryOvers << " carry operations.";
		}
		
		return 0;
	}
};

int main(int argc, char* argv[])
{
	PrimaryArithmetic digitAdder;
	digitAdder.process();
	return 0;
}