#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <memory.h>
#include <cmath>
using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define FOR0(i,n) for( i = 0 ; i < n ; ++i )
#define FOR1(i,n) for( i = 1 ; i <= n ; ++i )
#define sys_p system( "pause" )
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define sz(a) (int)a.size()

typedef long long LL ;

int main() {
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;

    int n, r, c, x, m, a[20][20], i, j, cnt, cur, ans = (int)1e5 ;

    int T, _T ;
    cin >> T ;
    for( _T = 1 ; _T <= T ; ++_T ) {
        ans = (int)1e5 ;
        cin >> r >> c >> n ;
        m = (1<<(r*c)) - 1 ;
        for( x = 0 ; x <= m ; ++x ) {
            for( i = 0 ; i < r ; ++i )
                for (j = 0; j < c; ++j)
                    a[i][j] = (1 << (i * c + j)) & x;
            cur = cnt = 0 ;
            for( i = 0 ; i < r ; ++i )
                for( j = 0 ; j < c ; ++j )
                    if( a[i][j] )
                        ++cnt ;
            if( cnt != n )
                continue ;
            for( i = 0 ; i < r ; ++i )
                for( j = 0 ; j < c ; ++j )
                    if( a[i][j] ) {
                        if( i && a[i-1][j] )
                            ++cur ;
                        if( j && a[i][j-1] )
                            ++cur ;
                    }
            ans = min( ans, cur ) ;
        }

        cout << "Case #" << _T << ": " << ans << endl ;
    }
}