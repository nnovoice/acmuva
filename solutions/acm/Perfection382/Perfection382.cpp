#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num = 0;
    int divisorsSum = 0;
    int numToEnd = 0;

    cout << "PERFECTION OUTPUT" << endl;

    while (cin >> num) {
        if (num == 0) {
            cout << "END OF OUTPUT" << endl;
            break;
        }
        if (num == 1) {
            cout << std::right << std::setw(5) << num << "  " << "DEFICIENT" << endl;
            continue;
        }

        divisorsSum = 0;
        numToEnd = num / 2;
        for (int i = 1; i <= numToEnd; ++i) {
            if ((num % i) == 0) {
                divisorsSum += i;
            }
        }

        cout << std::right << std::setw(5) << num << "  ";

        if (divisorsSum == num) {
            cout << "PERFECT" << endl;
        }
        else if (divisorsSum < num) {
            cout << "DEFICIENT" << endl;
        }
        else {
            cout << "ABUNDANT" << endl;
        }
    }
    return 0;
}
