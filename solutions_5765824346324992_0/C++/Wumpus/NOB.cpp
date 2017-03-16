#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const int maxn=100000+10;
const LL INF=0x3f3f3f3f3f3f3f3fLL;
int n,b;
LL m[maxn];

LL cal(LL t){
	LL res=0;
	for(int i=0;i<b;++i) res+=(t/m[i])+(t%m[i]!=0);
	return res;
}

LL solve()
{
	LL l=0,r=INF;
	while(l<=r){
		LL mid=(l+r)/2;
		if(cal(mid)<n) l=mid+1;
		else r=mid-1;
	}
//	printf("*** %d\n",r);
	while(cal(r) == n)
        r--;
	LL t=cal(r),cnt=t,ans=0;
	for(int i=0;i<b;++i){
		if(r%m[i]==0){
			++cnt;
			if(cnt==n){
				ans=i;
				break;
			}
		}
	}
	return ans+1;
}


int main()
{
  //  freopen("./test.txt","r",stdin);
	freopen("./B-small-attempt2.in","r",stdin);
    freopen("./b.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&b,&n);
		for(int i=0;i<b;++i) scanf("%lld",m+i);
		printf("Case #%d: %lld\n",++kase,solve());
	}
	return 0;
}
