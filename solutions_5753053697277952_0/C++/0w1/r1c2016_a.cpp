#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< int, int > pii;
const int INF = 0x3f3f3f3f;

int n;
int p[ 30 ];

void solve(){
    int sum = 0;
    for( int i = 0; i < n; ++i )
        sum += p[ i ];

    while( sum > 0 ){
        bool done = false;
        for( int i = 0; i < 26; ++i ){
            if( p[ i ] == 0 ) continue;
            if( p[ i ] >= 2 ){
                p[ i ] -= 2;
                sum -= 2;
                bool ok = true;
                for( int j = 0; j < 26; ++j )
                    if( p[ j ] > sum / 2 )
                        ok = false;
                if( !ok ) sum += 2, p[ i ] += 2;
                else{
                    printf( " %c%c", ( char )'A' + i, ( char )'A' + i );
                    done = true;
                    break;
                }
            }
            p[ i ] -= 1;
            sum -= 1;
            bool ok = true;
            for( int j = 0; j < 26; ++j )
                if( p[ j ] > sum / 2 )
                    ok = false;
            if( !ok ) sum += 1, p[ i ] += 1;
            else{
                printf( " %c", ( char )'A' + i );
                done = true;
                break;
            }
            for( int j = 0; j < 26; ++j ) if( i != j ){
                if( p[ j ] == 0 ) continue;
                --p[ i ], --p[ j ], sum -= 2;
                // printf( "p[ %d ] = %d, p[ %d ] = %d, sum = %d\n", i, p[ i ], j, p[ j ], sum );
                bool ok = true;
                for( int k = 0; k < 26; ++k )
                    if( p[ k ] > sum / 2 ){
                        // printf( "%d %d\n", p[ k ], sum / 2 );
                        ok = false;
                    }
                if( !ok ) sum += 2, ++p[ i ], ++p[ j ];
                else{
                    printf( " %c%c", ( char )'A' + i, ( char )'A' + j );
                    done = true;
                    break;
                }
            }
            if( done ) break;
        }
        assert( done );
    }
}

int main(){
    int T; scanf( "%d", &T );
    for( int kase = 1; kase <= T; ++kase ){
        printf( "Case #%d:", kase );
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i )
            scanf( "%d", p + i );
        solve();
        puts( "" );
    }
    return 0;
}
