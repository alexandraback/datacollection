#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;
int p[30],n;
int getm(int &t1, int &t2)
{
	int i1=-1,i2=-1;

	int cnt=0,tmp=0;
	for(int i=0;i<n;i++)
		if(p[i]>0){
		   	cnt++;
			tmp=p[i];
		}
	if(cnt==0) return 0;
	if(cnt==1) {t1=tmp;return 1;}
	for(int i=0;i<n;i++)
	{
		if(p[i]>i1)
		{
			t2=t1;
			i2=i1;

			i1=p[i];
			t1=i;
		}
		else if(p[i]>i2)
		{
			i2=p[i];
			t2=i;
		}
	}
	return 2;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++)
	{
		int sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
			sum+=p[i];
		}
		printf("Case #%d:",cases);
		if(sum&1) {
			int t1,t2;
			getm(t1,t2);
			printf(" %c",t1+'A');
			p[t1]--;
		}
		while(true)
		{
			int t1,t2;
			int ret=getm(t1,t2);
			if(ret==0) break;
			/*if(ret==1) {
				printf(" %c",t1+'A');
				p[t1]--;
				break;
			}*/
			printf(" %c%c",t1+'A',t2+'A');
			p[t1]--,p[t2]--;

			sum-=ret;
			double r=(double)p[t1]/sum;
			if(sum)
				assert(r<=0.5);
		}
		puts("");
	}
	return 0;
}
