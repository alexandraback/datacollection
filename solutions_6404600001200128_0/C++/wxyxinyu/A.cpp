#include <bits/stdc++.h>
using namespace std;
int TC,N,A[1010];
int main(){
	scanf("%d\n",&TC);
	for (int tc=1; tc<=TC; tc++){
		scanf("%d",&N);
		int rate=0,X=0,Y=0;
		for (int i=0; i<N; i++){
			scanf("%d",&A[i]);
			if (i && A[i]<A[i-1]){
				X+=A[i-1]-A[i];
				rate = max(rate,A[i-1]-A[i]);
			}
		}
		for (int i=1; i<N; i++){
			Y+=min(A[i-1],rate);
		}
		printf("Case #%d: %d %d\n",tc,X,Y);
	}
}
