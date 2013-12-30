#include <stdio.h>
#include <map>

const int MAXCHARS = 31;

using namespace std;

int main(int argc, char* argv[])
{
	char telephoneNum[MAXCHARS] = {'\0'};
	char actual[] = {'A', 'B', 'C',
                     'D', 'E', 'F',
                     'G', 'H', 'I',
                     'J', 'K', 'L',
                     'M', 'N', 'O',
					 'P', 'Q', 'R', 'S',
					 'T', 'U', 'V',
					 'W', 'X', 'Y', 'Z',
					 '0', '1', '-'};
	char repl[]   = {'2', '2', '2',
                     '3', '3', '3',
                     '4', '4', '4',
                     '5', '5', '5',
					 '6', '6', '6',
					 '7', '7', '7', '7',
					 '8', '8', '8',
					 '9', '9', '9', '9',
					 '0', '1', '-'};

	map<char, char> charMap;
	int arrSize = sizeof(actual);
	for (int i = 0; i < arrSize; ++i) {
		charMap[actual[i]] = repl[i];
	}

	while (scanf("%s", telephoneNum) != EOF) {
		for(int i = 0; telephoneNum[i] != '\0'; ++i) {
            printf("%c", charMap[telephoneNum[i]]);
		}
		printf("\n");
	}

	return 0;
}
