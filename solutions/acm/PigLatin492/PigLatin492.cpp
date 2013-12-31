#include <stdio.h>
const int MAXCHARS = 1024;

using namespace std;

bool IsLetter(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}

void PrintWord(char* word, int length)
{
    bool isVowel = false;
    if (length > 0) {
        switch (word[0]) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            isVowel = true;
            break;
        default:
            isVowel = false;
            break;
        }

        if (isVowel) {
            for (int i = 0; i < length; ++i)
                printf("%c", word[i]);
            printf("ay");
        }
        else {
            for (int i = 1; i < length; ++i) {
                printf("%c", word[i]);
            }
            printf("%c%c%c", word[0], 'a', 'y');
        }
    }
}

int main()
{
    ///This is the input.
    ///hisTay isay hetay inputay.
    char c = ' ';
    char prevChar = ' ';
    char word[MAXCHARS] = {'\0'};
    int index = 0;
    while (scanf("%c", &c) != EOF) {
        if (IsLetter(c))
        {
            word[index++] = c;
        }
        else {
            PrintWord(word, index);

            printf ("%c", c);

            index = 0;
        }
        prevChar = c;
    }

    if (IsLetter(prevChar)) {
        PrintWord(word, index);
    }
    return 0;
}
