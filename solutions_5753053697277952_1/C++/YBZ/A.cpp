#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std ;

const int MAXN = 30 ;

int N , sum ;
multimap<int,char> F ;

void Init() {
	cin >> N ;
	sum = 0 ;
	for ( int i = 0 ; i < N ; i ++ ) {
		int A ; cin >> A ;
		//while ( A > 2 ) {
		//	cout << " " << (char)(i+'A') << (char)(i+'A') ;
		//	A -= 2 ;
		//}
		sum += A ;
		F.insert( make_pair(0-A , i+'A') ) ;
	}
}

void Solve() {
	while ( F.size() >= 4 || (F.size() == 3 && (0-(*F.begin()).first) >= 2) ) {
		char w1 , w2 ;
		int a1 , a2 ;
		
		a1 = 0-(*F.begin()).first ;
		w1 = (*F.begin()).second ;
		F.erase(F.begin()) ;
		
		a1 -- ;
		if ( a1 != 0 ) F.insert( make_pair(0-a1,w1) ) ;
		
		a2 = 0-(*F.begin()).first ;
		w2 = (*F.begin()).second ;
		F.erase(F.begin()) ;
		
		a2 -- ;
		if ( a2 != 0 ) F.insert( make_pair(0-a2,w2) ) ;
		
		cout << " " << w1 << w2 ; sum -= 2 ;
		if ( (0-(*F.begin()).first) * 2 > sum ) fprintf(stderr , "ERROR\n") ;
	}
	
	while ( F.size() == 2 ) {
		char w1 , w2 ;
		int a1 , a2 ;
		
		a1 = 0-(*F.begin()).first ;
		w1 = (*F.begin()).second ;
		F.erase(F.begin()) ;
		
		a1 -- ;
		if ( a1 != 0 ) F.insert( make_pair(0-a1,w1) ) ;
		
		a2 = 0-(*F.begin()).first ;
		w2 = (*F.begin()).second ;
		F.erase(F.begin()) ;
		
		a2 -- ;
		if ( a2 != 0 ) F.insert( make_pair(0-a2,w2) ) ;
		
		cout << " " << w1 << w2 ; sum -= 2 ;
		if ( (0-(*F.begin()).first) * 2 > sum ) fprintf(stderr , "ERROR\n") ;
	}
	if ( F.size() == 3 ) {
		char w1 = (*F.begin()).second ; F.erase(F.begin());
		char w2 = (*F.begin()).second ; F.erase(F.begin());
		char w3 = (*F.begin()).second ; F.erase(F.begin());
		cout << " " << w1 << " " << w2 << w3 ;
	}
	cout << "\n" ;
}

int main() {
	int Test ;
	cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cout << "Case #" << i << ":" ;
		Init() ;
		Solve() ;
	}
}