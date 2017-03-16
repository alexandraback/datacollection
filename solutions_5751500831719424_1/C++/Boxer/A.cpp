#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) v.size()

typedef vector< string > vs;
typedef vector< int > vi;
typedef vector< vi > vvi;

void fix( string &s ){
	int n = unique( all( s ) ) - s.begin();
	s.resize( n );
}
int solve( vi &v ){
	sort( all( v ) );
	int n = v.size() , ans = 0;
	REP( i , n ) ans += abs( v[ i ] - v[ n / 2 ] );
	return ans;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases , n;
	cin >> cases;
	REP( tc , cases ){
		
		cin >> n;
		vs v( n ) , w( n );
		REP( i , n ) {
			cin >> v[ i ];
			w[ i ] = v[ i ];
			fix( w[ i ] );
		}
		set< string > SET( all( w ) );
		if( SET.size() != 1 ){
			cout << "Case #" << tc + 1 << ": Fegla Won\n" ;
			continue;
		}
		int ans = 0;
		vvi mat( n );
		REP( k , n ){
			//cout << v[ k ] << endl;
			vi vec;
			for( int i = 0 ; i < SZ( v[ k ] ) ; ++i ){
				int ind;
				for( int j = i ; j < SZ( v[ k ] ) ; ++j )
					if( v[ k ][ i ] == v[ k ][ j ] ) ind = j;
					else break;
				vec.pb( ind - i + 1 );
				i = ind;
			}
			mat[ k ] = vec;
		}
		int m = mat[ 0 ].size();
		REP( j , m ){
			vi vec;
			REP( i , n ) vec.pb( mat[ i ][ j ] );
			ans += solve( vec );
			
		}
		cout << "Case #" << tc + 1 << ": " << ans << "\n";;
	}
}

