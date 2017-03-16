#include <stdio.h>
#include <algorithm>

char s[110][110];

int main()
{
	int tc=0,n,i,t;
	char * q[110];
	int p[110];
	char x;
	scanf("%d",&n);
	while (scanf("%d",&n)==1)
	{
		int ok=1;
		t=0;
		for (i=0;i<n;++i) { scanf("%s",s[i]); q[i]=s[i]; }
		while (q[0][0])
		{
			x=q[0][0];
			for (i=0;i<n;++i)
			{
				p[i]=0;
				while (q[i][0]==x) { ++p[i]; ++q[i]; }
			}
			std::sort(p,p+n);
			if (p[0]==0) { ok=0; break; }
			for (i=0;i<n/2;++i) t+=p[n/2]-p[i];
			for (;i<n;++i) t+=p[i]-p[n/2];
		}
		for (i=0;i<n;++i) if (q[i][0]) ok=0;
		if (ok)
		{
			printf("Case #%d: %d\n",++tc,t);
		} else
		{
			printf("Case #%d: Fegla Won\n",++tc);
		}
	}
	return 0;
}
