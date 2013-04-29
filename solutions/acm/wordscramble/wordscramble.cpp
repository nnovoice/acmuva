#include <iostream>
#include <cstdio>

using namespace std;

void printReverseWord(char* word, int endIndex) {
	for (int i = endIndex; i >= 0; --i) {
		cout << word[i];
	}
}

int main(int argc, char* argv[]) {
	char word[1025];
	char ch = ' ';
	int index = -1;
	int inputChar = 0;
	int retVal = 0;

	while (1) {
		retVal = scanf("%c", &inputChar);
		if (retVal == EOF) {
			printReverseWord(word, index);
			break;
		}
		else {
			ch = (char) inputChar;
			if (ch == ' ' || ch == '\n') {
				printReverseWord(word, index);
				cout << ch;
				index = -1;
			}
			else {
				word[++index] = ch;
			}
		}
	}

	return 0;
}