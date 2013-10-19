#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int nParties = 0;
    int nGuesses = 0;
    cin >> nParties >> nGuesses;

    string partyName;
    int votePercentage;
    int tensValue = 0;
    int decimalValue = 0;
    map<string, int> partyVotePercentagesMap;

    for (int i = 0; i < nParties; ++i) {
        cin >> partyName;

        scanf("%d.%d", &tensValue, &decimalValue);
        votePercentage = 10 * tensValue + decimalValue;
        partyVotePercentagesMap[partyName] = votePercentage;
    }

    int total = 0.0;
    string operation;
    int guessVotePercentage = 0.0;
    bool guess = false;

    for (int j = 0; j < nGuesses; ++j) {
        guess = false;
        total = 0.0;

        //  A guess has the form P1 + P2 + ... + Pk COMP n
        while (true) {
            cin >> partyName;
            //cout << partyName << " ";

            total += partyVotePercentagesMap[partyName];

            cin >> operation;
            //cout << " " << operation;

            if (operation == "+") continue;
            else break;
        }


        scanf("%d", &guessVotePercentage);
        guessVotePercentage *= 10;
        //cout << " " << guessVotePercentage << " " << endl;
        //cout << "Debug: " << "total= " << total << " op " << operation << " guess= " << guessVotePercentage << endl;

        // comparison operators <, >, <=, >= or =
        if (operation == "=") {
            if ((total - guessVotePercentage) == 0)
                guess = true;
        }
        else if (operation == "<") {
            if (total < guessVotePercentage)
                guess = true;
        }
        else if (operation == "<=") {
            if (total <= guessVotePercentage)
                guess = true;
        }
        else if (operation == ">") {
            if (total > guessVotePercentage)
                guess = true;
        }
        else if (operation == ">=") {
            if (total >= guessVotePercentage)
                guess = true;
        }

        cout << "Guess #" << (j + 1) << " was ";
        if (guess)
            cout << "correct." << endl;
        else
            cout << "incorrect." << endl;
    }

    return 0;
}
