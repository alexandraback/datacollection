#include<stdio.h>
int arr[1010], T, n;
int main()
{
	int i, j, tt, m, cnt, p, s;
	scanf("%d", &T);
	for(tt=1; tt<=T; ++tt)
	{
		scanf("%d", &n); cnt=s=m=0;
		for(i=1; i<=n; ++i){ scanf("%d", &arr[i]); s+=arr[i]; }
		printf("Case #%d: ", tt);
		while(s>0)
		{
			m=cnt=0;
			for(i=1; i<=n; ++i)
			{
				if(m<arr[i]) m=arr[i];
			}
			for(i=1; i<=n; ++i)
			{
				if(arr[i]==m)
				{
					++cnt;
					p=i;
				}
			}
			if(cnt==1)
			{
				printf("%c ", 'A'+p-1);
				--arr[p]; --s;
			}
			else if(cnt==2)
			{
				for(i=1; i<=n; ++i)
				{
					if(arr[i]==arr[p] && i!=p) m=i;
				}
				printf("%c%c ", 'A'+m-1, 'A'+p-1);
				--arr[m];
				--arr[p]; s-=2;
			}
			else
			{
				printf("%c ", 'A'+p-1);
				--arr[p]; --s;
			}
		}
		printf("\n");
	}
}