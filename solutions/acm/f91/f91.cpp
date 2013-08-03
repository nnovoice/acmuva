#include <iostream>
using namespace std;

unsigned int f91(unsigned int num) {
    if (num > 100) {
        return num - 10;
    }

    return f91(f91(num + 11));
}

int main()
{
    unsigned int f91Num = 0;
    while (cin >> f91Num) {
        if (f91Num == 0) {
            break;
        }
        cout << "f91(" << f91Num << ") = ";
        cout << f91(f91Num) << endl;
    }
    return 0;
}
