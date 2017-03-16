#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std ;
#define rep( i, j, k ) for( i = j ; i < k ; ++i ) 
#define MaxL 10015
const int go[4][2] = { 0,1, 1,0, 0,-1, -1,0 } ;
int n, R, C, Case, T ;
bool map[MaxL] ;

int Calc( int i, int j )
{
	int re = 0, x, y ;
	rep( i, 0, 4 ) {
		x = i + go[i][0] ;
		y = i + go[i][1] ;
		if((x>=R)||(x<0)||(y>=C)||(y<0)||(!map[x*C+y])) continue ;
		++ re ;
	}
	return re ;
}

int Calc0() // ºÚ 
{
	int put = 0, re = 0, i, j; 
	
	memset( map, 0, sizeof( map ) ) ;
	
	rep( i, 0, R ) 
		for( j = (i&1) ; j < C ; j += 2 ) {
			map[i*C+j] = true ;
			++ put ;
		}
	
	if( put >= n ) return 0 ;
	
	if(!map[0]) {
		++ put ;
		re += Calc( 0, 0 ) ;
		map[0] = true ;
		if( put >= n ) return re ;
	}	
	if(!map[C-1]) {
		++ put ;
		re += Calc( 0, C-1 ) ;
		map[C-1] = true ;
		if( put >= n ) return re ;	
	}
	if((!map[(R-1)*C])) {
		++ put ;
		re += Calc(R-1, 0 ) ;
		map[(R-1)*C] = true; 
		if( put >= n ) return re ;
	}	
	if((R>1) && (!map[R*C-1])) {
		++ put ;
		re += Calc(R-1, C-1 ) ;
		map[R*C-1] = true ;
		if( put >= n ) return re ;
	}
	
	for( j = 0 ; j < C ; j ++ ) {
		if( !map[j] ) {
			++ put ;
			re += Calc( 0, j ) ;
			map[j] = true ;
			if( put >= n ) return re ;	
		}
		if( !map[(R-1)*C+j] ) {
			++ put ;
			re += Calc( R-1, j ) ;
			map[(R-1)*C+j] = true ;
			if( put >= n ) return re ;
		}
	}
	for( j = 0 ; j < R ; ++j ) {
		if( !map[j*C]) {
			++ put ;
			re += Calc( j, 0 ) ;
			map[j*C] =  true ;
			if( put >= n ) return re ;	
		}	
		if( !map[j*C+C-1] ) {
			++ put ;
			re += Calc( j, C-1 ) ;
			map[j*C+C-1] = true ;
			if( put >= n ) return re ;
		}
	}
	
	rep( i, 0, R )
		rep( j, 0, C ) 
			if( ! map[i*C+j] ) {
				++ put ;
				re += Calc( i, j ) ;
				if( put >= n ) return re ;	
			}
}

int Calc1()
{
	int put = 0, re = 0, i, j ;
	
	memset( map, 0, sizeof( map ) ) ;
	
	rep( i, 0, R ) 
		for( j = ((i&1)^1) ; j < C ; j += 2 ) {
			map[i*C+j] = true ;
			++ put ;
		}
	
	if( put >= n ) return 0 ;
	
	if(!map[0]) {
		++ put ;
		re += Calc( 0, 0 ) ;
		map[0] = true ;
		if( put >= n ) return re ;
	}	
	if(!map[C-1]) {
		++ put ;
		re += Calc( 0, C-1 ) ;
		map[C-1] = true ;
		if( put >= n ) return re ;	
	}
	if((R>1)&&(!map[(R-1)*C])) {
		++ put ;
		re += Calc( R-1, 0 ) ;
		map[(R-1)*C] = true; 
		if( put >= n ) return re ;
	}	
	if((R>1)&&(!map[R*C-1])) {
		++ put ;
		re += Calc( R-1, C-1 ) ;
		map[R*C-1] = true ;
		if( put >= n ) return re ;
	}
	
	for( j = 0 ; j < C ; j ++ ) {
		if( !map[j] ) {
			++ put ;
			re += Calc( 0, j ) ;
			map[j] = true ;
			if( put >= n ) return re ;	
		}
		if( !map[(R-1)*C+j] ) {
			++ put ;
			re += Calc( R-1, j ) ;
			map[(R-1)*C+j] = true ;
			if( put >= n ) return re ;
		}
	}
	for( j = 0 ; j < R ; ++j ) {
		if( !map[j*C]) {
			++ put ;
			re += Calc( j, 0 ) ;
			map[j*C] =  true ;
			if( put >= n ) return re ;	
		}	
		if( !map[j*C+C-1] ) {
			++ put ;
			re += Calc( j, C-1 ) ;
			map[j*C+C-1] = true ;
			if( put >= n ) return re ;
		}
	}
	
	rep( i, 0, R )
		rep( j, 0, C ) 
			if( ! map[i*C+j] ) {
				++ put ;
				re += Calc( i, j ) ;
				if( put >= n ) return re ;	
			}
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin) ;
	freopen("output.txt","w",stdout) ;
	
	for( scanf("%d", &T) ; T-- ; ) {
		scanf("%d%d%d", &R, &C, &n) ;
		if( R > C ) swap( R, C ) ; 
		printf("Case #%d: %d\n", ++Case, min( Calc0(), Calc1() ) ) ;
	}
	return 0 ;	
}
