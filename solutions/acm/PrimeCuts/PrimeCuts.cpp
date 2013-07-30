/* @JUDGE_ID: 44823RT 406 C++  */
// attempt
// 1: failed for 1000 1000 input. should not have submitted with this bug.
// 2: failed, probably due to the center of the list calculation. have to find out.
//    2: failed because C*2 and C*2-1 if greater than num_primes, was printing junk.
// 3: another failed attempt. i have to subdue my urge to submit solutions :-)

#include <iostream>
using namespace std;

const int NUMMAX = 1000;
int primes[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                73, 79, 83, 89, 97, 101, 103, 107, 109,
                113, 127, 131, 137, 139, 149, 151, 157,
                163, 167, 173, 179, 181, 191, 193, 197,
                199, 211, 223, 227, 229, 233, 239, 241,
                251, 257, 263, 269, 271, 277, 281, 283,
                293, 307, 311, 313, 317, 331, 337, 347,
                349, 353, 359, 367, 373, 379, 383, 389,
                397, 401, 409, 419, 421, 431, 433, 439,
                443, 449, 457, 461, 463, 467, 479, 487,
                491, 499, 503, 509, 521, 523, 541, 547,
                557, 563, 569, 571, 577, 587, 593, 599,
                601, 607, 613, 617, 619, 631, 641, 643,
                647, 653, 659, 661, 673, 677, 683, 691,
                701, 709, 719, 727, 733, 739, 743, 751,
                757, 761, 769, 773, 787, 797, 809, 811,
                821, 823, 827, 829, 839, 853, 857, 859,
                863, 877, 881, 883, 887, 907, 911, 919,
                929, 937, 941, 947, 953, 967, 971, 977,
                983, 991, 997};

int main()
{
	int N = 0, C = 0;
	int i = 0, num_primes = 0;

	int ninputs = 0;
	while ( cin >> N >> C )
	{
		if ( ninputs++ ) // put endl only after 1 input
			cout << endl;

		cout << N << " " << C << ":";

		// find the number of primes <= N
		for ( i = 0; primes[i] <= N; ++i)
			; // at the end, i equals number of primes <= N

		num_primes = i;
		if ( C >= num_primes || ( (2*C) >= num_primes ) || ( (2*C-1) >= num_primes) ) // print full list?
		{
			for ( int j = 0; j < num_primes; ++j )
				cout << " " << primes[j];
		}
		else if ( !( num_primes % 2 ) )
		{
			int mid = num_primes / 2;
			int start = mid - 1;
			int end = mid;

			for ( int j = 1; j < C ; ++j )
			{
				--start;
				++end;
			}

			for ( int j = start; j <= end; ++j )
				cout << " " << primes[j];
		}
		else
		{
			int mid = num_primes / 2;
			int start = mid, end = mid;

			for ( int j = 1; j < C ; ++j )
			{
				--start;
				++end;
			}
			for ( int j = start; j <= end; ++j )
				cout << " " << primes[j];
		}
		cout << endl;
	}
	return 0;
}
