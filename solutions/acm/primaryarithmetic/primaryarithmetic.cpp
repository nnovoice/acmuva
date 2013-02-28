//PC/UVa IDs: 110501/10035, Popularity: A, Success rate: average Level: 1
#define MAXLEN 10

#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <string.h>

using namespace std;

class PrimaryArithmetic {
private:
	unsigned int num1;
	unsigned int num2;
	unsigned int nCarryOvers;
	unsigned int nTestCases;
private:
	void init() {
		nCarryOvers = 0;
	}
public:
	PrimaryArithmetic() { 
		//freopen("C:\\data\\personal\\programming\\acm\\input_files\\primaryarithmetic\\uva.txt", "r", stdin);
		nTestCases = 0;
	}
	int process() {
		while (cin >> num1 >> num2) {
			++nTestCases;
			if (num1 == 0 && num2 == 0) {
				break;
			}

			init();

			numCarryOvers();

			printCarryOvers();
		}

		return 0;
	}
	void numCarryOvers() {
		unsigned int* pBiggerNum = (num1 > num2) ? &num1 : &num2;
		unsigned int digit1 = 0;
		unsigned int digit2 = 0;
		unsigned int carry = 0;
		unsigned int digitsTotal = 0;
		while (*pBiggerNum) 
		{
			digit1 = num1 % 10;
			digit2 = num2 % 10;
			digitsTotal = carry + digit1 + digit2;
			carry = (digitsTotal >= 10) ? 1 : 0;
			if (carry == 1) {
				++nCarryOvers;
			}
			num1 /= 10;
			num2 /= 10;
		}
	}
	void printCarryOvers() {
		/*if (nTestCases > 1) {
			cout << endl;
		}*/

		if (nCarryOvers == 0) {
			cout << "No carry operation.";
		}
		else if(nCarryOvers == 1) {
			cout << nCarryOvers << " carry operation.";
		}
		else {
			cout << nCarryOvers << " carry operations.";
		}
		cout << endl;
	}
};

int main(int argc, char* argv[])
{
	PrimaryArithmetic digitAdder;
	digitAdder.process();
	return 0;
}