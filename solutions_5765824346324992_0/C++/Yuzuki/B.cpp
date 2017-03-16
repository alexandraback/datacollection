#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define LL long long
#define Maxn 1050
LL n;int b;
LL a[Maxn],t[Maxn];
LL judge(LL mid){
	LL ret=0;
	for (int i=1;i<=b;i++){
		if (mid%a[i]==0) ret+=mid/a[i];
		else ret+=mid/a[i]+1;
	}
	return ret;
}
LL binarySearch(LL l,LL r){
	while (l<r){
		LL mid=(l+r+1)>>1;
		if (judge(mid)>=n) r=mid-1;
		else l=mid;
	}
	return l;
}

int main(){
	int cases;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		scanf("%d%lld",&b,&n);
		LL Max=0;
		for (int i=1;i<=b;i++){
			scanf("%lld",&a[i]);
			Max=max(Max,a[i]);
		}
		LL k=binarySearch(0,Max*n);
		LL cnt=n-judge(k);
		//cout<<k<<endl;cout<<judge(k)<<endl;
		LL sum=0;
		for (int i=1;i<=b;i++){
			t[i]=a[i]-((k-1)%a[i]+1);
		}
		//for (int i=1;i<=b;i++) cout<<t[i]<<' ';cout<<endl;
		int ans=1;
		for (int j=1;j<=cnt;j++){
			ans=1;
			for (int i=1;i<=b;i++){
				if (t[ans]>t[i]) ans=i;
			}
			LL tmp=t[ans];
			t[ans]=a[ans];
			if (tmp==0) continue;
			for (int i=1;i<=b;i++)
				if (ans!=i) t[i]-=tmp;
		}
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}