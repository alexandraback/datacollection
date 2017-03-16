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
		freopen("C-small-attempt2.in","rt",stdin);
		freopen("C-small.out","wt",stdout);
	}
	else {
		freopen("C-large-practice.in","rt",stdin);
		freopen("C-large.out","wt",stdout);
	}
	
	int T;
	cin >> T;
	
	int N;
	For(caseNum,1,T+1) {
		printf("Case #%d: ", caseNum);
		cin >> N;
		long long x[N], y[N];
		For(i,0,N) {
			cin >> x[i] >> y[i];
		}
		
		int S1, S2, S0, Smin;
		cout << endl;
		For(i,0,N) {
			Smin = N;
			For(j,0,N) {
				if (j != i) {
					S0 = 0;
					S1 = 0;
					S2 = 0;
					For(k,0,N) {
						if (k!= i && k!=j) {
							if ( (x[i]-x[j])*(y[k]-y[j])-(y[i]-y[j])*(x[k]-x[j]) < 0 ) S1++;
							else if ( (x[i]-x[j])*(y[k]-y[j])-(y[i]-y[j])*(x[k]-x[j]) > 0 ) S2++;
							else if ( (x[i]-x[j])*(y[k]-y[j])-(y[i]-y[j])*(x[k]-x[j]) == 0 ) S0++;
						}
					}
					if (S1 < Smin) Smin = S1;
					if (S2 < Smin) Smin = S2;
					if (Smin == 0) break;
				}
			}
			if (N<=3) {
				cout << 0 << endl;
			}
			else{
			cout << Smin << endl;
		}
		}
		
		
		
	}
	

	return 0;
	
}
