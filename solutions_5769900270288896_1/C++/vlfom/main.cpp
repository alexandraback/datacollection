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

int n, p, r, c, a[106][10006], i, j, ans, cnt, cur ;

int solve1( int T ) {
    FOR1(i,r)
        FOR1(j,c)
            a[i][j] = T ;

    ans = 2*r*c-r-c ;
    p = r*c ;

    for( cur = 4 ; cur >= 1 ; --cur )
        FOR1(i,r)
            FOR1(j,c)
                if( p > n && a[i][j] ) {
                    cnt = (a[i-1][j]==T) + (a[i+1][j]==T) + (a[i][j-1]==T) + (a[i][j+1]==T) ;
                    if( cnt == cur ) {
                        a[i][j] = 0;
                        ans -= cur;
                        p--;
                    }
                }

    return ans ;
}

int solve2( int T ) {
    FOR1(i,r)
        FOR1(j,c)
            a[i][j] = T ;

    ans = 2*r*c-r-c ;
    p = r*c ;

    FOR1(i,r)
        FOR1(j,c)
            if( p > n && a[i][j] ) {
                cnt = (a[i-1][j]==T) + (a[i+1][j]==T) + (a[i][j-1]==T) + (a[i][j+1]==T) ;
                if( cnt >= 3 && (i+j)%2 ) {
                    a[i][j] = 0;
                    ans -= cnt;
                    p--;
                }
            }

    for( cur = 4 ; cur >= 1 ; --cur )
        FOR1(i,r)
            FOR1(j,c)
                if( p > n && a[i][j] ) {
                    cnt = (a[i-1][j]==T) + (a[i+1][j]==T) + (a[i][j-1]==T) + (a[i][j+1]==T) ;
                    if( cnt == cur ) {
                        a[i][j] = 0;
                        ans -= cur;
                        p--;
                    }
                }

    return ans ;
}

int main() {
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;

    int T, _T ;
    cin >> T ;
    for( _T = 1 ; _T <= T ; ++_T ) {
        cout << "Case #" << _T << ": ";

        cin >> r >> c >> n;

        if (r > c)
            swap(r, c);

        cout << min( solve1(_T), solve2(_T) ) << endl ;
    }
}