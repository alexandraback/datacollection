#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;	
int n,b;
long long m[2000];
void work()
{
	scanf("%d%d",&b,&n);
	for(int i = 0; i < b; i++)
		scanf("%lld",&m[i]);
	long long s  = 0, t = 100000LL*1000000000LL;
	//long long s =0, t = 10000;
	while (s < t){
		//printf("%lld\n",t);
		long long mid = (s+t)/2;
		long long tot = 0;
		for(int i = 0; i < b;i++)tot += mid/m[i]+1;
		if(tot >=n)
			t= mid;
		else 
			s = mid +1;
	}
	//printf("%lld\n",t);
	long long tot = 0;
	int tmp = 0;
	for (int i= 0; i < b; i++)tot += s/m[i]+1;
	for (int i = 0; i < b; i++)if(s %m[i] == 0)tmp++;
	tot -=tmp;
	int x =0;
	for(int i = 0; i <b; i++)
		if(s%m[i]==0){
			x++;
			if(tot + x==n){
				printf("%d\n",i+1);
				return;
			}
		}
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i = 1; i <=T; i++){
		printf("Case #%d: ", i);
		work();		
	}
	return 0;
}