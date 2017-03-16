#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void do_case() {
	int N;
	cin >> N;

	array<int,26> parties = { 0 };

	int total_senators = 0;
	for( int i=0; i<N; ++i ) {
		cin >> parties[i];
		total_senators += parties[i];
	}
	//cout << "total_senators=" << total_senators << endl;
	//cout << "parties=";
	//for( int i=0; i<N; ++i ) cout << parties[i] << " ";
	//cout << endl;

	// Equalize the two biggest parties
	int party1=0, party2=1;
	for( int i=0; i<N; ++i ) {
		if( parties[i] > parties[party1] ) {
			party2 = party1;
			party1 = i;
		}
		else if( parties[i] > parties[party2] && i!=party1 ) {
			party2 = i;
		}
	}
	//cout << "Biggest parties: " << party1 << " " << party2 << endl;
	while( parties[party1] > parties[party2] ) {
		cout << static_cast<char>('A'+party1) << " ";
		--parties[party1];
		--total_senators;
	}

	// Remove all other parties
	while( total_senators != parties[party1]+parties[party2] ) {
		for( int i=0; i<N; ++i ) {
			if( parties[i]>0 && i!=party1 && i!=party2 ) {
				cout << static_cast<char>('A'+i) << " ";
				--parties[i];
				--total_senators;
			}
		}
	}

	// Pairwise remove the biggest parties
	while( parties[party1]+parties[party2] > 0 ) {
		cout << static_cast<char>('A'+party1) << static_cast<char>('A'+party2) << " ";
		--parties[party1];
		--parties[party2];
	}
}

int main() {
	unsigned int T;
	cin >> T;

	for( unsigned int i=0; i<T; ++i ) {
		cout << "Case #" << (i+1) << ": ";
		do_case();
		cout << endl;
	}
}
