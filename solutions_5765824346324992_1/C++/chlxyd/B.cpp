#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repf(i, a, b) for (long long i = (a); i <= (b); ++i)
#define repd(i, a, b) for (long long i = (a); i >= (b); --i)
long long n , T ;
long long k ;
long long a[1100] ; 
long long solve(long long tt) {
    long long ret = 0 ;
    repf( i , 1 , n ) {
        if ( tt % a[i] == 0 )
            ret += tt / a[i] ;
        else ret += tt / a[i] + 1 ;
    }
    return ret ;
}
long long cal() {
    long long l = 0 , r = 110000LL * k ;
    while ( l < r ) {
        long long mid = ( l + r ) / 2 ;
        long long now = solve(mid) ;
        if ( now < k )
            l = mid ;
        else r = mid ;
        if ( r - l == 1 ) {
            if ( solve(r) < k )
                return r ;
            return l ;
        }
    }
    return r ;
}
int main() {
    freopen("B.out","w",stdout) ;
    scanf("%lld" , &T ) ;
    repf( t , 1 , T ) {
        scanf("%lld %lld" , &n , &k ) ;
        repf( i , 1 , n ) 
            scanf("%lld" , &a[i] ) ;
        long long tt = cal() ;
        //cout<<tt<<endl;
        long long left = k - solve(tt) ;
        //cout<<left<<endl;
        long long ret = -1 ;
        repf( i , 1 , n ) {
            if ( tt % a[i] == 0 )
                left -- ;
            if ( left == 0 ) {
                ret = i ;
                break ;
            }
        }
        printf("Case #%lld: %lld\n" ,t , ret ) ;
    }
    return 0;
}

