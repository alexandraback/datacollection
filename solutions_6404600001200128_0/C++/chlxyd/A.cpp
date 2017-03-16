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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u>>1;
int n , T ;
int a[1100] ;
int solve1() {
    int ans = 0 ;
    repf( i , 2 , n ) {
        if ( a[i] < a[i-1] )
            ans += a[i-1] - a[i] ;
    }
    return ans ;
}
int solve2() {
    int ans = 1000000000 ;
    repf( i , 0 , 10000 ) {
        int now = 0 ;
        repf( j , 2 , n ) {
            if ( a[j-1] - i > a[j] ) {
                now = -1 ;
                break ;
            }
            else {
                now += min( a[j-1] , i ) ;
            }
        }
        if ( now == -1 ) continue ;
        if ( ans > now ) ans = now ;
    }
    return ans ;
}
int main() {
    freopen("A.out","w",stdout) ;
    scanf("%d" , &T ) ;
    repf( t , 1 , T ) {
        memset(a,0,sizeof(a)) ;
        scanf("%d" , &n) ;
        repf( i , 1 , n ) 
            scanf("%d" , &a[i] ) ;
        printf("Case #%d: %d %d\n" ,t  , solve1() , solve2() ) ;
    }
    return 0;
}

