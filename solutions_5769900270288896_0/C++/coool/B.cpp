#include <bits/stdc++.h>
using namespace std;
#define max 1<<18
int dp[max];
int R,C,N,t,x;
 
int func(int x)
{
	int i,j,ans=0;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(j and(x&(1<<(i*C+j)))and(x&(1<<(i*C+j-1)))) {
				ans++;
			}
			if(i and(x&(1<<(i*C+j)))and(x&(1<<(i*C+j-C)))) {
				ans++;
			}
		}
	}
	return ans;
}
 
int main() 
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output2.txt","w",stdout);
    int i,j;
	cin>>t; 
	for(j = 1; j <= t; j++) {
		cin>>R>>C>>N;
		x = R*C*N*100;
		for(i = 1; i < (1<<(R*C)); i++) {
			dp[i] = dp[i - (i & -i)] + 1;
			if (dp[i] == N) {
			    x = min(x,func(i));
			}
		}
		printf("Case #%d: %d\n",j,x);
	}
}
