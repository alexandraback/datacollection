#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxN (1005)
using namespace std;

typedef long long LL;
int N,M;
int A[maxN];

LL get_value(LL x){
	LL ans=0;
	if (x==0) return 0;
	for (int i=0;i<N;i++){
		ans+=(x-1)/A[i]+1;
	}
	return ans;
}
int main(){
	freopen("i.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int testcase=1;T--;testcase++){
		printf("Case #%d: ",testcase);
		scanf("%d%d",&N,&M);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		LL left=0,right=100000000000005L;
		for (;left+1<right;){
			LL mid=(left+right)/2;
			LL f=get_value(mid);
			if (f<M) 
				left=mid;
			else
				right=mid;
		}
		//cout<<left<<endl;
		LL now=get_value(left);
		for (int i=0;i<N;i++){
			if (left%A[i]==0){
				now++;
				if (now==M){
					printf("%d\n",i+1);
					break;
				}
			}
		}
		if (now!=M){
			puts("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		}
	}
	return 0;
}
