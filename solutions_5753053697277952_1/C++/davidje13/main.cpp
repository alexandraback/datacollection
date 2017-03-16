#include <iostream>
#include <vector>
#include <stdexcept>
#include <stdlib.h>

// https://code.google.com/codejam/contest/4314486/dashboard#s=p0

std::vector<std::vector<std::size_t>> solve( std::vector<long> members, const std::size_t maxPerStep ) {
	long total = 0;
	for( const long partySize : members ) {
		total += partySize;
	}
	std::vector<std::vector<std::size_t>> result;
	while( total > 0 ) {
		std::vector<std::size_t> majority;
		long majoritySize = 1;
		for( std::size_t i = 0; i < members.size( ); ++ i ) {
			const long partySize = members[i];
			if( partySize > majoritySize ) {
				majoritySize = partySize;
				majority.clear( );
			}
			if( partySize == majoritySize ) {
				majority.push_back( i );
			}
		}
		if( majority.size( ) > maxPerStep ) {
			majority.resize( maxPerStep - 1 ); // ensure at least 2 are left tied
		}
		for( const std::size_t party : majority ) {
			-- members[party];
		}
		total -= majority.size( );
		result.push_back( majority );
	}
	return result;
}

int main( int argc, const char *const *const argv ) {
	if( argc != 1 ) {
		std::cerr
			<< "Usage: " << argv[0] << std::endl
			<< std::endl
			<< "Takes input on stdin" << std::endl;
		return EXIT_FAILURE;
	}

	long totalTests;
	std::cin >> totalTests;

	for( long n = 0; n < totalTests; ++ n ) {
		std::size_t partyCount;
		std::cin >> partyCount;
		std::vector<long> members( partyCount );
		for( std::size_t i = 0; i < partyCount; ++ i ) {
			std::cin >> members[i];
		}
		const auto solution = solve( members, 2 );
		std::cout << "Case #" << (n + 1) << ":";
		for( const auto &part : solution ) {
			std::cout << ' ';
			for( const auto party : part ) {
				std::cout << (char) ('A' + party);
			}
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
