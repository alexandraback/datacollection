#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int neig( int x, int y, int n, int m )
{
    int s = 0;
    for( int i = -1; i <= 1; i++ )
    {
        for( int j = -1; j <= 1; j++ )
        {
            if( i + j == 1 || i + j == -1 )
            {
                int a = x + i;
                int b = y + j;

                if( a >= 0 && a < n && b >=0 && b < m )
                    s++;
            }
        }
    }

    return s;
}

int main()
{
    int t;
    scanf( "%d", &t );

    for( int z = 1; z <= t; z++ )
    {
        int r, c, n;
        scanf( "%d %d %d", &r, &c, &n );
        
        vector< int > v;

        int free = 0;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                if( ( i + j ) % 2 == 1 )
                    v.push_back( neig( i, j, r, c ) );
                else
                    free++;
            }
        }
        
        //printf( "%d\n", free );        
        int res = 0;
        if( n > free )
        {
            sort( v.begin(), v.end() );
            for( int i = 0; i < n - free; i++ )
                res += v[ i ];
        }

        v.clear();

        free = 0;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                if( ( i + j ) % 2 == 0 )
                    v.push_back( neig( i, j, r, c ) );
                else
                    free++;
            }
        }

        int res2 = 0;
        //printf( "%d\n", free );        
        if( n > free )
        {
            sort( v.begin(), v.end() );
            for( int i = 0; i < n - free; i++ )
                res2 += v[ i ];
        }

        printf( "Case #%d: %d\n", z, min( res, res2 ) );
    }
}
