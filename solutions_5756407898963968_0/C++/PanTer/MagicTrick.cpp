#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

//freopen( "input.txt", "r", stdin );
//freopen( "output.txt", "w", stdout );
//fflush( stdin );

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 //1 Billon
#define EPS 1e-9
#define MOD 1000000007
#define WHITE -1
#define BLACK 1
#define GRAY 2

//int num_length( int n ) { return int( log10( n ) ) + 1; }
int gcd( int a, int b ){ return b == 0 ? a : gcd( b, a % b ); }
int lcm( int a, int b ){ return a * ( b / gcd( a, b ) ); }
//int toi( string a ){ int ans;  sscanf(a.c_str(),"%d",&ans);  return ans;  }
//string tos( int a ){ ostringstream st; st<<a; string ans = st.str(); return ans; }

#define FOR(i,a,b) for(int i=(a), _b=(b);i<=_b;i++)
#define DOW(i,b,a) for(int i=(b), _a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define mem(A,x) memset(A, x, sizeof A)
#define pb push_back
#define all(A) A.begin(),A.end()
#define sci(x) scanf("%d",&x)
#define scs(x) gets(x);

int main( void )
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    int t, r1, r2, icase = 0, V[ 16 ], num;
    sci( t );
    while( t-- ){
        mem( V, 0 );
        printf( "Case #%d: ", ++icase );
        sci( r1 );
        REP( i, 4 )
            REP( j, 4 ){
                sci( num );
                if( i == r1 - 1 ) V[ num ]++;
            }
        sci( r2 );
        REP( i, 4 )
            REP( j, 4 ){
                sci( num );
                if( i == r2 - 1 ) V[ num ]++;
            }
        int count = 0;
        REP( i, 16 ) if( V[ i ] == 2 ){ count++; num = i; }
        if( count == 0 ) printf( "Volunteer cheated!\n" );
        if( count == 1 ) printf( "%d\n", num );
        if( count >= 2 ) printf( "Bad magician!\n" );
    }
    return 0;
}
