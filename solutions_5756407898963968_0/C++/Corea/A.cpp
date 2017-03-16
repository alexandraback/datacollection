#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf( "%d", &T );
    for( int tt = 1; tt <= T; tt ++ ) {
        int a;
        scanf( "%d", &a );
        vector<int> lst1, lst2;
        for( int i = 1; i <= 4; i ++ ) {
            for( int j = 1; j <= 4; j ++ ) {
                int num;
                scanf( "%d", &num );
                if( i == a ) {
                    lst1.push_back( num );
                }
            }
        }
        int b;
        scanf( "%d", &b );
        for( int i = 1; i <= 4; i ++ ) {
            for( int j = 1; j <= 4; j ++ ) {
                int num;
                scanf( "%d", &num );
                if( i == b ) {
                    lst2.push_back( num );
                }
            }
        }
        int result = 0;
        for( int i = 0; i < 4; i ++ ) {
            for( int j = 0; j < 4; j ++ ) {
                if( lst1[ i ] == lst2[ j ] ) {
                    if( result == 0 ) {
                        result = lst1[ i ];
                    } else {
                        result = -1;
                    }
                }
            }
        }

        printf( "Case #%d: ", tt );
        if( result == 0 ) {
            printf( "Volunteer cheated!\n" );
        } else if( result == -1 ) {
            printf( "Bad magician!\n" );
        } else {
            printf( "%d\n", result );
        }
    }
    return 0;
}
