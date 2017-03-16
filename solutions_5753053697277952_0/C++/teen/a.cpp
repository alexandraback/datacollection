#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

#define LL long long 

using namespace std;
const int maxn = 1005;
const int inf = 1e9+7;


int n, p[maxn];

int main(){

	int T; scanf("%d", &T);
	for(int it=1;it<=T;it++){
		printf("Case #%d:", it);

		scanf("%d", &n); int sum = 0;
		for(int i=1;i<=n;i++){
			scanf("%d", &p[i]);
			sum += p[i];
		}

		while ( sum>0 ){
			if ( sum<=2 ){
				printf(" ");
				for(int i=1;i<=n;i++)
					while ( p[i]>0 ) {
						p[i]--; sum--;
						printf("%c", 'A'-1+i );
					}
			}
			else{
				int maxv = -1;
				for(int i=1;i<=n;i++){
					maxv = max(p[i], maxv);
				}
				int cnt = 0;
				for(int i=1;i<=n;i++){
					if ( maxv==p[i] ) cnt++;
				}
				if( cnt==2 ){
					printf(" ");
					for(int i=1;i<=n;i++)
						if ( p[i]==maxv ){
							printf("%c", 'A'+i-1 );
							p[i]--; sum--;
						}
				}
				else{
					for(int i=1;i<=n;i++)
						if ( p[i]==maxv ) {
							printf(" %c", 'A'+i-1 );
							p[i]--; sum--;
							if ( maxv==1 ) break;
						}
				}
			}
		}
		printf("\n");
	}	

	return 0;
}

