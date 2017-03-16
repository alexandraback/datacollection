#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int m[20000];

int main() {
	int T,ics = 0;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i=0;i<n;++i)
			cin >> m[i];
		int mxdt = m[0] - m[1];
		for(int i=2;i<n;++i)
			mxdt = max(mxdt,m[i-1]-m[i]);
		int y = 0;
		for(int i=1;i<n;++i) {
			int d = m[i-1] - m[i];
			if( d > 0 )
				y += d;
		}
		int z = 0;
		for(int i=0;i<n-1;++i) {
			if( m[i] >= mxdt )
				z += mxdt;
			else
				z += m[i];
		}
		printf("Case #%d: %d %d\n",++ics,y,z);
	}
	return 0;
}