#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int a[1010];

int main() {
        freopen( "b.in", "r", stdin );
        freopen( "b.out", "w", stdout );

        int T;
        cin >>T;
        for ( int cas = 1; cas <= T; cas ++ ) {
                scanf( "%d", &n );
                int ret = 0, Max = 0;
                for ( int i = 1; i <= n; i ++ ) {
                        scanf( "%d", &a[i] );
                        if ( i >= 2 ) {
                                if ( a[i - 1] - a[i] >= 0 ) {
                                        ret += a[i - 1] - a[i];
                                        Max = max( Max, a[i - 1] - a[i] );
                                }
                        }
                }

                printf( "Case #%d: %d ", cas, ret );
                ret = 0;
                for ( int i = 1; i < n; i ++ ) {
                        ret +=  min( a[i], Max );
                }

                cout <<ret<<endl;
        }

        return 0;
}




