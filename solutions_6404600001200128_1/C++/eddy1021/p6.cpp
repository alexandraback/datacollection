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
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
int mypow( int _a , int _x , int _mod ){
    if( _x == 0 ) return 1;
    int _tmp = mypow( _a , _x / 2 , _mod );
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
int n , m[ N ];
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        m[ i ] = getint();
}
int cal1(){
    int tans = 0;
    for( int i = 2 ; i <= n ; i ++ )
        if( m[ i ] < m[ i - 1 ] )
            tans += m[ i - 1 ] - m[ i ];
    return tans;
}
int can( int rt ){
    int now = m[ 1 ] , tans = 0;
    for( int i = 2 ; i <= n ; i ++ ){
        int nxt = max( 0 , now - rt );
        tans += now - nxt;
        if( nxt > m[ i ] ) return -1;
        now = m[ i ];
    }
    return tans;
}
int cal2(){
    int l = 0 , r = 10000 , mid , a = 10000;
    while( l <= r ){
        mid = ( l + r ) >> 1;
        if( can( mid ) != -1 ) r = mid - 1 , a = mid;
        else l = mid + 1;
    }
    return can( a );
}
void solve(){
    printf( "Case #%d: %d %d\n" , ++ cs , cal1() , cal2() );
}
int main(){
    build();
    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
