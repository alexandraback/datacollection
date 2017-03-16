#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define N 1005
int n,m,b[N];

void init() {
	int i;
	scanf("%d%d",&n,&m);
	FOR(i,1,n)
		scanf("%d",&b[i]);
}

long long get(long long x) {
	int i;
	long long res=0;
	FOR(i,1,n) {
		res+=(x+b[i]-1)/b[i];
	}
	return res;
}

int work() {
	long long l=1,r=100000000000000LL,mid,temp;
	int i;
	while(l<r) {
		mid=(l+r)/2;
		temp=get(mid);
		if(temp<m)l=mid+1;else r=mid;
	}
	temp=m-get(l-1);
	FOR(i,1,n) {
		if((l-1)%b[i]==0){
			temp--;
			if(temp==0)return i;
		}
	}
}

int main() {
	int i,T;
	scanf("%d",&T);
	FOR(i,1,T) {
		init();
		printf("Case #%d: %d\n", i,work());
	}
}