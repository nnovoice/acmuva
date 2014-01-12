#include <stdio.h>
#include <string>
#include <string.h>
#include <list>
using namespace std;

enum Mode {Home, End};

void PrintWords (list<string>& words)
{
    list<string>::iterator li = words.begin();
    list<string>::iterator le = words.end();
    for (; li != le; ++li) {
        printf("%s", (*li).c_str());
    }
    printf("\n");
}

void InsertWord (list<string>& words, string& word, Mode mode)
{
    if (mode == End) {
        words.push_back(word);
    }
    else {
        words.push_front(word);
    }
}

int main()
{
    list<string> words;
    string word;
    char c = ' ';
    Mode mode = End;

    while (scanf("%c", &c) != EOF) {
        switch(c) {
        case '[':
        case ']':
            if (word.size() > 0) {
                InsertWord(words, word, mode);
                word.clear();
            }
            mode = (c == '[') ? Home : End;
            break;
        case '\n':
            if (word.size() > 0)
                InsertWord(words, word, mode);
            PrintWords(words);
            words = list<string>();
            word.clear();
            mode = End;
            break;
        default:
            word += c;
            //printf("%c", c);
            break;
        }
    }

    //printf ("Debug: %s num words=%d\n", word.c_str(), words.size());

    if (words.size() > 0) {
        if (word.size() > 0)
            InsertWord(words, word, mode);
        PrintWords(words);
    }
    return 0;
}
