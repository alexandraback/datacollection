#include <cstdio>
#include <algorithm>

using namespace std;

int cases, mark[ 2 ][ 20 ];

void read( int idx )
{
    int row, x;
    for ( int i = 1; i <= 16; i++ ) mark[ idx ][ i ] = false;
    scanf( "%d", &row );
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
        {
            scanf( "%d", &x );
            if ( i == row - 1 ) mark[ idx ][ x ] = true;
        }
}

int main()
{
    freopen( "A-small-attempt0.in", "r", stdin );
    freopen( "sol.out", "w", stdout );
    scanf( "%d", &cases );
    for ( int k = 0; k < cases; k++ )
    {
        read( 0 );
        read( 1 );
        int ans = 0;
        for ( int i = 1; i <= 16; i++ )
            if ( mark[ 0 ][ i ] && mark[ 1 ][ i ] )
            {
                if ( ans == 0 ) ans = i;
                else ans = -1;
            }
        printf( "Case #%d: ", k + 1 );
        if ( ans == 0 ) printf( "Volunteer cheated!\n" );
        else if ( ans == -1 ) printf( "Bad magician!\n" );
        else printf( "%d\n", ans );
    }
}
