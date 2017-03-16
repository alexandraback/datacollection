#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>

void Work( int test )
{
	int i, j;
	int r;
	bool p[ 16 ];
	memset( p, 0, sizeof( p ) );
	scanf( "%d", &r );
	for( i = 1; i <= 4; ++i )
	{
		for( j = 1; j <= 4; ++j )
		{
			int x;
			scanf( "%d", &x );
			--x;
			if ( i != r )
				p[ x ] = true;
		}
	}
	scanf( "%d", &r );
	for( i = 1; i <= 4; ++i )
	{
		for( j = 1; j <= 4; ++j )
		{
			int x;
			scanf( "%d", &x );
			--x;
			if ( i != r )
				p[ x ] = true;
		}
	}

	int result = -1;
	for( i = 0; i < 16; ++i )
	{
		if( p[ i ] )
			continue;
		if( result == -1 )
			result = i;
		else
			result = -2;
	}

	if( result == -1 )
		printf( "Case #%d: Volunteer cheated!\n", test );
	else if( result == -2 )
		printf( "Case #%d: Bad magician!\n", test );
	else
		printf( "Case #%d: %d\n", test, result + 1 );
}

int main()
{
	int i, t;
	scanf( "%d", &t );
	for( i = 0; i < t; ++i )
	{
		Work( i + 1 );
	}
	return 0;
}
