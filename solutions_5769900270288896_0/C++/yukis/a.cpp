#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long dig( long long x ) {
	long long t = 1 ;
	while ( x / t > 0 ) t *= 10 ;
	return t / 10 ;
}

long long dig2( long long x ) {
	long long t = 0 ;
	while ( x > 0 ) {
		x /= 10 ;
		t ++ ;
	}
	long long cici = 1 ;
	while ( t > 1 ) {
		cici *= 10 ;
		t -= 2 ;
	}
	return cici ;
}

long long reverse( long long x ) {
	long long cici = 0 ;
	while ( x > 0 ) {
		cici = cici * 10 + x % 10 ;
		x /= 10 ;
	}
	return cici ;
}

long long calc2( long long st , long long ed ) {
	if ( dig( st ) != dig( ed ) || st != dig( st ) ) 
		while ( 1 ) cout << "ERROR" << st << ' ' << dig( st ) << ' ' << ed << ' ' << dig( ed ) << endl;
	long long d = dig( st ) ;
	long long d2 = dig2( st ) ;
	long long cici ;
	if ( st == ed ) 
		return 0 ;
	if ( ed % 10 == 0 )
		return calc2( st , ed - 1 ) + 1 ;
	if ( d == 1 )
		cici = ed - st ;
	else {
		cici = 1 ;
		cici += reverse( ed / d2 ) ;
		cici += ed % d2 - 1 ;
		if ( cici > ed - st )
			cici = ed - st ;
	}
	// cout << st << ' ' << ed << ' ' << cici << endl;
	return cici ;
}

long long calc( long long st , long long ed ) {
	long long dst = dig( st ) ;
	long long ded = dig( ed ) ;
	if ( dst == ded )
		return calc2( st , ed ) ;
	else
		return calc2( st , dst * 10 - 1 ) + calc( dst * 10 , ed ) + 1 ;

}

int main() {
	freopen( "A-large.in" , "r" , stdin ) ;
	freopen( "A-large.out" , "w" , stdout ) ;
	int test_case ;
	cin >> test_case ;
	for ( int t = 1 ; t <= test_case ; t ++ ) {
		long long n ;
		cin >> n ;
		printf( "Case #%d: " , t ) ;
		cout << calc( 1 , n ) + 1 << endl;
	}
}