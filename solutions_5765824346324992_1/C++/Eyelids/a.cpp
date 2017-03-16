#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
int n, m;
LL a[1010];
LL calc( LL t ) {
        LL ret = 0;
        for ( int i = 1; i <= m; i ++ ) {
                ret += ( t / a[i] ) + 1;
        }
        return ret;
}

int main() {
        freopen( "b.in", "r", stdin );
        freopen( "b.out", "w", stdout );

        int T;
        cin >>T;
        for ( int cas = 1; cas <= T; cas ++ ) {
                LL L = 0, R = (LL)1e15, M;
                cin >>m>>n;
                for ( int i = 1; i <= m; i ++ ) cin >>a[i];

                LL ans = -1;
                while ( L <= R ) {
                        M = ( L + R ) >> 1;
                        LL tmp = calc( M );
                        if ( tmp >= n ) {
                                ans = M;
                                R = M - 1;
                        } else {
                                L = M + 1;
                        }
                }
                //cout <<ans<<endl;

                int ret = 1;
                int tmp = calc( ans ), cnt = 0;
                tmp -= n;

                for ( int i = m; i >= 1; i -- ) {
                        if ( ans % a[i] == 0 ) {
                                if ( tmp == cnt ) {
                                        ret = i;
                                        break;
                                }
                                cnt ++;
                        }
                }

                printf( "Case #%d: %d\n", cas, ret );
        }

        return 0;
}




