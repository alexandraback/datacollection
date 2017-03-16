#include <stdio.h>

using namespace std;


int main()
{
	long long tc,t,r=0;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		int x[4][4],y[4][4],i,j,k,a,b;
		scanf("%d",&a);
		for (i=0;i<4;++i) for (j=0;j<4;++j) scanf("%d",x[i]+j);
		scanf("%d",&b);
		for (i=0;i<4;++i) for (j=0;j<4;++j) scanf("%d",y[i]+j);
		k=0;
		for (i=0;i<4;++i) for (j=0;j<4;++j) if (x[a-1][i]==y[b-1][j]) k=k?17:x[a-1][i];
		if (k==0)
		{
			printf("Case #%lld: Volunteer cheated!\n",tc+1,r);
		} else if (k==17)
		{
			printf("Case #%lld: Bad magician!\n",tc+1,r);
		} else
		{
			printf("Case #%lld: %d\n",tc+1,k);
		}
	}
	return 0;
}
