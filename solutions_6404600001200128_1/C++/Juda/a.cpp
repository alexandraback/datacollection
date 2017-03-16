#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
int a[1005],n;

void init() {
	int i;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
}

int work1() {
	int i,res=0;
	FOR(i,2,n) {
		if(a[i]<a[i-1])
			res+=a[i-1]-a[i];
	}
	return res;
}

int work2() {
	int i,k,res,ans=1000000000,ls=0;
	FOR(i,2,n)ls=max(a[i-1]-a[i],ls);
	FOR(k,ls,10000){
		res=0;
		FOR(i,2,n) {
			res+=min(a[i-1],k);
		}
		ans=min(ans,res);
	}
	return ans;
}

int main() {
	int i,T;
	scanf("%d",&T);
	FOR(i,1,T) {
		init();
		printf("Case #%d: %d %d\n", i, work1(),work2());
	}
}