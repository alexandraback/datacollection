#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXS = 2000;

int main()
{
    int values[MAXS];
    int T, N, A, B;
    scanf( "%d", &T );
    for ( int t = 1; t <= T; t++ )
    {
        A = 0; B = 0;
        int rate = 0;
        scanf( "%d", &N );
        for ( int i = 0; i < N; i++ ) scanf( "%d", &values[i] );
        for ( int i = 0; i < N-1; i++ )
        {
            A += max(0,values[i]-values[i+1]);
            rate = max( rate, values[i]-values[i+1] );
        }
        int offset = 0;
        for ( int i = 0; i < N-1; i++ )
        {
            //offset += values[i];
            B += min(values[i],rate);
            //offset -= min(offset,rate);
            //printf( "%d\n", offset );
        }
        printf( "Case #%d: %d %d\n", t, A, B );
    }
    return 0;
}
