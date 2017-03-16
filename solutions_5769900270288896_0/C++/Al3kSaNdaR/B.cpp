#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz size
#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

using namespace std;

typedef long long int lld;
typedef pair < int, int > pii;

int main ( void )
{
    freopen ( "B-small-attempt0.in", "r", stdin );
    freopen ( "B-small-attempt0.out", "w", stdout );

    int T;
    cin >> T;
    for ( int i = 1; i <= T; i++ )
    {
        int R, C, N;
        cin >> R >> C >> N;

        int Solution = 1 << 30;
        for ( int i = 0; i < ( 1 << ( R * C ) ); i++ )
        {
            int Grid[42][42];
            memset ( Grid, 0, sizeof ( Grid ) );

            int Count = 0;
            for ( int j = 0; j < R * C; j++ )
            {
                if ( ( i >> j ) & 1 )
                {
                    Grid[j / C][j % C] = 1;
                    Count++;
                }
            }
            if ( Count != N ) continue;

            int Cost = 0;
            for ( int ii = 0; ii < R; ii++ )
                for ( int jj = 0; jj < C; jj++ )
                {
                    if ( Grid[ii][jj] == 0 ) continue;
                    if ( Grid[ii][jj + 1] == 1 ) Cost++;
                    if ( Grid[ii + 1][jj] == 1 ) Cost++;
                }

            Solution = min ( Solution, Cost );
        }

        cout << "Case #" << i << ": " << Solution << endl;
    }

    return 0;
}
