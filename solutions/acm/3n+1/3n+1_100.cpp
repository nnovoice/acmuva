#include <stdio.h>

const unsigned int MAXNUMBERS = 1000000;
unsigned int cycles[MAXNUMBERS];

unsigned int GetCycleCount (unsigned int num)
{
  unsigned int cycleLen = 1;
  while (num != 1) {
    if ((num & 1) == 0)
      num /= 2;
    else {
      num *= 3;
      num += 1;

    }
    ++cycleLen;
  }
    return cycleLen;
}

int main()
{
  unsigned int maxCycleCount = 0;
  cycles[1] = 1;
  for (unsigned int i = 2; i <= MAXNUMBERS; ++i) {
    cycles[i] = GetCycleCount(i);
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
