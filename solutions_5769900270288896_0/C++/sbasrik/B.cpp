#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<climits>
#include<ctime>
#include<sstream>
#define mp       	make_pair
#define pb       	push_back
#define st       	first
#define nd       	second
#define wait     	getchar();getchar();
#define lint     	long long
#define KARE(a)	 	( (a)*(a) )
#define MAX(a,b) 	( (a)>(b) ? (a) : (b) )
#define MIN(a,b) 	( (a)<(b) ? (a) : (b) )
#define MAX3(a,b,c)	( MAX( a,MAX(b,c) ) )
#define MIN3(a,b,c)	( MIN( a,MIN(b,c) ) )
#define FILL(ar,a)	memset( ar,a,sizeof ar )
#define oo	 		1e9
#define pii       	pair<int,int>
#define pll			pair<lint,lint>
#define pdd			pair<double,double>
#define y1			yy1
#define eps      	(1e-9)
#define esit(a,b)  	( abs( (a)-(b) ) < eps )
#define sol(a)		( (a)<<1 )
#define sag(a)		( sol(a)|1 )
#define orta(a,b)	( ( (a)+(b) )>>1 )
#define mxn       	1005
using namespace std;

int mat[20][20];
int n,r,c;
int id,test,mn;
int yon[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int check(){
	
	int i,j,k,ret=0;
	
	for( i=1 ; i<=r ; i++ )
	for( j=1 ; j<=c ; j++ )
	if( mat[i][j] )
		for( k=0 ; k<4  ; k++ ){
		
			int nx = i+yon[k][0];
			int ny = j+yon[k][1];
			
			if( nx>=1 && ny>=1 && nx<=r && ny<=c && mat[nx][ny] )	ret++;
		
		}
		
	return ret/2;
}

void rec( int x , int y , int s ){
	
	if( y==c+1 ){
		rec( x+1,1,s );
		return;
	}
	
	if( x==r+1 ){
		
		if( s==0 )		mn = min( mn , check() );
		return;
		
	}
	
	mat[x][y] = 0;
	rec( x,y+1,s );

	if( s ){
		mat[x][y] = 1;
		rec( x,y+1,s-1 );
	}
	
	return;
}

int main(){
	
		freopen( "input.in" , "r" , stdin );
		freopen( "out.txt" , "w" , stdout );
	
	cin>>test;
	
	for( id=1 ; id<=test ; id++ ){
		
		scanf( "%d %d %d" , &r , &c , &n );
		mn = 1e9;
		rec( 1,1,n );
		printf( "Case #%d: %d\n" , id , mn );
		
	}
	return 0;
}
