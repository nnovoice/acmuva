#include <stdio.h>
#include <climits>
using namespace std;

const unsigned int MAXNUMBERS = 1000000;
const unsigned int MAXSTACKNUMBERS = 300;
unsigned int cycles[MAXNUMBERS];
unsigned int numStack[MAXSTACKNUMBERS];
int index = 0;

unsigned int GetCycleCount (unsigned int n)
{

    unsigned int num = n;
    unsigned int cycleLen = 0;
    unsigned int stackNum = 0;
    while (1) {
        if (num < MAXNUMBERS && cycles[num] != 0) {
            cycleLen = cycles[num];
            while (index > 0) {
                stackNum = numStack[--index];
                ++cycleLen;
                if (stackNum < MAXNUMBERS) {
                    cycles[stackNum] = cycleLen;
                }
            }
            break; /// Gets us out of the loop
        }
        else {
            numStack[index] = num;
            ++index;
        }

        if ((num & 1) == 0)
            num /= 2;
        else {
          num *= 3;
          num += 1;
        }
    }

    return cycles[n];
}

int main()
{
////    [10] 5 16 8 4 2 1 {6}
////    [13] 40 20 10 5 16 8 4 2 1 {9}
////    [14] 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1 {17}
////    [19] 58 29 88 44 22 ... 2 1 {20}
////    [32] 16 8 4 2 1 {5}
////    [1] 4 2 1 {3}
  unsigned int maxCycleCount = 0;
  unsigned int numThatGeneratesMaxCycle = 0;
  cycles[1] = 3;
  cycles[2] = 1;
  for (unsigned int i = 3; i <= MAXNUMBERS; ++i) {
    cycles[i] = GetCycleCount(i);
    //printf("%u,%u\n", i, cycles[i]);
  }

  unsigned int m = 0, mOriginal = 0;
  unsigned int n = 0, nOriginal = 0;

  while (scanf("%u %u", &mOriginal, &nOriginal) != EOF) {
    if (mOriginal == 0 && nOriginal == 0) break;
    if (mOriginal > nOriginal) {
      m = nOriginal;
      n = mOriginal;
    }
    else {
      m = mOriginal;
      n = nOriginal;
    }

    maxCycleCount = 0;
    for (unsigned int i = m; i <= n; ++i) {
      if (maxCycleCount < cycles[i]) {
        maxCycleCount = cycles[i];
        numThatGeneratesMaxCycle = i;
      }
    }

    printf("Between %d and %d, %d generates the longest sequence of %d values.\n", mOriginal, nOriginal, numThatGeneratesMaxCycle, maxCycleCount);
  }
  return 0;
}
