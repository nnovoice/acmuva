#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

const double EPSILON = 1e-9;

int main()
{
    int nParties = 0;
    int nGuesses = 0;
    cin >> nParties >> nGuesses;

    string partyName;
    double votePercentage;
    map<string, double> partyVotePercentagesMap;

    for (int i = 0; i < nParties; ++i) {
        cin >> partyName >> votePercentage;
        partyVotePercentagesMap[partyName] = votePercentage;
    }

    double total = 0.0;
    string operation;
    double guessVotePercentage = 0.0;
    bool guess = false;

    for (int j = 0; j < nGuesses; ++j) {
        guess = false;
        total = 0.0;

        //  A guess has the form P1 + P2 + ... + Pk COMP n
        while (true) {
            cin >> partyName;

            total += partyVotePercentagesMap[partyName];

            cin >> operation;

            if (operation == "+") continue;
            else break;
        }

        cin >> guessVotePercentage;
        //cout << "Debug: " << "total= " << total << " op " << operation << " guess= " << guessVotePercentage << endl;

        // comparison operators <, >, <=, >= or =
        if (operation == "=") {
            if (fabs(total - guessVotePercentage) <= EPSILON)
                guess = true;
        }
        else if (operation == "<") {
            if (total < guessVotePercentage)
                guess = true;
        }
        else if (operation == "<=") {
            if (total < guessVotePercentage)
                guess = true;
            else {
                if (fabs(total - guessVotePercentage) <= EPSILON)
                    guess = true;
            }
        }
        else if (operation == ">") {
            if (total > guessVotePercentage)
                guess = true;
        }
        else if (operation == ">=") {
            if (total > guessVotePercentage)
                guess = true;
            else {
                if (fabs(total - guessVotePercentage) <= EPSILON)
                    guess = true;
            }
        }

        cout << "Guess# " << (j + 1) << " was ";
        if (guess)
            cout << "correct." << endl;
        else
            cout << "incorrect." << endl;
    }

    return 0;
}
