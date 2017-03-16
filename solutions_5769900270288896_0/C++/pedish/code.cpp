#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <string>
#include <queue>
#include <functional>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <string.h>
using namespace std;

namespace{
	#define		CAST( T, val )		( (T)( val ) )
	#define		CASE( lb )			break; case lb:
	#define		CASE_CONTINUE( lb )	case lb:
	#define		CASE_DEFAULT		break; default:
	#define		For( i, s )			for(int i= 0; i< (int)s; i++)
	#define		ForA( i, a, s )		for(int i= (int)a; i< (int)s; i++)
	#define		ForSize( i, s )		for(int i= 0, size= (int)s; i< size; i++)
	#define		ForSizeA( i, a, s )	for(int i= (int)a, size= (int)s; i< size; i++)
	#define		ForItr( itr, con )	for(auto itr= con.begin(); itr!= con.end(); itr++)
	#define		ForStr( i, str )	for(int i= 0; str[i]; i++)
	#define		GOTO( lb )			goto lb
	#define		LABEL( lb )			lb:
	#define		ALL( con )			con.begin(), con.end()

	typedef		long long		LLint;
	typedef		unsigned int	Uint;
	typedef		unsigned char	Uchar;
	typedef		unsigned short	Ushort;
	
	const int Ten5= 100000;		//	10^5
	const int Ten6= 1000000;	//	10^6
	const double EPS= 0.00000000023283064365386962890625;	//	2^-32
	template <typename T> class priority_queue_less : public priority_queue<T,vector<T>,greater<T> >{};
}
template <typename Itr> bool next_combination(Itr fst, Itr mid, Itr last){
	if( fst== mid || mid== last ) return false;
	Itr m1= mid, m2= last-1, mid2= mid;
	while( --m1!= fst && !( *m1 < *m2 ) );
	bool res= !( ( m1== fst ) && !( *fst< *m2 ) );
	if( res ){ while( mid2!= m2 && !( *m1 < *mid2 ) ) ++mid2; fst= m1; swap( *fst++, *mid2++ ); }
	if( fst!= mid && mid2!= last ){
		m1= mid; m2= mid2; while( m1!= fst && m2!= last ) swap( *--m1, *m2++ );
		reverse( fst, m1 ); reverse( fst, mid ); reverse( m2, last ); reverse( mid2, last );
	}
	return res;
}
void solve(){
	int W, H, N;
	cin>> W>> H>> N;

	bool exist[16];
	int min= INT_MAX;
	int comb[16];

	For( i, W*H ) comb[i]= i;

	while(1){
		For( i, W*H ){
			exist[i]= false;
		}
		For( i, N ){
			exist[ comb[i] ]= true;
		}

		//	cnt
		int cnt= 0;
		For( w, W ) For( h, H ) if( exist[W*h+w] ){
			if( w > 0 && exist[W*h+w-1] ) cnt++;
			if( h > 0 && exist[W*(h-1)+w] ) cnt++;
			if( w < W-1 && exist[W*h+w+1] ) cnt++;
			if( h < H-1 && exist[W*(h+1)+w] ) cnt++;
		}

		min= ::min( min, cnt );
		if( !next_combination( comb, comb+N, comb+W*H ) ) break;
	}

	cout<< min/2;
}
int main(){
	int L;
	cin>> L;

	For( l, L ){
		cout<< "Case #"<< l+1<< ": ";
		solve();
		cout<< endl;
	}

	return 0;
}
