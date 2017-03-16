#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <bitset>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef double db;
typedef long long LL;
typedef pair< int, int > PII;
typedef pair< LL, LL > PLL;
typedef pair< db, db > PDD;

const db dInf = 1E90;
const LL lInf = ( LL ) 1E16;
const int Inf = 0x23333333;
const int N = 35;

#define it iterator
#define rbg rbegin()
#define ren rend()
#define fdi( i, x ) for ( typeof( x.rbg ) i=x.rbg; i!=x.ren; ++i )
#define foi( i, x ) for ( typeof( x.begin() ) i=x.begin(); i!=x.end(); ++i )
#define fd( i, y, x ) for ( int i=( y )-1, LIM=x; i>=LIM; --i )
#define fo( i, x, y ) for ( int i=x, LIM=y; i<LIM; ++i )
#define mkp( A, B ) make_pair( A, B )
#define pub( x ) push_back( x )
#define pob( x ) pop_back( x )
#define puf( x ) push_front( x )
#define pof( x ) pop_front( x )
#define fi first
#define se second

int n, sum;
int a[N];

void preprocessing()
{
	scanf( "%d", &n );
	fo ( i, 0, n ) scanf( "%d", &a[i] ), sum += a[i];
}

void solve()
{
	while ( sum )
	{
		int ma = -1, sema = -1, mnum, smnum;
		fo ( i, 0, n )
			if ( a[i] > ma ) smnum = mnum, sema = ma, ma = a[i], mnum = i;
			else if ( a[i] > sema ) sema = a[i], smnum = i;

		if ( ma==sema && ma+sema==sum )
		{
			printf( " %c%c", mnum+'A', smnum+'A' ), sum -= 2;
			--a[ mnum ], --a[ smnum ];
			continue;
		}
		printf( " %c", 'A'+mnum ), --sum, --a[ mnum ];
	}
	printf( "\n" );
}

int main()
{
	freopen( "yist.in", "r", stdin );
	freopen( "yist.out", "w", stdout );

	int T; scanf( "%d", &T );
	fo ( Case, 0, T )
	{
		preprocessing();
		printf( "Case #%d:", Case+1 );
		solve();
	}

	fclose( stdin ), fclose( stdout );
	return 0;
}

