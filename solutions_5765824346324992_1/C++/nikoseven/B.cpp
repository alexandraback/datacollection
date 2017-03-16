#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int B;
long long n;
int m[2000];

long long count(long long t) {
	long long s = 0;
	for(int i=0;i<B;++i) {
		s += t / m[i];
		if( t % m[i] )
			++s;
	}
	return s;
}

bool stillWating(long long t) {
	long long s = 0;
	for(int i=0;i<B;++i) {
		s += t / m[i];
		if( t % m[i] )
			++s;
		if( s >= (n) )
			return false;
	}
	return s < n;
}

int main() {
	int T,ics = 0;
	cin >> T;
	while(T--) {
		cin >> B >> n;
		for(int i=0;i<B;++i)
			cin >> m[i];
		int mi = m[0];
		stillWating(5000000000LL-1);
		for(int i=1;i<B;++i)
			mi = min(mi,m[i]);
		
		long long l=0,r=(long long)mi*n+1;
		
		while( l<r ) {
			long long m = (l+r)/2;
			if( stillWating(m) ) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		int ans = -1;
		long long g = count(l-1);
		for(int i=0;i<B;++i) {
			if( (l-1) % m[i] == 0 ) {
				if( g+1 == n ) {
					ans = i+1;
					break;
				}
				else {
					++g;
				}
			}
		}
		printf("Case #%d: %d\n",++ics,ans);
	}
	return 0;
}
