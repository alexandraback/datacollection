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
#include <cstdint>

using namespace std;

class Solution
{
    static const int MAXN = 3012;
	int Result[ MAXN ];
    int N;
    int X[ MAXN ], Y[ MAXN ];

public:
	void Work()
	{
        int i, j, k;


        for( i = 0; i < N; ++i )
        {
            Result[ i ] = -1;
            for( j = 0; j < N; ++j )
            {
                if( i == j )
                    continue;
                int r = 0;
                for( k = 0; k < N; ++k )
                {
                    if( (int64_t)X[i]*Y[j]-(int64_t)X[j]*Y[i] + (int64_t)X[j]*Y[k]-(int64_t)X[k]*Y[j] + (int64_t)X[k]*Y[i]-(int64_t)X[i]*Y[k] > 0 )
                        ++r;
                }
                if( Result[i] == -1 || Result[i] > r )
                    Result[i] = r;
            }
            if( Result[i] == -1 )
                Result[i] = 0;
        }
	}

	void Read()
	{
        int i;
		scanf( "%d", &N );
        for( i = 0; i < N; ++i )
        {
            scanf( "%d%d", &X[i], &Y[i] );
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
