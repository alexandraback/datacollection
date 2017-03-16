#include <stdio.h>
#include <string.h>
using namespace std;
int a[1010];
int gcd(int x,int y)
{
	if (x%y==0) return y;
	return gcd(y,x%y);
}
int main(int argc, char const *argv[])
{
	int t,n,b;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		scanf("%d%d",&b,&n);
		for (int i=0;i<b;i++) scanf("%d",&a[i]);
		int d=a[0];
		for (int i=1;i<b;i++) d=gcd(d,a[i]);
		int k=a[0];
		for (int i=1;i<b;i++) k=k*a[i]/d;
		int p=0;
		for (int i=0;i<b;i++) p=p+k/a[i];
		n=n%p;
		//printf("%d %d\n", k,n);
		int i=0,f=1;
		if (n==0) 
			{
				int MAX=999999,pp;
				for (int i=0;i<b;i++) if (a[i]<=MAX)
				{
					MAX=a[i];
					pp=i;
				}
				printf("Case #%d: %d\n", TT,pp+1);
				continue;
			}
		while (1)
		{
			if (i%d==0)
			{
				for (int j=0;j<b;j++) if (i%a[j]==0)
				{
					n--;
					if (n==0)
					{
						printf("Case #%d: %d\n",TT,j+1 );
						f=0;
						break;
					}
				}
			}
			if (f==0) break;
			i++;
		}
	}
	return 0;
}