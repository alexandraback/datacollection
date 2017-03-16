#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef double db;
int n,k;
int a[1111];

int main()
{
	freopen("bs.in","r",stdin);
	freopen("bs.out","w",stdout);
	int tes;scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		ll l=0,r=ll(1e18);
		while(l<=r){
			ll mid=l+r>>1;
			ll su=0;
			if(mid>=0){
				for (int i=1;i<=n;i++)su+=mid/a[i]+1;
			}
			if(k<=su)r=mid-1;
			else l=mid+1;
		}
		ll su=0;
		if(l>0)for (int i=1;i<=n;i++)su+=(l-1)/a[i]+1;
		ll lef=k-su;
		int ans;
		for (int i=1;i<=n;i++){
			if(l%a[i]==0){
				lef--;
				if(lef==0){
					ans=i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}



		



