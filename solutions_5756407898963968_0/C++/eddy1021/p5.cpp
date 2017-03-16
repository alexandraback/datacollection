#include <stdio.h>
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int t , r1 , r2 , cs;
void init(){
    r1 = 0; r2 = 0;
    int r; r = getint();
    for( int i = 1 ; i <= 4 ; i ++ )
        for( int j = 1 ; j <= 4 ; j ++ ){
            int tmp = getint();
            if( i == r )
                r1 ^= ( 1 << tmp );
        }
    r = getint();
    for( int i = 1 ; i <= 4 ; i ++ )
        for( int j = 1 ; j <= 4 ; j ++ ){
            int tmp = getint();
            if( i == r )
                r2 ^= ( 1 << tmp );
        }
}
void solve(){
    bool got = false; int ans;
    for( int i = 1 ; i <= 16 ; i ++ )
        if( ( ( r1 & ( 1 << i ) ) > 0 ) && ( ( r2 & ( 1 << i ) ) > 0 ) ){
            if( got ){
                puts( "Bad magician!" );
                return;
            }
            ans = i; got = true;
        }
    if( !got ) puts( "Volunteer cheated!" );
    else printf( "%d\n" , ans );
}
int main(){

    freopen( "A-small-attempt0.in" , "r" , stdin );
    freopen( "A-small-attempt0.out" , "w" , stdout );

    t = getint(); while( t -- ){
        init();
        printf( "Case #%d: " , ++ cs );
        solve();
    }

    fclose( stdin );
    fclose( stdout );
}
