#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int T , N , cnt;
int casen = 1;
struct PAIR{
	long long x , y;
	PAIR(){}
	PAIR( long long _x , long long _y ){
		x = _x , y = _y;
	}
	
}points[ 101 ] , node[30] , toCheck;
bool success , chose[ 101 ];

double cross( PAIR O , PAIR A , PAIR B ){
	return (A.x-O.x) * ( B.y-O.y ) - ( B.x-O.x ) * ( A.y-O.y );
}

bool cmp( PAIR A , PAIR B ){
	return A.x < B.x || ( A.x == B.x && A.y < B.y );
}

bool onPoly(){
	
	PAIR tmp[30] , arr[ 30 ];
	
	int tcnt = 0 , top = 0;
	
	for ( int i = 1 ; i <= cnt ; i++ )
		if ( !chose[i] )
			tmp[++tcnt] = node[i];
	
	tmp[++tcnt] = toCheck;
	
	sort( tmp+1 , tmp+tcnt+1 , cmp );

	for ( int i = 1 ; i <= tcnt ; i++ ){
		while ( top >= 2 && cross( arr[top-1] , arr[top] , tmp[i] ) < 0 )
			top--;
		arr[ ++top ] = tmp[i];
	}
	
	const int index = top + 1;
	
	for ( int i = tcnt-1 ; i >= 1 ; i-- ){
		while ( top >= index && cross( arr[top-1] , arr[top] , tmp[i] ) < 0 )
			top--;
		arr[ ++top ] = tmp[i];
	}	
	
	//for ( int i = 1 ; i <= top ; i++ )
	//	printf("%d %d\n",arr[i].x , arr[i].y );

	for ( int i = 1 ; i <= top ; i++ )
		if (  arr[i].x == toCheck.x && arr[i].y == toCheck.y )
			return true;	
		
	return false;
}

void DFS( int now , int cutted , int wantToCut ){
	if ( success ) return;
	if ( now > cnt ){		
		//puts("!!!");	
		if ( onPoly() ){
			success = true;
			return;
		}
	}
	else{
		if ( cutted < wantToCut ){
			chose[now] = true;
			DFS( now+1 , cutted+1 , wantToCut );
			chose[now] = false;
		}
		if ( cutted + ( cnt - now ) >= wantToCut )
			DFS( now+1 , cutted , wantToCut );
		
	}


}
int Solve( int which ){
	
	cnt = 0; success = false;
	memset( chose , 0 , sizeof( chose ) );
	
	for ( int i = 1 ; i <= N ; i++ )
		if ( i != which )
			node[++cnt] = points[i];
	toCheck = points[ which ];
	for ( int cut = 0 ; cut <= N-3 ; cut++ ){
		
		DFS( 1 , 0 , cut ) ;
		if ( success ) return cut;
	
	}

}
int main(){
	freopen("C-small-attempt2.in" , "r" , stdin);
	freopen("output.out" , "w" , stdout);


	scanf("%d",&T);
	while ( T-- ){
		scanf("%d",&N);
		for ( int i = 1 ; i <= N ; i++ )
			scanf("%I64d%I64d",&points[i].x,&points[i].y);
		
		printf("Case #%d:\n", casen++);
		
		if ( N <= 2 ){
			for ( int i = 1 ; i <= N ; i++ )
				puts("0");
			continue;
		}
		
		//printf("%d\n", Solve( 1 ));
		for ( int i = 1 ; i <= N ; i++ )
			printf("%d\n", Solve( i ));
	}


	return 0;
}
