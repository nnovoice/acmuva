#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char* argv[]) 
{
	char input = ' ';
	char actual[] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', \
					 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\', \
					 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', \
					 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', ' ', '\n'};
	char repl[]   = {'@', '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-',/* '='*/ \
					 '@', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']',/* '\\'*/ \
					 '@', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', /*'\''*/ \
					 '@', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', ' ', '\n'/*'/'*/};
	// charcters: `, Q, A, Z will not appear in the input. Also, no lower case letters
	map<char, char> charMap;
	int arrSize = sizeof(actual);
	for (int i = 0; i < arrSize; ++i) {
		charMap[actual[i]] = repl[i];
	}

	while (scanf("%c", &input) != EOF) {
		printf("%c", charMap[input]);
	}

	return 0;
}