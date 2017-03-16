#include "R1A_A.h"

int CR1A_ATaskProcessor::findMinMushroomsMethod1( const std::vector<int>& mushroomsCounts )
{
	const int count = mushroomsCounts.size();
	assert( count > 0 );

	int result = 0;
	for( int i = 0; i < count - 1; i++ ) {
		if( mushroomsCounts[i] > mushroomsCounts[i + 1] ) {
			result += mushroomsCounts[i] - mushroomsCounts[i + 1];
		}
	}
	return result;
}

int CR1A_ATaskProcessor::findMinMushroomsMethod2( const std::vector<int>& mushroomsCounts )
{
	const int count = mushroomsCounts.size();
	assert( count > 0 );

	int minSpeed = 0;
	for( int i = 0; i < count - 1; i++ ) {
		if( mushroomsCounts[i] > mushroomsCounts[i + 1] ) {
			minSpeed = max( minSpeed, mushroomsCounts[i] - mushroomsCounts[i + 1] );
		}
	}

	int result = 0;
	for( int i = 0; i < count - 1; i++ ) {
		result += min( minSpeed, mushroomsCounts[i] );
	}
	return result;
}
