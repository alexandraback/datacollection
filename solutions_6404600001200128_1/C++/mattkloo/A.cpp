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
	bool isSmall = false;
	if (isSmall) {
		//freopen("practice.txt","rt",stdin);
		freopen("A-small-attempt0.in","rt",stdin);
		freopen("A-small.out","wt",stdout);
	}
	else {
		freopen("A-large.in","rt",stdin);
		freopen("A-large.out","wt",stdout);
	}
	
	int T;
	cin >> T;
	
	int N;
	For(caseNum,1,T+1) {
		printf("Case #%d: ", caseNum);
		cin >> N;
		int m[N];
		For(i,0,N) {
			cin >> m[i];
		}
		
		long long total1 = 0, total2 = 0;
		For(i,1,N) {
			if (m[i] < m[i-1]) {
				total1 += m[i-1] - m[i];
			}
		}
		int maxRate = 0;
		For(i,1,N) {
			if (m[i-1]-m[i] > maxRate) {
				maxRate = m[i-1] - m[i];
			}
		}
		For(i,0,N-1) {
			if (maxRate > m[i]) {
				total2 += m[i];
			}
			else {
				total2 += maxRate;
			}
		}
		
		
		cout << total1 << " " << total2 << endl;
	}
	

	return 0;
	
}
