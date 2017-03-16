#include <iostream>
#include <stdio.h>
using namespace std;
int T , N , B;
long long arr[1001];
int main(){
	freopen("B-small-attempt1.in" , "r" , stdin);
	freopen("output.out" , "w" , stdout);
	int casen = 1;
	scanf("%d",&T);

	while ( T-- ){
		scanf("%d%d",&B,&N);
		long long l = 0 , r = 1e13 , mid , ans;
		for ( int i = 1 ; i <= B ; i++ )
			scanf("%I64d",&arr[i]);

			
		while ( r >= l ){
			mid = ( l + r ) >> 1;
			long long cutted = 0;
			for ( int i = 1 ; i <= B ; i++ )
				cutted += mid / arr[i] + 1;
			if ( cutted >= N )
				r = mid - 1 , ans = mid;
			else
				l = mid + 1;
		}
		long long cutted = 0;
		for ( int i = 1 ; i <= B ; i++ )
			cutted += ans / arr[i] + 1;
		
		if ( ans == 0 ) printf("Case #%d: %d\n",casen++ , N);
		else{
			for ( int i = B ; i >= 1 ; i-- )
				if ( ans % arr[i] == 0 ){
					if ( N != cutted ){ cutted--; continue; }
					printf("Case #%d: %d\n",casen++ , i);
					break;
				}

			
			
			
		}
	}

	return 0;
}
