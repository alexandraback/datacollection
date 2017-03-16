#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int ar[1004];
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&ar[i]);
		int a1=0,a2=0;
		for(int i=1;i<n;i++)
		{
			if(ar[i]<(ar[i-1])) a1+=(ar[i-1]-ar[i]);
			
		}
		
		int max=0;
			for(int i=1;i<n;i++)
		{
			int d=ar[i-1]-ar[i];
			if(d>max) max=d;
		}
		for(int i=0;i<n-1;i++)
		{
			
			if(ar[i]<max) a2+=ar[i]; else a2+=max;
		}
		printf("%d %d\n",a1,a2);
	}
}
