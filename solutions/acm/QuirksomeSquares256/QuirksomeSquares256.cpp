#include <iostream>

using namespace std;

const int MAXNUMBERS = 100000000;

unsigned int numbers[MAXNUMBERS];

void GetNumbers(int num, int& a, int& b, int numDigits)
{
    a = 0; b = 0;
    int digit = 0;
    int multiple = 1;
    int nExtractedDigits = 0;
    while (num != 0 && nExtractedDigits < numDigits) {
        digit = num % 10;
        b += digit * multiple;
        num -= digit;
        num /= 10;
        ++nExtractedDigits;
        multiple *= 10;
    }

    nExtractedDigits = 0;
    multiple = 1;

    while (num != 0 && nExtractedDigits < numDigits) {
        digit = num % 10;
        a += digit * multiple;
        num -= digit;
        num /= 10;
        ++nExtractedDigits;
        multiple *= 10;
    }
}


int main()
{
    int a = 0;
    int b = 0;
    int i = 0;
    int nDigits = 0;

    for (i = 1; i < MAXNUMBERS; ++i) {
        if (i < 100) {
            nDigits = 1;
            a = i % 10;
            b = i / 10;
        }
        else if (i < 10000) {
            nDigits = 2;
            a = i % 100;
            b = i / 100;

            a = i % 1000;
            b = i / 1000;
        }
        else if (i < 1000000) {
            nDigits = 3;
            a = i % 1000;
            b = i / 1000;

            nDigits = 4;
            a = i % 10000;
            b = i / 10000;
        }
        else {
            nDigits = 4;
            a = i % 10000;
            b = i / 10000;
        }

        //GetNumbers(i, a, b, nDigits);
        numbers[i] = a * a + b * b;
        //cout << "Debug: " << "Num= " << i << " a = " << a << " b= " << b << endl;
    }

    return 0;
}
