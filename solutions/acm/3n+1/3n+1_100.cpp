#include <stdio.h>

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
        else { /// num = (3 * num) + 1
          num *= 3;
          num += 1;
        }
    }

    return cycles[n];
}

unsigned collatz_aux(unsigned n, unsigned count)
{
      if (n == 1)
           return count;
      else if (n % 2 == 0)
           return collatz_aux(n / 2, count + 1);
      else
           return collatz_aux(3 * n + 1, count + 1);
}
int main()
{
  unsigned int maxCycleCount = 0;
  cycles[1] = 1;
  for (unsigned int i = 2; i <= MAXNUMBERS; ++i) {
    cycles[i] = collatz_aux(i, 0) + 1;
    //printf("%u,%u\n", i, cycles[i]);
  }

  unsigned int m = 0, mOriginal = 0;
  unsigned int n = 0, nOriginal = 0;

  while (scanf("%u %u", &mOriginal, &nOriginal) != EOF) {
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
      if (maxCycleCount < cycles[i])
        maxCycleCount = cycles[i];
    }

    printf("%u %u %u\n", mOriginal, nOriginal, maxCycleCount);
  }
  return 0;
}
