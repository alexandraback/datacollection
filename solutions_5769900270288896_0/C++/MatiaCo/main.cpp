#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;


int main (int argc, char * const argv[]) {
    int ncases, cases, run;
	int R, C, N;
		
	cin >> ncases;
	
	
	for (cases = 0; cases < ncases; cases++) {
		cout << "Case #" << cases + 1 << ": ";

		cin >> R >> C >> N;
		
		cout << max(3*N - (R-1)*(C-1), 0) << endl;
	}
	
    return 0;
}
