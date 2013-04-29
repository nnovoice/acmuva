#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char* argv[]) 
{
	int targetHeight = 0;
	int climbingHeight = 0;
	int slidingHeight = 0;
	int fatigueFactor = 0;
	int day = 0;
	int climbedHeight = 0;
	int totalHeight = 0;

	int fatigueDist = 0;

	freopen("C:\\data\\personal\\programming\\acm\\input_files\\thesnail573\\input.txt", "r", stdin); 

	while (cin >> targetHeight >> climbingHeight >> slidingHeight >> fatigueFactor) {
		if (targetHeight == 0) {
			break;
		}

		fatigueDist = fatigueFactor * climbingHeight;

		day = 0;
		totalHeight = climbingHeight;
		if (totalHeight >= targetHeight) {
			cout << "success on day " << ++day << endl;
			break;
		}

		targetHeight *= 100;
		climbingHeight *= 100;
		slidingHeight *= 100;
		totalHeight *= 100;
		climbedHeight = climbingHeight;

		while (totalHeight > 0) {
			++day;
			
			climbedHeight = (climbedHeight - fatigueDist);
			if (climbedHeight < 0)
				climbedHeight = 0;

			totalHeight += climbedHeight;
			
			if (totalHeight >= targetHeight) {
				break;
			}
			
			totalHeight -= slidingHeight;
		}
		
		if (totalHeight > 0) {
			cout << "success on day " << day << endl;
		}
		else {
			cout << "failure on day " << day << endl;
		}
	}
	return 0;
}