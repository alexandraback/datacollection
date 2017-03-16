#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std ;
const int MAXN = 1001 ;
int n ;
int a[MAXN] ;
int main() {
	int T , test = 1 ;
	
	cin >> T ;
	while ( T-- ) {
		cout << "Case #" << test++ << ": " ;
		
		cin >> n ;
		for ( int i = 0 ; i < n ; ++i )
			cin >> a[i] ;
		long long ans1 = 0 ;
		for ( int i = 0 ; i+1 < n ; ++i )
			if ( a[i] >= a[i+1] )
				ans1 += a[i] - a[i+1] ;
		
		long long ans2 = 0 , t2 = 0 ;
		for ( int i = 0 ; i+1 < n ; ++i )
			if ( a[i] >= a[i+1] )
				if ( a[i]-a[i+1]  > t2 )
					t2 = a[i]-a[i+1] ;
		
		for ( int i = 0 ; i+1 < n ; ++i )
			ans2 += min( (long long)a[i], t2 );
		cout << ans1 << ' ' << ans2 << endl ;
	}
	
	return 0;
}
