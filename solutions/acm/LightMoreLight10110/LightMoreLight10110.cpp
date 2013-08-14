#include <iostream>
#include <bitset>

using namespace std;

const unsigned long int MAXBULBS = 4294967295;
bitset<MAXBULBS> switchStates;

int main()
{
    unsigned int num = 0;
    switchStates.reset();
    while (cin >> num) {
        if (num == 0)
            break;

        switchStates.reset(num);
        for (unsigned long i = 1; i <= num; ++i) {
            for (unsigned long j = 1; j <= num; j += i) {
                if ((j % i) == 0)
                    switchStates.flip(j);
            }
        }
        if (switchStates.test(num) == true)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
