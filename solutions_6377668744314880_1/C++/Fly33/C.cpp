#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
#include <deque>
#include <algorithm>
#include <omp.h>

using namespace std;

typedef long long int64_t;

static const int MAXN = 3012;
static const double EPS = 1e-9;
static const double Pi = 3.1415926535897932384626433832795;

class Solution
{
	int Result[ MAXN ];
    int N;
    int X[ MAXN ], Y[ MAXN ];
	double A[ MAXN * 2 ];

public:
	void Work()
	{
        int i, j, k;

		memset( Result, 0, sizeof( Result ) );

		if( N > 3 )
		{
			for( i = 0; i < N; ++i )
			{
				Result[ i ] = -1;

				for( j = 0; j < N; ++j )
				{
					if( i == j )
						continue;
					A[ j ] = atan2( (double)(Y[j]-Y[i]), (double)(X[j]-X[i]) );
				}

				swap( A[ 0 ], A[ i ] );
				sort( A + 1, A + N );

				for( j = 1; j < N; ++j )
					A[ j + N - 1 ] = A[ j ] + 2 * Pi;

				for( j = 1; j < N; ++j )
				{
					int r = lower_bound( A + 1, A + N * 2 + 1, A[ j ] + Pi - EPS ) - ( A + j + 1 );
					if( Result[ i ] == -1 || Result[ i ] > r )
						Result[ i ] = r;
				}

				if( Result[i] == -1 )
					Result[i] = 0;
			}
		}
	}

	void Read()
	{
        int i;
		scanf( "%d", &N );
        for( i = 0; i < N; ++i )
        {
            int x, y;
            scanf( "%d%d", &x, &y );
            X[i] = x;
            Y[i] = y;
        }
	}

	void Write( int t )
	{
        int i;
		printf( "Case #%d:\n", t );
        for( i = 0; i < N; ++i )
        {
            printf( "%d\n", Result[i] );
        }
	}
};

vector< Solution > solution;

int main()
{
	int i, t;
	scanf( "%d", &t );
	solution.resize( t );
	for( i = 0; i < t; ++i )
		solution[ i ].Read();
#pragma omp parallel for schedule(dynamic, 1)
	for( i = 0; i < t; ++i )
		solution[ i ].Work();
	for( i = 0; i < t; ++i )
		solution[ i ].Write( i + 1 );
	return 0;
}
