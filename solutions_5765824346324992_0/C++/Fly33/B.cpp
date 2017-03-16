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
    static const int MAXB = 1012;
	int Result;
    int B, N;
    int M[ MAXB ];

public:
	void Work()
	{
        int i, n = 0;
        int64_t left = 0, right = 0;

        if( Calc( 0 ) < N )
        {
            left = 0;
            right = 1;

            while( Calc( right ) < N )
            {
                left = right;
                right *= 2;
            }

            while( right - left > 1 )
            {
                int64_t middle = ( right + left ) / 2;

                if( Calc( middle ) < N )
                    left = middle;
                else
                    right = middle;
            }
        
            n = Calc( left );
        }

        for( i = 0; i < B; ++i )
        {
            if( right % M[i] == 0 )
            {
                if( ++n == N )
                    Result = i+1;
            }
        }
	}

    int Calc( int64_t t )
    {
        int i;
        int result = 0;
        for( i = 0; i < B; ++i )
        {
            result += ( int )( t / M[ i ] + 1 );
        }
        return result;
    }
	
	void Read()
	{
        int i;
		scanf( "%d%d", &B, &N );
        for( i = 0; i < B; ++i )
        {
            scanf( "%d", &M[i] );
        }
	}

	void Write( int t )
	{
		printf( "Case #%d: %d\n", t, Result );
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
