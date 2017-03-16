#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t=1; t<=T; t++){
		int R,C,N;
		cin>>R>>C>>N;
		int ans = 0, dans = 0;
		if(R == 1 || C == 1){
			if(R*C&1){
				ans += 2*max(0, N-(R*C+1)/2);
			}
			else{
				ans += 1*max(0, min(1, N-(R*C+1)/2));
				ans += 2*max(0, N-1-(R*C+1)/2);
			}
		}
		else if((R*C)&1){
			ans += 3*max(0, min(R + C - 2, N - (R*C+1)/2));
			ans += 4*max(0, N - R - C + 2  - (R*C+1)/2);
			dans += 2*max(0, min(4, N - (R*C)/2));
			dans += 3*max(0, min(R + C - 2 - 4, N - 4 - (R*C)/2));
			dans += 4*max(0, N - R - C + 2 + 4 - 4 - (R*C)/2);
			ans = min(ans, dans);
		}
		else{
			ans += 2*max(0, min(2, N - (R*C+1)/2));
			ans += 3*max(0, min(R + C - 2 - 2 , N - 2 - (R*C+1)/2));
			ans += 4*max(0, N - R - C + 2 + 2 - 2 - (R*C+1)/2);
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
