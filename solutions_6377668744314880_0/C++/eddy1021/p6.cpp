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
#define N 3010
int n;
D x[ N ] , y[ N ];
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%lf%lf" , &x[ i ] , &y[ i ] );
}
int cal2( int idx , int idx2 ){
    int cntl = 0 , cntr = 0;
    if( equal( x[ idx ] , x[ idx2 ] ) ){
        for( int i = 1 ; i <= n ; i ++ )
            if( x[ i ] < x[ idx ] - eps ) cntl ++;
            else if( x[ i ] > x[ idx ] + eps ) cntr ++;
        return min( cntl , cntr );
    }
    D slope = ( y[ idx2 ] - y[ idx ] ) / ( x[ idx2 ] - x[ idx ] );
    D dc = y[ idx ] - slope * x[ idx ];
    for( int i = 1 ; i <= n ; i ++ ){
        D vl = y[ i ] - slope * x[ i ] - dc;
        if( vl < -eps ) cntl ++;
        else if( vl > eps ) cntr ++;
    }
    return min( cntl , cntr );
}
void cal( int idx ){
    int ans = n - 1;
    for( int i = 1 ; i <= n ; i ++ )
        if( i != idx )
            ans = min( ans , cal2( idx , i ) );
    printf( "%d\n" , ans );
}
void solve(){
    printf( "Case #%d:\n" , ++ cs );
    for( int i = 1 ; i <= n ; i ++ )
        cal( i );
}
int main(){
    build();
    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
