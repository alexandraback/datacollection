#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std ;
const int MAXN = 5001 ;
const double eps = 1e-9;
int n ;
struct Point {
	int x , y ;
	Point( ) {}
	Point ( int _x, int _y ) {
		x = _x , y = _y ;
	}
	bool operator < ( const Point b ) const {
		return atan2(y,x) + eps < atan2(b.y,b.x);
	}
	
	void out() {
		cout << x << ' ' << y <<endl ;
	}
}a[MAXN];
vector<Point> b ;

Point operator - ( Point a , Point b ) {
	return Point( a.x-b.x, a.y-b.y );
}
long long operator * ( Point a , Point b ) {
	return (long long)a.x*b.y - (long long)a.y*b.x ;
}

int main() {
	int T , test = 1 ;
	
	cin >> T ;
	while ( T-- ) {
		cout << "Case #" << test++ << ":" << endl  ;
cerr << T << endl ;
		cin >> n ;
		for ( int i = 0 ; i < n ; ++i ) {
			int x , y ;
			cin >> x >> y ;
			a[i] = Point(x,y);
		}
		
		for ( int i = 0 ; i < n ; ++i ) {
			
			b.clear();
			for ( int j = 0 ; j < n ; ++j ) {
				if ( j != i )
					b.push_back( a[j]-a[i] );
			}
			sort( b.begin(), b.end() );
			
			int t = b.size() ;
			
			for ( int j = 0 ; j < t ; ++j )
				b.push_back( b[j] ) ;
			
			int ans = t ;
			for ( int l = 0, r = 0 ; l < t ; ++l ) {
				r = max( l+1 , r ) ;
				while ( b[l]*b[r] > 0 && r-l < t ) ++r ;
				ans = min( ans , r-l-1 ) ;
			}
			cout << ans << endl ;
		}
	}
	
	return 0;
}
