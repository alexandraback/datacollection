#include <iostream>
#include <fstream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <map>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define GCD(a,b)  { return (b==0)?a:GCD(b,a%b); }
#define LCM(a,b)  { return a*b/GCD(a,b);  }
#define FOR(i,n) for(i=0;i<n;i++)
#define FOR_X(i,n,x) for(i=x;i<n;i++)
#define FORN(i,n) for(i=n;i>=0;i--)
#define FORN_X(i,n,x) for(i=n;i>=x;i--)

typedef long long int lld;
using namespace std;

int t,r,c,n;
int a[17][17];

int dp[1<<17];

long long int rec(int mask){

	int i,j,k,minn=INT_MAX,x;

	if(dp[mask]!=-1)
		return dp[mask];

	if(__builtin_popcount(mask)==n)
	{
		//cout<<endl;
		memset(a,0,sizeof a);

		i = 0 ; j = 0;

		for(int k=0;k<=r*c;k++){
			if((mask&(1<<k))!=0){
				a[i][j]=1;
			}
			j++;
			if(j==c)
				{
					j=0;
					i++;
				}
		}

		int countx=0;

		for(i=0;i<r;i++){
			//cout<<endl;
			for(j=0;j<c;j++){
			//	cout<<a[i][j]<<" ";
				if(a[i][j]==0)
					continue;

				if(i+1<r){
					if(a[i+1][j]==1)
						countx++;
				}
				if(i-1>=0)
					{
						if(a[i-1][j]==1)
							countx++;
					}
				if(j-1>=0){
					if(a[i][j-1]==1)
						countx++;
				}
				if(j+1<c){
					if(a[i][j+1]==1)
						countx++;
				}


			}
		}
		//cout<<"\n count = "<<countx/2;
		return countx/2;
	}

	for(i=0;i<r*c;i++){
		if((mask&(1<<i))==0){
			x = rec((mask|(1<<i)));
			minn = MIN(x,minn);
		}
	}
	dp[mask]=minn;
	return minn;

}
int main(){
	cin>>t;
	long long int x;
	x = 0;
	while(t--){
		x++;
		cin>>r>>c>>n;
		memset(dp,-1,sizeof dp);
		printf("Case #%lld: %lld\n",x,rec(0));
	}
	return 0;
}

