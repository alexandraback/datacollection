#include "R1A_B.h"

int CR1A_BTaskProcessor::findBarberIndex( __int64 placeInALine, const std::vector<int>& barbersTimes )
{
	const int barbersCount = barbersTimes.size();
	assert( barbersCount > 0 );
	assert( placeInALine >= 1 );

	//	binary search for the moment in time
	__int64 t0 = 0;
	__int64 t1 = 1;
	while( getFirstInLine( barbersTimes, t1 ) <= placeInALine ) {
		t1 *= 2;
	}

	while( t1 - t0 > 1 ) {
		__int64 t2 = (t0 + t1) / 2; 
		const __int64 firstInLine = getFirstInLine( barbersTimes, t2 );
		if( firstInLine > placeInALine ) {
			t1 = t2;
		} else {
			t0 = t2;
		}
	}

	return assignToABarber( barbersTimes, t0, placeInALine );
}

//	who's first in line at a given moment in time, >= 1
__int64 CR1A_BTaskProcessor::getFirstInLine( const std::vector<int>& barbersTimes, __int64 momentInTime )
{
	assert( momentInTime >= 0 );
	if( momentInTime == 0 ) {
		return 1;
	}

	__int64 totalCustomersProcessed = 0;
	int numberOfBusyBarbers = 0;
	for( int i = 0; i < (int)barbersTimes.size(); i++ ) {
		assert( barbersTimes[i] > 0 );
		const __int64 numberOfProcessedCustomers = momentInTime / barbersTimes[i];
		if( momentInTime % barbersTimes[i] != 0 ) {
			numberOfBusyBarbers++;
		}
		totalCustomersProcessed += numberOfProcessedCustomers;
	}

	return totalCustomersProcessed + numberOfBusyBarbers + 1;
}

//	assign to a barber, the moment in time is known
int CR1A_BTaskProcessor::assignToABarber( const std::vector<int>& barbersTimes, __int64 momentInTime, __int64 placeInALine )
{
	assert( momentInTime >= 0 );

	std::vector<int> freeBarbers;
	__int64 totalCustomersProcessed = 0;
	int numberOfBusyBarbers = 0;
	for( int i = 0; i < (int)barbersTimes.size(); i++ ) {
		assert( barbersTimes[i] > 0 );
		const __int64 numberOfProcessedCustomers = momentInTime / barbersTimes[i];
		if( momentInTime % barbersTimes[i] == 0 ) {
			freeBarbers.push_back( i + 1 );
		} else {
			numberOfBusyBarbers++;
		}
		totalCustomersProcessed += numberOfProcessedCustomers;
	}
	const int index = (int)( placeInALine - ( totalCustomersProcessed + numberOfBusyBarbers ) - 1 );
	assert( index >= 0 && index < (int)freeBarbers.size() );
	return freeBarbers[index];
}