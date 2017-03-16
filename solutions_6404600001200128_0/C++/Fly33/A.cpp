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

using namespace std;

class Solution
{
    static const int MAXN = 1012;
    int N;
    int M[ MAXN ];
	int Result1, Result2;

public:
	void Work()
	{
        int i, m = 0;
        Result1 = Result2 = 0;

        for( i = 1; i < N; ++i )
        {
            if( M[i-1] > M[i] )
            {
                Result1 += M[i-1] - M[i];
                if( m < M[i-1] - M[i] )
                    m = M[i-1] - M[i];
            }
        }

        for( i = 1; i < N; ++i )
        {
            if( M[i-1] < m )
                Result2 += M[i-1];
            else
                Result2 += m;
        }
	}
	
	void Read()
	{
        int i;
		scanf( "%d", &N );
        for( i = 0; i < N; ++i )
        {
            scanf( "%d", &M[i] );
        }
	}

	void Write( int t )
	{
		printf( "Case #%d: %d %d\n", t, Result1, Result2 );
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
