#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define Maxn 1050
int n;
int a[Maxn];
int judge(int mid){
	int ret=0;
	for (int i=1;i<n;i++){
		if (a[i]-mid>a[i+1]) return -1;
		ret+=min(a[i],mid);
	}
	return ret;
}
int binarySearch(int l,int r){
	while (l<r){
		int mid=(l+r)>>1;
		if (judge(mid)!=-1) r=mid;
		else l=mid+1;
	}
	//cout<<l<<' '<<r<<endl;
	//cout<<judge(9)<<endl;
	return judge(l);
}
int main(){
	int cases;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ans1=0;
		for (int i=1;i<n;i++){
			if (a[i]>a[i+1]) ans1+=a[i]-a[i+1];
		}
		int ans2=binarySearch(0,100000);
		printf("Case #%d: %d %d\n",cas,ans1,ans2);
	}
	return 0;
}