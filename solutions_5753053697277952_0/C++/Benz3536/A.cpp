#include<bits/stdc++.h>
using namespace std;
int m[100];
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.txt","w",stdout);
	int a,b,c,d,T,N,check,sum;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	for(d=0;d<T;d++)
	{
		scanf("%d",&N);
		sum=0;
		for(a=0;a<N;a++)
		{
			scanf("%d",&m[a]);
			sum+=m[a];
		}
		printf("Case #%d: ",d+1);
		if(sum%2==1)
		{
			for(a=0;a<N;a++)
			{
				if(m[a])
				{
					m[a]--;
					check=1;
					for(b=0;b<N;b++)
					{
						if(m[b]*2>sum-1)check=0;
					}
					if(check)
					{
						printf("%c ",a+'A');
						sum--;
						break;
					}
					else 
					{
						m[a]++;
					}
				}
			}
		}
		while(sum)
		{
			//
			check=0;
			for(a=0;a<N;a++)
			{
				for(b=a;b<N;b++)
				{
					m[a]--;
					m[b]--;//printf("%d %d\n",m[a],m[b]);
					check=1;
					if(m[a]>-1&&m[b]>-1)
					{
						for(c=0;c<N;c++)
						{
							if(m[c]*2>sum-2)check=0;
						}
					}
					else check=0;
					if(check)
					{
						printf("%c%c ",a+'A',b+'A');
						sum-=2;
						break;
					}
					else
					{
						m[a]++;
						m[b]++;
					}
				}	
				if(check)break;
			}
		}
		printf("\n");
	}
}
