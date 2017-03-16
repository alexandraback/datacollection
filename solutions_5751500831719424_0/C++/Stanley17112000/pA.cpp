#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int T , N , top[105] , save[105] , C = 1;
int sum[105][105] , sumcnt[105];
char app[101][105] , S[101][105];
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&T);
	while ( T-- ){
		int totallen = 0;
		bool flag = true;
		memset( top , 0 , sizeof( top ) );
		memset( sum , 0 , sizeof( sum ) ); 
		memset( sumcnt , 0 , sizeof( sumcnt ) );
		scanf("%d",&N);
		for ( int i = 1 ; i <= N ; i++ ){
			scanf("%s",S[i]);
			save[i] = strlen( S[i] );
			totallen += save[i];			
		}
		for ( int i = 1 ; i <= N ; i++ ){
			int ptr = 0;
			app[i][++top[i]] = S[i][0];
			sum[i][top[i]] = 1;
			sumcnt[top[i]]++;
			for ( int j = 1 ; S[i][j] ; j++ ){
				if ( S[i][j] != S[i][j-1] )
					app[i][++top[i]] = S[i][j];
				sum[i][top[i]]++;
				sumcnt[top[i]]++;
			}
		}
		for ( int i = 1 ; i <= N && flag ; i++ )
			for ( int j = i+1 ; j <= N ; j++ ){
				if ( top[i] != top[j] ){
					flag = false;
					break;	
				}
				else{
					for ( int k = 1 ; k <= top[i] ; k++ )	
						if ( app[i][k] != app[j][k] ){
							flag = false;
							break;	
						}
				}
			}
		if ( !flag ) printf("Case #%d: Fegla Won\n",C++);
		else{
			int ans = 0;
			for ( int i = 1 ; i <= top[1] ; i++ ){
			
				int avg =  sumcnt[i] / N , left = sumcnt[i] % N;
				if ( left > N/2 ) avg++;
			
				for ( int j = N ; j >= 1 ; j-- )
					ans += abs ( avg - sum[j][i] );
				
			}
			printf("Case #%d: %d\n",C++,ans);
		}
	} 
	return 0;
}
