#include <iostream>
#include <string.h>

using namespace std;

const int MAXCHARS = 1025;

int main()
{
    int nCases = 0;
    char paranthesisStack[MAXCHARS] = {' '};
    int top = 0;
    char input[MAXCHARS] = {' '};
    int inputLength = 0;
    bool error = false;

    cin >> nCases;
    cin.getline (input, MAXCHARS); // eat extra line!

    for (int i = 0; i < nCases; ++i) {
        error = false;
        top = 0;

        cin.getline (input, MAXCHARS);
        //cout << "Debug: " << input << endl;
        inputLength = strlen(input);

        for (int j = 0; j < inputLength; ++j) {
            if (input[j] == '(' || input[j] == '[') {
                paranthesisStack[top++] = input[j];
            }
            else {
                if (input[j] == ')') {
                    error = (paranthesisStack[top - 1] == '(') ? false : true;
                }
                else if (input[j] == ']') {
                    error = (paranthesisStack[top - 1] == '[') ? false : true;
                }

                if (error == false) {
                    paranthesisStack[top] = ' ';
                    --top;
                }
                else {
                    break;
                }
            }
        }
        if (error == true)
            cout << "No" << endl; // imbalance in parantheses
        else {
            if (top == 0)
                cout << "Yes" << endl; // parantheses are balanced
            else
                cout << "No" << endl; // imbalance in parantheses
        }
    }

    return 0;
}
