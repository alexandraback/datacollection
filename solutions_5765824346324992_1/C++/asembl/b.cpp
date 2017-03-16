#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std ;
const int MAXN = 1001 ;
long long a[MAXN] ;
int n , b ;

long long cnt( long long time ) {
	long long ans = b ;
	for ( int i = 0 ; i < b ; ++i )
		ans += time / a[i] ;
	return ans ;
}


int main() {
	int T , test = 1 ;
	
	cin >> T ;
	while ( T-- ) {
		cout << "Case #" << test++ << ": " ;
		cin >> b >> n ;
		for ( int i = 0 ; i < b ; ++i )
			cin >> a[i] ;
		
		long long l = 0 , r = 100000000000001LL , mid ;
		while ( l < r ) {
			mid = (l+r)/ 2 ;
			if ( cnt(mid) < n )
				l = mid + 1 ;
			else
				r = mid ;
		}
		if ( l == 0 )
			cout << n << endl ;
		else {
			n -= cnt(l-1) ;
			for ( int i = 0 ; i < b ; ++i ) {
				if ( l % a[i] == 0 )
					n-- ;
				if ( n == 0 ) {
					cout << i+1 << endl ;
					break;
				}
			}
		}
	}
	
	return 0;
}