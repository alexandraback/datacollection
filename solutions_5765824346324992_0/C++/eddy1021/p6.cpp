// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009int
#define mod7 1000000007int 
#define INF 1023456789int
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 1010
ll n , b , m[ N ];
void build(){

}
void init(){
    b = getint(); n = getint();
    for( int i = 1 ; i <= b ; i ++ )
        m[ i ] = getint();
}
ll cal( ll now ){
    ll sum = 0;
    for( int i = 1 ; i <= b ; i ++ )
        sum += ( now / m[ i ] ) + ( now % m[ i ] != 0 );
    return sum;
}
void solve(){
    ll l = 0 , r = n * 100000ll , mid , ans = n * 100000ll;
    while( l <= r ){
        mid = ( l + r ) >> 1;
        if( cal( mid ) < n ) ans = mid , l = mid + 1;
        else r = mid - 1;
    }
    ll got = cal( ans );
    for( int i = 1 ; i <= b ; i ++ )
        if( ans % m[ i ] == 0 ){
            got ++;
            if( got == n ){
                printf( "Case #%d: %d\n" , ++ cs , i );
                return;
            }
        }
}
int main(){
    build();
    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
