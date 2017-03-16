#include <cstdio>
int cas, n, a[26], cnt;
int main(){
    freopen( "A-small-attempt0.in" , "r" , stdin );
    freopen( "A.out" , "w" , stdout );
    scanf( "%d" , &cas );
    for( int T = 1 ; T <= cas ; T ++ ){
        scanf( "%d" , &n );
        cnt = 0;
        for( int i = 0 ; i < n ; i ++ ){
            scanf( "%d" , &a[i] );
            cnt += a[i];
        }
        printf( "Case #%d: " , T );
        int flag = cnt & 1;
        for( int i = 1 ; i <= cnt ; i ++ ){
            int MAX = -1, id = 0;
            for( int j = 0 ; j < n ; j ++ )
                if( MAX < a[j] )
                    MAX = a[id=j];
            a[id] --;
            putchar( id + 'A' );
            if( i % 2 == flag && i != cnt )
                putchar( ' ' );    
        }
        printf( "\n" );
    }
}
            
                
    
    
