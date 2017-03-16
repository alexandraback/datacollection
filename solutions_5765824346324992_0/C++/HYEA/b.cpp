#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
void tmain()
{
	int B;
	long long N;
	long long M[1010];
	scanf("%d%lld",&B,&N);
	if(N==1)
	{
		puts("0");
		return;
	}
	for(int i=0;i<B;i++) scanf("%lld",M+i);
	long long lo=-1LL;
	long long hi=500000000000000LL;
	while(lo+1!=hi)
	{
		int modzero=-1;
		long long sumcount=0;
		long long mi=(lo+hi)/2;
		for(int i=0;i<B;i++)
		{
			if(mi%M[i]==0 && modzero == -1 ) modzero = i;
			//if(mi%M[i]==0) sumcount++;
			sumcount+=mi/M[i]+1;
		}
		if(sumcount>=N) hi=mi;
		else lo=mi;
	}
	//think about only hi
	//printf("%lld ",hi);
	for(int i=0;i<B;i++)
		N-=(hi-1)/M[i]+1;
	for(int i=0;i<B;i++)
	{
		if(hi%M[i]==0) N--;
		if(N==0)
		{
			printf("%d\n",i+1);
			return;
		}
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		tmain();
	}
	return 0;
}