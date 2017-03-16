#include<bits/stdc++.h>
#define ll long long
#define N 1000000007
#define maxs 100005
#define mins 1005
#define pb push_back
using namespace std;

ll power(ll a,ll b)
{
	ll t=1;
	while(b>0){
		if(b&1){
			t=(t*a);
		}
		a=a*a;
		b>>=1;
	}
	return t;
}

int mark[100][100];


int main()
{
	ll t,cnt=1,i,j,k,r,c,val,ans,n,s,p,temp,c1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld",&r,&c,&n);
		s=r*c;
		c1=c;
		ans=INT_MAX;
		for(i=0;i<(1<<s);i++){
				p=0;
				temp=i;
				c=0;
				while(temp>0){
					if(temp&1){
						c++;
					}
					temp>>=1;
				}
				temp=i;
				if(c==n){
					for(j=0;j<r;j++){
						for(k=0;k<c1;k++){
							mark[j][k]=0;
							}
						}
					for(j=0;j<r;j++){
						for(k=0;k<c1;k++){
							val=j*c1+k;
							if(((1<<val)&temp)!=0){
								mark[j][k]=1;
							}
						}
					}
					c=0;
					for(k=0;k<r;k++){
						for(p=0;p<c1;p++){
							if(mark[k][p]==0){
								continue;
							}
							if(k-1>=0 && mark[k-1][p]==1){
								c++;
							}
							if(p-1>=0 && mark[k][p-1]==1){
								c++;
							}
						}
					}
					if(c<ans){
						ans=c;
					}
				}
			}
		printf("Case #%lld: %lld\n",cnt,ans);
		cnt++;
	}
	return 0;
}
