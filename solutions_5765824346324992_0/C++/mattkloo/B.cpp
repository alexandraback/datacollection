#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

#define For(i,m,n) for(int i=m; i<n; i++)


int main() {
	bool isSmall = true;
	if (isSmall) {
		//freopen("practice.txt","rt",stdin);
		freopen("B-small-attempt1.in","rt",stdin);
		freopen("B-small.out","wt",stdout);
	}
	else {
		freopen("B-large-practice.in","rt",stdin);
		freopen("B-large.out","wt",stdout);
	}
	
	int T;
	cin >> T;
	
	int N, B;
	For(caseNum,1,T+1) {
		printf("Case #%d: ", caseNum);
		cin >> B >> N;
		int M[B];
		int A[B];
		int prod = 1;
		For(i,0,B) {
			cin >> M[i];
			prod *= M[i];
			A[i] = 0;
		}
		int total = 0;
		For(i,0,B) {
			total += prod/M[i];
		}
		N = N%total;
		if (N == 0) N = total;
		int s = 1;
		int y;
		while (s <= N) {
			For(i,0,B) {
				if (A[i] > 0) A[i]--;
				if (A[i] == 0) {
					if (s == N) {
						y = i+1;
						goto END;
					}
					A[i] = M[i];
					s++;
				}
			}
		}
		
		END:;
		
		
		cout << y << endl;
	}
	

	return 0;
	
}
